/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:35:23 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/19 17:10:21 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_tile	*init_data(t_game *game)
{
	t_tile	*data;

	data = malloc(sizeof(t_tile) * game->map->rows * game->map->cols);
	if (!data)
		return (NULL);
	return (data);
}

void	push(t_queue *q, t_tile new_point)
{
	q->data[q->tail++] = new_point;
}

t_tile	pop(t_queue *q)
{
	return (q->data[q->head++]);
}

int	is_empty(t_queue *q)
{
	return (q->head == q->tail);
}

t_tile	create_node(int y, int x)
{
	t_tile	new_node;

	new_node.y = y;
	new_node.x = x;
	return (new_node);
}
