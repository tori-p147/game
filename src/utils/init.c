/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:37:20 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/18 22:22:08 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*init_img(t_game *game, char *img_path, int *w, int *h)
{
	return (mlx_xpm_file_to_image(game->mlx_display_ptr, img_path, w, h));
}

void	init_window(t_game *game)
{
	int		i;
	int		tile_size;
	char	*imgs_path[IMG_COUNT] = {"textures/wall.xpm", "textures/usagi.xpm",
			"textures/carrot.xpm", "textures/exit.xpm", "textures/space.xpm"};

	game->tile_size = 48;
	tile_size = game->tile_size;
	game->steps_count = 0;
	game->win_width = game->map->cols * tile_size;
	game->win_height = game->map->rows * tile_size;
	game->mlx_display_ptr = mlx_init();
	game->user_win_ptr = mlx_new_window(game->mlx_display_ptr, game->win_width,
			game->win_height, "so_long");
	i = IMG_COUNT;
	while (--i >= 0)
	{
		game->sprites[i].img_ptr = init_img(game, imgs_path[i],
				&game->sprites[i].width, &game->sprites[i].height);
	}
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
		game->map->array[i] = ft_strdup(line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	game->map->player_count = 0;
	game->map->exit_count = 0;
	game->map->remain_items_count = 0;
	game->map->collected_items_count = 0;
}
