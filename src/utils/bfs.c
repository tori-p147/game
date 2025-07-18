/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:23:01 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/18 22:17:05 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_not_visited_tile(t_game *game, bool **visited, int pos_y, int pos_x)
{
	return (!is_wall(game->map->array[pos_y][pos_x]) && pos_y < game->map->rows
		&& pos_y >= 0 && pos_x < game->map->cols && pos_x >= 0
		&& visited[pos_y][pos_x] == false);
}

void	serch_neighbors(t_game *game, t_queue *q, bool **visited, t_tile curr)
{
	char		tile;
	const int	dy[MAX_SIDE] = {-1, 0, 1, 0};
	const int	dx[MAX_SIDE] = {0, -1, 0, 1};
	t_tile		neighbor;
	int			i;
	int			pos_y;
	int			pos_x;

	i = MAX_SIDE;
	while (--i >= 0)
	{
		pos_y = curr.y + dy[i];
		pos_x = curr.x + dx[i];
		if (is_not_visited_tile(game, visited, pos_y, pos_x))
		{
			tile = game->map->array[pos_y][pos_x];
			if (tile == 'C')
				game->map->collected_items_count++;
			visited[pos_y][pos_x] = true;
			neighbor = create_node(pos_y, pos_x);
			push(q, neighbor);
		}
	}
}

bool	**init_visited(t_game *game)
{
	bool	**visited;
	int		y;

	visited = malloc(sizeof(bool *) * game->map->rows);
	if (!visited)
		return (NULL);
	y = 0;
	while (y < game->map->rows)
	{
		visited[y] = malloc(sizeof(bool) * game->map->cols + 1);
		if (!visited[y])
		{
			free_visited(visited, game);
			return (NULL);
		}
		y++;
	}
	return (visited);
}

void	init_q(t_tile *data, t_queue *q, t_game *game)
{
	q->capacity = game->map->rows * game->map->cols;
	q->data = data;
	q->head = 0;
	q->tail = 0;
}

int	is_has_exit(t_game *game)
{
	t_tile	curr;
	t_tile	*data;
	t_queue	q;
	bool	**visited;

	visited = init_visited(game);
	if (!visited)
		exit_error("visited allocation fail\n", game);
	data = init_data(game);
	if (!data)
		exit_error("queue.data allocation fail\n", game);
	init_q(data, &q, game);
	push(&q, create_node(game->player_y, game->player_x));
	printf("exit x,y = %d,%d\n", game->exit_x, game->exit_y);
	while (!is_empty(&q))
	{
		curr = pop(&q);
		if (curr.x == game->exit_x && curr.y == game->exit_y)
			game->map->found_exit = true;
		if (game->map->collected_items_count == game->map->remain_items_count
			&& game->map->found_exit)
			return (1);
		printf("COLLECTED: [%d / %d ]\n", game->map->collected_items_count,
			game->map->remain_items_count);
		serch_neighbors(game, &q, visited, curr);
	}
	return (0);
}
