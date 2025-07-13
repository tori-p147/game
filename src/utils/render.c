/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 22:10:02 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/13 20:22:34 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_space(t_game *game, int screen_x, int screen_y)
{
	mlx_put_image_to_window(game->mlx_display_ptr, game->user_win_ptr,
		game->space_img, screen_x, screen_y);
}

void	render_player(t_game *game, int screen_x, int screen_y)
{
	mlx_put_image_to_window(game->mlx_display_ptr, game->user_win_ptr,
		game->player_img, screen_x, screen_y);
}

void	render_wall(t_game *game, int screen_x, int screen_y)
{
	mlx_put_image_to_window(game->mlx_display_ptr, game->user_win_ptr,
		game->wall_img, screen_x, screen_y);
}

void	render_item(t_game *game, int screen_x, int screen_y)
{
	mlx_put_image_to_window(game->mlx_display_ptr, game->user_win_ptr,
		game->item_img, screen_x, screen_y);
}

void	render_exit(t_game *game, int screen_x, int screen_y)
{
	mlx_put_image_to_window(game->mlx_display_ptr, game->user_win_ptr,
		game->exit_img, screen_x, screen_y);
}

void	render_map(t_game *game)
{
	char	tile;
	int	x;
	int	y;
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
				render_wall(game, screen_x, screen_y);
			if (tile == 'P')
			{
				render_player(game, screen_x, screen_y);
				if (game->player_x == 0 && game->player_y == 0)
				{
					game->player_x = screen_x;
					game->player_y = screen_y;
				}
			}
			else if (tile == 'C')
			{
				game->map->collect_count++;
				if (x == game->player_x && y == game->player_y)
				{
					tile = '0';
					render_player(game, screen_x, screen_y);
				}
				else
					render_item(game, screen_x, screen_y);
			}
			else if (tile == 'E')
			{
				if (x == game->player_x && y == game->player_y)
				{
					if (game->map->collect_count == 0)
						render_player(game, screen_x, screen_y);
				}
				else
					render_exit(game, screen_x, screen_y);
			}
			else if (tile == '0')
				render_space(game, screen_x, screen_y);
			x++;
		}
		y++;
	}
}
