/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:40:07 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/15 23:11:41 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "so_long.h"

typedef struct s_queue	t_queue;
typedef struct s_game	t_game;

void					init_window(t_game *game);
void					init_map(const char *map_name, t_game *game);
void					init_space(t_game *game);
void					init_exit(t_game *game);
void					init_item(t_game *game);
void					init_palyer(t_game *game);
void					init_wall(t_game *game);
void					init_queue(t_queue *q, int capacity);

#endif