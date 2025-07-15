/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 22:10:02 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/15 16:15:15 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_img(t_game *game, int screen_x, int screen_y, void *terget_img)
{
	mlx_put_image_to_window(game->mlx_display_ptr, game->user_win_ptr,
		terget_img, screen_x, screen_y);
}

void	render_map(t_game *game)
{
	char	tile;
	int		x;
	int		y;
	int		screen_x;
	int		screen_y;

	y = 0;
	while (y < game->map->rows)
	{
		x = 0;
		while (x < game->map->cols)
		{
			tile = game->map->array[y][x];
			screen_x = x * game->tile_size;
			screen_y = y * game->tile_size;
			if (tile == '1')
				render_img(game, screen_x, screen_y, game->wall_img);
			if (tile == 'P')
			{
				render_img(game, screen_x, screen_y, game->player_img);
				game->player_x = x;
				game->player_y = y;
			}
			else if (tile == 'C')
				render_img(game, screen_x, screen_y, game->item_img);
			else if (tile == 'E')
				render_img(game, screen_x, screen_y, game->exit_img);
			else if (tile == '0')
				render_img(game, screen_x, screen_y, game->space_img);
			x++;
		}
		y++;
	}
}
