/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 22:24:06 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/20 18:45:23 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# define IDX_WALL 0
# define IDX_PLAYER 1
# define IDX_ITEM 2
# define IDX_EXIT 3
# define IDX_SPACE 4

# include "structs.h"

void	render_map(t_game *game);
void	render_img(t_game *game, int screen_x, int screen_y, void *target_img);

#endif