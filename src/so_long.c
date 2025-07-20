/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:41:22 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/19 19:08:51 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_error(const char *msg, t_game *game)
{
	free_map(game->map);
	free_game(game);
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

void	count_map_lines(const char *map_name, t_game *game)
{
	int		fd;
	char	*line;
	size_t	rows_count;
	size_t	cols_count;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		exit_error("error occurred when trying read map file", game);
	line = get_next_line(fd);
	rows_count = 0;
	while (line != NULL)
	{
		cols_count = validate_rows_length(line);
		rows_count++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
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
	game->map->array = malloc(sizeof(char *) * (game->map->rows));
	if (!game->map->array)
		exit_error("map.array memory allocation fail", game);
	i = 0;
	while (i < game->map->rows)
	{
		game->map->array[i] = malloc(sizeof(char) * (game->map->cols + 1));
		if (!game->map->array[i])
		{
			while (--i >= 0)
				free(game->map->array[i]);
			exit_error("map.array[i] memory allocation fail", game);
		}
		i++;
	}
}

void	parse_map_objects(t_game *game)
{
	int		y;
	int		x;
	char	tile;

	y = 0;
	while (y < game->map->rows)
	{
		x = 0;
		while (x < game->map->cols)
		{
			tile = game->map->array[y][x];
			validate_tile(game, tile, y, x);
			x++;
		}
		y++;
	}
	validate_objects_count(game);
	if (!is_has_exit(game))
		exit_error("Error: map has not exit", game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("args error");
		return (-1);
	}
	init_map(argv[1], &game);
	parse_map_objects(&game);
	init_window(&game);
	render_map(&game);
	mlx_hook(game.user_win_ptr, KeyPress, KeyPressMask, &key_press, &game);
	mlx_hook(game.user_win_ptr, DestroyNotify, NoEventMask, &free_game, &game);
	mlx_loop(game.mlx_display_ptr);
	return (0);
}
