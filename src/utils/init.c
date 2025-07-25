/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:37:20 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/25 21:15:05 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_imgs_ptrs(t_game *game, char *imgs_paths[])
{
	int	i;

	i = 0;
	while (i < IMG_COUNT)
	{
		game->sprites[i].img_ptr = mlx_xpm_file_to_image(game->mlx_display_ptr,
				imgs_paths[i], &game->sprites[i].width,
				&game->sprites[i].height);
		if (!game->sprites[i].img_ptr)
		{
			free_images_ptrs(game, i - 1);
			exit_error("Error load image", game);
		}
		i++;
	}
}

void	init_imgs(t_game *game)
{
	int		i;
	char	*imgs_paths[IMG_COUNT];

	imgs_paths[0] = "textures/wall.xpm";
	imgs_paths[1] = "textures/usagi.xpm";
	imgs_paths[2] = "textures/carrot.xpm";
	imgs_paths[3] = "textures/exit.xpm";
	imgs_paths[4] = "textures/space.xpm";
	i = 0;
	while (i < IMG_COUNT)
	{
		game->sprites[i].img_ptr = NULL;
		game->sprites[i].width = 0;
		game->sprites[i].height = 0;
		i++;
	}
	init_imgs_ptrs(game, imgs_paths);
	game->images_initialized = 1;
}

void	init_window(t_game *game)
{
	int	tile_size;

	game->tile_size = 48;
	tile_size = game->tile_size;
	game->steps_count = 0;
	game->win_width = game->map->cols * tile_size;
	game->win_height = game->map->rows * tile_size;
	game->mlx_display_ptr = mlx_init();
	game->user_win_ptr = mlx_new_window(game->mlx_display_ptr, game->win_width,
			game->win_height, "so_long");
	init_imgs(game);
}

void	init_map(const char *map_name, t_game *game)
{
	int		fd;
	size_t	i;
	char	*line;

	game->map_initialized = 0;
	game->images_initialized = 0;
	alloc_map_arrays(map_name, game);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		exit_error("error occurred when trying read map file", game);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_strlcpy(game->map->array[i], line, game->map->cols + 1);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	game->map->player_count = 0;
	game->map->exit_count = 0;
	game->map->remain_items_count = 0;
}

void	init_q(t_tile *data, t_queue *q, t_game *game)
{
	q->capacity = game->map->rows * game->map->cols;
	q->data = data;
	q->head = 0;
	q->tail = 0;
}
