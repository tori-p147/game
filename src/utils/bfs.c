/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:23:01 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/17 19:00:13 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_tile(t_game *game, int pos_y, int pos_x)
{
	return (!is_wall(game->map->array[pos_y][pos_x]) && pos_y < game->map->rows
		&& pos_y >= 0 && pos_x < game->map->cols && pos_x >= 0);
}

void	serch_neighbors(t_bfs_context ctx, t_tile curr)
{
	char		tile;
	const int	dy[4] = {-1, 0, 1, 0};
	const int	dx[4] = {0, -1, 0, 1};
	t_tile		neighbor;
	int			i;
	int			pos_y;
	int			pos_x;
	int			collected;

	i = 0;
	while (i < 4)
	{
		pos_y = curr.y + dy[i];
		pos_x = curr.x + dx[i];
		if (is_valid_tile(ctx.game, pos_y, pos_x)
			&& ctx.visited[pos_y][pos_x] == false)
		{
			tile = ctx.game->map->array[pos_y][pos_x];
			collected = curr.collected_count;
			printf("search tile '%c': y = %d x = %d\n", tile, pos_y, pos_x);
			if (tile == 'C')
				collected++;
			if (!ctx.visited[pos_y][pos_x][collected])
			{
				ctx.visited[pos_y][pos_x][collected] = true;
				neighbor = create_node(pos_y, pos_x);
				neighbor.steps = curr.steps + 1;
				neighbor.collected_count = collected;
				printf("add neighbors[%d] '%c': y = %d x = %d\n", i, tile,
					pos_y, pos_x);
				push(ctx.q, neighbor);
			}
		}
		i++;
	}
}

void	init_visited(bool ***visited, t_game *game)
{
	int	y;
	int	x;
	int	c;

	*visited = malloc(sizeof(bool **) * game->map->rows);
	y = 0;
	while (y < game->map->rows)
	{
		visited[y] = malloc(sizeof(bool *) * game->map->rows);
		x = 0;
		while (x < game->map->rows)
		{
			visited[y][x] = malloc(sizeof(bool) * game->map->remain_items_count
					+ 1);
			c = 0;
			while (c <= game->map->remain_items_count)
			{
				visited[y][x][c] = false;
				c++;
			}
			x++;
		}
		y++;
	}
}

void	init_context(t_bfs_context *ctx, t_game *game)
{
	t_queue	q;
	bool	***visited;

	ctx->game = game;
	init_visited(visited, game);
	if (!ctx->visited)
		free_visited(visited, game);
	ctx->visited = visited;
	init_queue(&q, game);
	ctx->q = q;
	ctx->collected_state = 0;
}

int	is_has_exit(t_game *game)
{
	t_tile			curr;
	t_bfs_context	ctx;

	printf("PLAYER: y=%d x=%d\n", game->player_y, game->player_x);
	init_context(&ctx, game);
	push(ctx->q, create_node(game->player_y, game->player_x));
	while (!is_empty(&ctx.q))
	{
		curr = pop(&ctx.q);
		printf("poped CURRENT NODE: y = %d x = %d\n", curr.y, curr.x);
		if (curr.x == game->exit_x && curr.y == game->exit_y
			&& curr.collected_count == game->total_collectables)
		{
			printf("EXIT FIND - %d steps: y = %d x = %d\n", curr.steps, curr.y,
				curr.x);
			return (1);
		}
		else
			serch_neighbors(ctx, curr);
	}
	return (0);
}
