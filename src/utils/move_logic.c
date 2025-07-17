/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:30:33 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/17 18:01:36 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int new_y, int new_x)
{
	char	target_tile;

	// int	steps_count;
	// steps_count = 0;
	target_tile = game->map->array[new_y][new_x];
	if (target_tile != '1')
	{
		if (target_tile == 'E')
		{
			if (game->map->remain_items_count != 0)
			{
				printf("Check %d item(s) before exit",
					game->map->remain_items_count);
			}
			else
			{
				mlx_string_put(game->mlx_display_ptr, game->user_win_ptr, 10,
					10, 0xFFFFFF, "You win!");
				free_game(game);
			}
		}
		else
		{
			if (target_tile == 'C')
				game->map->remain_items_count--;
			game->map->array[game->player_y][game->player_x] = '0';
			game->map->array[new_y][new_x] = 'P';
			game->player_y = new_y;
			game->player_x = new_x;
		}
	}
	render_map(game);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		move_player(game, game->player_y - 1, game->player_x);
	else if (keycode == KEY_A)
		move_player(game, game->player_y, game->player_x - 1);
	else if (keycode == KEY_S)
		move_player(game, game->player_y + 1, game->player_x);
	else if (keycode == KEY_D)
		move_player(game, game->player_y, game->player_x + 1);
	else if (keycode == KEY_ESC)
		free_game(game);
	return (0);
}
