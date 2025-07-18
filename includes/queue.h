/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:36:09 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/18 16:33:48 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include "so_long.h"

typedef struct s_game	t_game;

typedef struct s_tile
{
	int					x;
	int					y;
}						t_tile;

typedef struct s_queue
{
	t_tile				*data;
	int					head;
	int					tail;
	int					capacity;
}						t_queue;

t_tile					*init_data(t_game *game);
void					push(t_queue *q, t_tile new_point);
t_tile					pop(t_queue *q);
int						is_empty(t_queue *q);
t_tile					create_node(int y, int x);

#endif