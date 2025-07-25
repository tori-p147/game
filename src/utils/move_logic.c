/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:30:33 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/25 21:54:00 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int new_y, int new_x)
{
	char	tile;

	tile = game->map->array[new_y][new_x];
	if (tile == '1')
		return ;
	if (tile == 'C')
		game->map->remain_items_count--;
	if (tile == 'E')
	{
		if (game->map->remain_items_count == 0)
		{
			ft_printf("YOU WIN!\n");
			free_game(game);
			exit(0);
		}
		else
		{
			ft_printf("Check %d item(s) before exit\n",
				game->map->remain_items_count);
			return ;
		}
	}
	replace_player_pos(game, new_y, new_x);
	ft_printf("Steps: %d\n", game->steps_count++);
	render_map(game);
}

void	replace_player_pos(t_game *game, int new_y, int new_x)
{
	game->map->array[game->player_y][game->player_x] = '0';
	game->map->array[new_y][new_x] = 'P';
	game->player_y = new_y;
	game->player_x = new_x;
}

int	key_press(int keycode, t_game *game)
{
	if (!game || !game->user_win_ptr)
		return (1);
	if (keycode == KEY_W)
		move_player(game, game->player_y - 1, game->player_x);
	else if (keycode == KEY_A)
		move_player(game, game->player_y, game->player_x - 1);
	else if (keycode == KEY_S)
		move_player(game, game->player_y + 1, game->player_x);
	else if (keycode == KEY_D)
		move_player(game, game->player_y, game->player_x + 1);
	else if (keycode == KEY_ESC)
	{
		free_game(game);
		exit(0);
	}
	return (0);
}
