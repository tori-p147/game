/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:41:22 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/10 17:47:11 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "init.h"
#include "so_long.h"
#include "validator.h"

int	event_handler(int key, void *mlx)
{
	(void)key;
	(void)mlx;
	printf("called\n");
	return (0);
}

int	count_map_lines(const char *map_name)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		exit_error("error occurred when trying read map file", NULL);
	while ((line = get_next_line(fd)) != NULL)
	{
		validate_line_length(line);
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

void	alloc_map_array(const char *map_name, t_game *game)
{
	int	i;
	int	rows;

	rows = count_map_lines(map_name);
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		exit_error("game.map allocation fail", game);
	game->map->array = malloc(sizeof(char *) * (rows + 1));
	if (!game->map->array)
		exit_error("map.array[] memory allocation fail", game);
	i = 0;
	while (i < game->map->cols - 1)
	{
		game->map->array[i] = malloc(sizeof(char *) * (game->map->cols + 1));
		if (!game->map->array[i])
			exit_error("map.array[][] memory allocation fail", game);
	}
	game->map->rows = rows;
	game->map->cols = 0;
}

void	parse_map_objects(t_game *game)
{
	int		i;
	int		j;
	char	**map_array;

	i = 0;
	while (i < game->map->rows)
	{
		j = 0;
		map_array = game->map->array;
		validate_wall(map_array[i][0], game);
		validate_wall(map_array[i][game->map->cols - 1], game);
		while (j < game->map->cols)
		{
			validate_wall(map_array[0][j], game);
			validate_wall(map_array[game->map->rows - 1][j], game);
			if (map_array[i][j] == 'P')
				game->map->player_count++;
			else if (map_array[i][j] == 'C')
				game->map->collect_count++;
			else if (map_array[i][j] == 'E')
				game->map->exit_count++;
			j++;
		}
		i++;
	}
	validate_objects_count(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		perror("args error");
		exit(EXIT_FAILURE);
	}
	init_map(argv[1], &game);
	parse_map_objects(&game);
	init_window(&game);
	mlx_loop(game.mlx_display_ptr);
	return (0);
}
