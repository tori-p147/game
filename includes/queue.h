/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:36:09 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/17 19:01:12 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include "so_long.h"

typedef struct s_tile
{
	int		x;
	int		y;
	int		steps;
	int		collected_count;
}			t_tile;

typedef struct s_queue
{
	t_tile	*data;
	int		head;
	int		tail;
	int		capacity;
}			t_queue;

void		init_queue(t_queue q, t_game *game);
void		push(t_queue *q, t_tile new_point);
t_tile		pop(t_queue *q);
int			is_empty(t_queue *q);
t_tile		create_node(int y, int x);

#endif