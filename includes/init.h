/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:40:07 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/18 20:25:40 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "so_long.h"

typedef struct s_queue	t_queue;
typedef struct s_game	t_game;

void					init_window(t_game *game);
void					init_map(const char *map_name, t_game *game);
void					*init_img(t_game *game, char *img_path, int *w,
							int *h);
#endif