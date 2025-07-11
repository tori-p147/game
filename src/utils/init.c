/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:37:20 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/11 18:52:18 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_game *game)
{
	size_t	win_width;
	size_t	win_height;
	size_t	tile_size;

	tile_size = 64;
	win_width = game->map->cols * tile_size;
	win_height = game->map->rows * tile_size;
	game->mlx_display_ptr = mlx_init();
	game->user_win_ptr = mlx_new_window(game->mlx_display_ptr, win_width,
			win_height, "so_long");
}

void	init_map(const char *map_name, t_game *game)
{
	int		fd;
	size_t	i;
	char	*line;

	alloc_map_arrays(map_name, game);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		exit_error("error occurred when trying read map file", game);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		game->map->array[i] = line;
		printf("%s", game->map->array[i]);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	game->map->array[i] = NULL;
	close(fd);
	game->map->player_count = 0;
	game->map->exit_count = 0;
	game->map->collect_count = 0;
}
