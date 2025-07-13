/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:30:33 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/13 20:39:24 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int dx, int dy)
{
	char	target_tile;

	target_tile = game->map->array[dx][dy];
	if (target_tile != '1')
	{
		if (target_tile == 'C')
			game->map->collect_count--;
		game->player_x = dx;
		game->player_y = dy;
		render_map(game);
	}
}

int	key_press(int keycode, t_game *game)
{
	printf("%d", game->player_x);
	if (keycode == KEY_W)
		move_player(game, game->player_x - 1, game->player_y);
	else if (keycode == KEY_A)
	{
	}
	else if (keycode == KEY_S)
	{
	}
	else if (keycode == KEY_D)
	{
	}
	else if (keycode == KEY_ESC)
		mlx_destroy_window(game->mlx_display_ptr, game->user_win_ptr);
	return (0);
}
