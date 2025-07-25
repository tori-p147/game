/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:23:01 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/20 22:12:55 by vmatsuda         ###   ########.fr       */
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
	int			i;
	int			pos_y;
	int			pos_x;
	const int	dy[MAX_SIDE] = {-1, 0, 1, 0};
	const int	dx[MAX_SIDE] = {0, -1, 0, 1};

	i = MAX_SIDE;
	while (--i >= 0)
	{
		pos_y = curr.y + dy[i];
		pos_x = curr.x + dx[i];
		if (is_not_visited_tile(game, visited, pos_y, pos_x))
		{
			if (game->map->array[pos_y][pos_x] == 'C')
				game->map->collected_items_count++;
			visited[pos_y][pos_x] = true;
			push(q, create_node(pos_y, pos_x));
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
			while (--y >= 0)
				free(visited[y]);
			return (NULL);
		}
		memset(visited[y], 0, sizeof(bool) * game->map->cols + 1);
		y++;
	}
	return (visited);
}

int	is_has_exit(t_game *game)
{
	t_tile	*data;
	t_queue	q;
	bool	**visited;
	bool	is_exit_found;

	is_exit_found = false;
	visited = init_visited(game);
	if (!visited)
		exit_error("visited allocation fail\n", game);
	data = init_data(game);
	if (!data)
		exit_error("queue.data allocation fail\n", game);
	init_q(data, &q, game);
	is_exit_found = search_exit(game, &q, visited);
	free(data);
	free_visited(visited, game);
	return (is_exit_found);
}

int	search_exit(t_game *game, t_queue *q, bool **visited)
{
	t_tile	curr;

	curr = create_node(game->player_y, game->player_x);
	push(q, curr);
	while (!is_empty(q))
	{
		curr = pop(q);
		if (curr.x == game->exit_x && curr.y == game->exit_y)
			game->map->found_exit = true;
		if (game->map->collected_items_count == game->map->remain_items_count
			&& game->map->found_exit)
			return (1);
		serch_neighbors(game, q, visited, curr);
	}
	return (0);
}
