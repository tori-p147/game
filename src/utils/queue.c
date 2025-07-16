/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:35:23 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/16 19:00:58 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	init_queue(t_queue *q, int capacity)
{
	q->data = malloc(sizeof(t_tile) * capacity);
	q->head = 0;
	q->tail = 0;
	q->capacity = capacity;
}

void	push(t_queue *q, t_tile new_point)
{
	int	i;

	i = q->head;
	q->data[q->tail] = new_point;
	q->tail++;
	while (i < q->tail)
	{
		printf("AFTER push x = %d, y = %d\n", q->data[i].x, q->data[i].y);
		i++;
	}
}

t_tile	pop(t_queue *q)
{
	int		i;
	t_tile	curr;

	i = q->head;
	curr = q->data[q->head++];
	while (i < q->tail)
	{
		printf("AFTER pop x = %d, y = %d\n", q->data[i].x, q->data[i].y);
		i++;
	}
	return (curr);
}

int	is_empty(t_queue *q)
{
	printf("CHECK is empty q->head: %d q->tail: %d\n", q->head, q->tail);
	if (q->head == q->tail)
		return (1);
	return (0);
}
