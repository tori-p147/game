/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:37:20 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/15 16:31:17 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_space(t_game *game)
{
	int	img_width;
	int	img_height;

	game->space_img = mlx_xpm_file_to_image(game->mlx_display_ptr,
			"textures/space.xpm", &img_width, &img_height);
}

void	init_player(t_game *game)
{
	int	img_width;
	int	img_height;

	game->player_img = mlx_xpm_file_to_image(game->mlx_display_ptr,
			"textures/usagi.xpm", &img_width, &img_height);
}
void	init_wall(t_game *game)
{
	int	img_width;
	int	img_height;

	game->wall_img = mlx_xpm_file_to_image(game->mlx_display_ptr,
			"textures/wall.xpm", &img_width, &img_height);
}

void	init_item(t_game *game)
{
	int	img_width;
	int	img_height;

	game->item_img = mlx_xpm_file_to_image(game->mlx_display_ptr,
			"textures/carrot.xpm", &img_width, &img_height);
}

void	init_exit(t_game *game)
{
	int	img_width;
	int	img_height;

	game->exit_img = mlx_xpm_file_to_image(game->mlx_display_ptr,
			"textures/exit.xpm", &img_width, &img_height);
}

void	init_window(t_game *game)
{
	int	tile_size;

	game->tile_size = 48;
	tile_size = game->tile_size;
	game->win_width = game->map->cols * tile_size;
	game->win_height = game->map->rows * tile_size;
	game->mlx_display_ptr = mlx_init();
	game->user_win_ptr = mlx_new_window(game->mlx_display_ptr, game->win_width,
			game->win_height, "so_long");
	init_space(game);
	init_player(game);
	init_wall(game);
	init_item(game);
	init_exit(game);
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
}
