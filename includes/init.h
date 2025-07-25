/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:40:07 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/20 23:01:37 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "structs.h"

void	init_window(t_game *game);
void	init_map(const char *map_name, t_game *game);
void	init_imgs(t_game *game);
void	init_q(t_tile *data, t_queue *q, t_game *game);
void	init_imgs_ptrs(t_game *game, char *imgs_paths[]);

#endif