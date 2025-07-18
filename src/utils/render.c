/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 22:10:02 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/18 18:43:31 by vmatsuda         ###   ########.fr       */
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
	mlx_put_image_to_window(game->mlx_display_ptr, game->user_win_ptr,
		target_img, screen_x, screen_y);
}

void	render_map(t_game *game)
{
	char	tile;
	int		x;
	int		y;

	y = 0;
	while (y < game->map->rows)
	{
		x = 0;
		while (x < game->map->cols)
		{
			tile = game->map->array[y][x];
			printf("%c\n", tile);
			render_img(game, x * game->tile_size, y * game->tile_size,
				game->sprites[get_img_index(tile)].img_ptr);
			if (tile == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			x++;
		}
		y++;
	}
}
