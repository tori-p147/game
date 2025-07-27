/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:23:24 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/27 14:43:43 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BFS_H
# define BFS_H
# define MAX_SIDE 4

# include <stdbool.h>
# include "structs.h"

int						is_not_visited_tile(t_game *game, bool **visited, int y,
							int x);
void					serch_neighbours(t_game *game, t_queue *q,
							bool **visited, t_tile curr);
int						is_has_exit(t_game *game);
bool					**init_visited(t_game *game);
int						search_exit(t_game *game, t_queue *q,
							bool **visited);

#endif