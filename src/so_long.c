/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:41:22 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/13 20:24:12 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

void	count_map_lines(const char *map_name, t_game *game)
{
	int		fd;
	char	*line;
	size_t	rows_count;
	size_t	cols_count;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		exit_error("error occurred when trying read map file", NULL);
	line = get_next_line(fd);
	rows_count = 0;
	while (line != NULL)
	{
		cols_count = validate_rows_length(line);
		rows_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		exit_error("game.map allocation fail", game);
	game->map->rows = rows_count;
	game->map->cols = cols_count;
}

void	alloc_map_arrays(const char *map_name, t_game *game)
{
	int	i;

	count_map_lines(map_name, game);
	game->map->array = malloc(sizeof(char *) * (game->map->rows + 1));
	if (!game->map->array)
		exit_error("map.array[] memory allocation fail", game);
	i = 0;
	while (i < game->map->cols - 1)
	{
		game->map->array[i] = malloc(sizeof(char) * (game->map->cols + 1));
		if (!game->map->array[i])
			exit_error("map.array[][] memory allocation fail", game);
		i++;
	}
	game->map->array[i] = NULL;
}

void	parse_map_objects(t_game *game)
{
	int		x;
	int		y;
	char	tile;

	y = 0;
	while (y < game->map->rows)
	{
		x = 0;
		if (y == 0 || y == game->map->rows - 1)
			validate_wall(game->map->array[y][x], game);
		while (x < game->map->cols)
		{
			tile = game->map->array[y][x];
			if (x == 0 || x == game->map->cols - 1)
				validate_wall(tile, game);
			if (tile == 'P')
				game->map->player_count++;
			else if (tile == 'C')
				game->map->collect_count++;
			else if (tile == 'E')
				game->map->exit_count++;
			x++;
		}
		y++;
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
	render_map(&game);
	mlx_hook(game.user_win_ptr, KeyPress, KeyPressMask, &key_press, &game);
	mlx_loop(game.mlx_display_ptr);
	return (0);
}
