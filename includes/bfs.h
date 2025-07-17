/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:23:24 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/17 19:04:44 by vmatsuda         ###   ########.fr       */
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

typedef struct s_bfs_context
{
	bool				***visited;
	int					collected_state;
	t_game				*game;
	t_queue				q;
}						t_bfs_context;

int						exit_bts(const char *msg, bool ***visited, t_tile *data,
							t_game *game);
int						is_valid_tile(t_game *game, int y, int x);
void					serch_neighbors(t_bfs_context ctx, t_tile curr);
int						is_has_exit(t_game *game);
void					init_context(t_bfs_context *ctx, t_game *game);
void					init_visited(bool ***visited, t_game *game);

#endif