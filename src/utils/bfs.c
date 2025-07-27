/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:23:01 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/27 15:15:03 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_not_visited_tile(t_game *game, bool **visited, int pos_y, int pos_x)
{
	if (pos_y < 0 || pos_y >= game->map->rows)
		return (0);
	if (pos_x < 0 || pos_x >= game->map->cols)
		return (0);
	if (visited[pos_y][pos_x])
		return (0);
	if (game->map->array[pos_y][pos_x] == '1')
		return (0);
	return (1);
}

void	serch_neighbours(t_game *game, t_queue *q, bool **visited, t_tile curr)
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
		if (game->map->array[pos_y][pos_x] == 'E')
		{
			game->map->found_exit = true;
			visited[pos_y][pos_x] = true;
			continue ;
		}
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
		visited[y] = malloc(sizeof(bool) * (game->map->cols));
		if (!visited[y])
		{
			while (--y >= 0)
				free(visited[y]);
			return (NULL);
		}
		memset(visited[y], 0, sizeof(bool) * (game->map->cols));
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

	game->map->collected_items_count = 0;
	game->map->found_exit = false;
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

	game->map->found_exit = false;
	curr = create_node(game->player_y, game->player_x);
	visited[game->player_y][game->player_x] = true;
	push(q, curr);
	while (!is_empty(q))
	{
		curr = pop(q);
		serch_neighbours(game, q, visited, curr);
	}
	if (game->map->collected_items_count != game->map->remain_items_count
		|| !game->map->found_exit)
		return (0);
	return (1);
}
