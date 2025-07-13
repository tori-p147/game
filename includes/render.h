/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 22:24:06 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/13 19:48:59 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "so_long.h"

void	render_map(t_game *game);
void	render_player(t_game *game, int x, int y);
void	render_exit(t_game *game, int x, int y);
void	render_space(t_game *game, int x, int y);
void	render_wall(t_game *game, int x, int y);
void	render_item(t_game *game, int x, int y);

#endif