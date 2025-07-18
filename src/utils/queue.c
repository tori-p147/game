/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:35:23 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/18 16:50:34 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_tile	*init_data(t_game *game)
{
	t_tile *data;
	
	data = malloc(sizeof(t_tile) * game->map->rows * game->map->cols);
	if (!data)
		return (NULL);
	return (data);
}

void	push(t_queue *q, t_tile new_point)
{
	q->data[q->tail++] = new_point;
	printf("IN Queue AFTER push y = %d, x = %d, q.tail = %d\n", q->data[q->tail].y, q->data[q->tail].x, q->tail);
}

t_tile	pop(t_queue *q)
{
	int		i;
	t_tile	curr;

	i = q->head;
	curr = q->data[q->head++];
	while (i < q->tail)
	{
		printf("AFTER pop y = %d, x = %d\n", q->data[i].y, q->data[i].x);
		i++;
	}
	return (curr);
}

int	is_empty(t_queue *q)
{
	printf("CHECK is empty q->head: %d q->tail: %d\n", q->head, q->tail);
	return (q->head == q->tail);
}

t_tile	create_node(int y, int x)
{
	t_tile	new_node;

	new_node.y = y;
	new_node.x = x;
	return (new_node);
}
