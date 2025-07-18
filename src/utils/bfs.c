/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:23:01 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/18 16:44:38 by vmatsuda         ###   ########.fr       */
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
	const int	dy[4] = {-1, 0, 1, 0};
	const int	dx[4] = {0, -1, 0, 1};
	t_tile		neighbor;
	int			i;
	int			pos_y;
	int			pos_x;

	i = 0;
	while (i < 4)
	{
		pos_y = curr.y + dy[i];
		pos_x = curr.x + dx[i];
		if (is_not_visited_tile(game, visited, pos_y, pos_x))
		{
			tile = game->map->array[pos_y][pos_x];
			printf("search tile '%c': y = %d x = %d\n", tile, pos_y, pos_x);
			if (tile == 'C')
				game->map->collected_items_count++;
			visited[pos_y][pos_x] = true;
			neighbor = create_node(pos_y, pos_x);
			printf("add neighbors[%d] '%c': y = %d x = %d\n collected = %d", i,
				tile, pos_y, pos_x, game->map->collected_items_count);
			push(q, neighbor);
		}
		i++;
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
	q.capacity = game->map->rows * game->map->cols;
	q.data = data;
	q.head = 0;
	q.tail = 0;
	printf("PLAYER: y=%d x=%d\n", game->player_y, game->player_x);
	push(&q, create_node(game->player_y, game->player_x));
	while (!is_empty(&q))
	{
		curr = pop(&q);
		printf("poped CURRENT NODE: y = %d x = %d (collected: %d)\n", curr.y,
			curr.x, game->map->collected_items_count);
		if (curr.x == game->exit_x && curr.y == game->exit_y)
			game->map->has_exit = true;
		else if (game->map->collected_items_count == game->map->remain_items_count
			&& game->map->has_exit)
			return (1);
		else
		{
			printf("EXIT NOT FIND (y = %d x = %d): collected %d / %d\n", curr.y,
				curr.x, game->map->collected_items_count,
				game->map->remain_items_count);
			serch_neighbors(game, &q, visited, curr);
		}
	}
	return (0);
}
