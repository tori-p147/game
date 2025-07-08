/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:41:22 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/08 22:48:25 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"
#include "validator.h"

int	event_handler(int key, void *mlx)
{
	(void)key;
	(void)mlx;
	printf("called\n");
	return (0);
}

void	init_window(t_game *game)
{
	int	win_width;
	int	win_height;
	int	tile_size;

	tile_size = 64;
	win_width = game->map->cols * tile_size;
	win_height = game->map->rows * tile_size;
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, win_width, win_height,
			"so_long");
}

int	count_map_lines(const char *map_name)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		exit_error("error when open file", NULL);
	while ((line = get_next_line(fd)) != NULL)
	{
		if (!validate_line_length(line))
			exit_error("map row length is not same", NULL);
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

void	parse_map(const char *map_name, t_game *game)
{
	int		fd;
	char	*line;
	int		row;
	int		rows;

	row = 0;
	rows = count_map_lines(map_name);
	game->map = malloc(sizeof(t_map *));
	if (!game->map)
		exit_error("map memory allocation fail", game);
	game->map->array = malloc(sizeof(char *) * (rows + 1));
	if (!game->map->array)
		exit_error("map arrays memory allocation fail", game);
	game->map->rows = rows;
	game->map->cols = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		exit_error("error occurred when open map", game);
	while ((line = get_next_line(fd)) != NULL)
	{
		game->map->array[row] = line;
		if (row == 0)
			game->map->cols = ft_strlen(line) - (line[ft_strlen(line)
					- 1] == '\n');
		row++;
	}
	game->map->array[row] = NULL;
	close(fd);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		perror("args error");
		exit(EXIT_FAILURE);
	}
	parse_map(argv[1], &game);
	validate_map_objects(&game);
	init_window(&game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
