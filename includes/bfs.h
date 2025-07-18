/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:23:24 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/18 16:46:17 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BFS_H
# define BFS_H

# include "queue.h"
# include "so_long.h"
# include <stdbool.h>

typedef struct s_tile	t_tile;
typedef struct s_queue	t_queue;
typedef struct s_game	t_game;

int						exit_bts(const char *msg, bool **visited, t_tile *data,
							t_game *game);
int						is_not_visited_tile(t_game *game, bool **visited, int y,
							int x);
void					serch_neighbors(t_game *game, t_queue *q,
							bool **visited, t_tile curr);
int						is_has_exit(t_game *game);
bool					**init_visited(t_game *game);

#endif