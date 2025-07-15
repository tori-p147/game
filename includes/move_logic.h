/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_logic.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:31:51 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/15 14:36:27 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_LOGIC_H
# define MOVE_LOGIC_H

# include "so_long.h"

typedef struct s_game	t_game;

typedef enum e_keycode
{
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_ESC = 65307
}						t_keycode;

void					move_player(t_game *game, int dx, int dy);
int						key_press(int keycode, t_game *game);

#endif