/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 22:10:02 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/20 23:04:05 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_img_index(char tile)
{
	if (tile == '1')
		return (IDX_WALL);
	else if (tile == 'P')
		return (IDX_PLAYER);
	else if (tile == 'C')
		return (IDX_ITEM);
	else if (tile == 'E')
		return (IDX_EXIT);
	else if (tile == '0')
		return (IDX_SPACE);
	return (-1);
}

void	render_img(t_game *game, int screen_x, int screen_y, void *target_img)
{
	if (!game || !game->mlx_display_ptr || !game->user_win_ptr || !target_img)
		return ;
	mlx_put_image_to_window(game->mlx_display_ptr, game->user_win_ptr,
		target_img, screen_x, screen_y);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;
	int	screen_y;
	int	screen_x;

	y = 0;
	while (y < game->map->rows)
	{
		x = 0;
		while (x < game->map->cols)
		{
			screen_x = x * game->tile_size;
			screen_y = y * game->tile_size;
			render_img(game, screen_x, screen_y,
				game->sprites[get_img_index(game->map->array[y][x])].img_ptr);
			if (game->map->array[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			x++;
		}
		y++;
	}
}
