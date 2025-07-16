/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 22:23:31 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/16 22:27:18 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	validate_rows_length(char *line)
{
	static size_t	old_line_length;
	size_t			new_line_length;
	size_t			map_cols;

	new_line_length = ft_strlen(line);
	if (line[new_line_length - 1] == '\n')
		new_line_length--;
	printf("%ld", old_line_length);
	printf("\n%ld", new_line_length);
	printf("\n---\n");
	if (old_line_length != 0 && old_line_length != new_line_length)
		exit_error("map.rows length is not same\n", NULL);
	old_line_length = new_line_length;
	return (map_cols = new_line_length);
}

int	is_wall(char c)
{
	if (c != '1')
		return (0);
	return (1);
}

void	validate_objects_count(t_game *game)
{
	if (game->map->player_count > 1 || game->map->player_count == 0)
		exit_error("Error occurred because player not one\n", game);
	if (game->map->player_count == 0)
		exit_error("Error occurred because player undefined\n", game);
	if (game->map->remain_items_count == 0)
		exit_error("Error occurred because collectable not exist\n", game);
	if (game->map->exit_count == 0)
		exit_error("Error occurred because exit not exists\n", game);
}

void	serch_and_pop_neighbors(t_game *game, t_queue *q, t_tile curr,
		bool **visited)
{
	int			i;
	char		tile;
	t_tile		neighbor;
	const int	dy[4] = {-1, 0, 1, 0};
	const int	dx[4] = {0, -1, 0, 1};

	i = 0;
	while (i < 4)
	{
		printf("search tile: y = %d x = %d\n", curr.y + dy[i], curr.x + dx[i]);
		tile = game->map->array[curr.y + dy[i]][curr.x + dx[i]];
		if (!is_wall(tile) && visited[curr.y + dy[i]][curr.x + dx[i]] == false
			&& (curr.y + dy[i] < game->map->rows && curr.y + dy[i] > 0)
			&& (curr.x + dx[i] < game->map->cols && curr.x + dx[i] > 0))
		{
			push(q, create_node(neighbor.y = curr.y + dy[i], neighbor.x = curr.x
					+ dx[i]));
			visited[curr.y + dy[i]][curr.x + dx[i]] = true;
			printf("added node: y = %d x = %d\n", curr.y + dy[i], curr.x
				+ dx[i]);
		}
		i++;
	}
}

int	is_has_exit(t_game *game)
{
	t_queue	q;
	int		i;
	t_tile	curr;
	bool	**visited;
	int		step_count;

	i = 0;
	step_count = 0;
	printf("PLAYER: y=%d x=%d\n", game->player_y, game->player_x);
	visited = malloc(sizeof(bool *) * game->map->rows + 1);
	if (!visited)
		exit_error("visited[] memory allocation fail", game);
	while (i < game->map->cols - 1)
	{
		visited[i] = malloc(sizeof(bool) * game->map->cols + 1);
		if (!visited[i])
			exit_error("visited[][] memory allocation fail", game);
		i++;
	}
	init_queue(&q, game->map->rows * game->map->cols);
	push(&q, create_node(game->player_y, game->player_x));
	while (!is_empty(&q))
	{
		curr = pop(&q);
		visited[curr.y][curr.x] = true;
		printf("poped curr: y = %d x = %d\n", curr.y, curr.x);
		if (curr.x == game->exit_x && curr.y == game->exit_y)
			return (1);
		else
		{
			serch_and_pop_neighbors(game, &q, curr, visited);
			step_count++;
			printf("STEPS: %d\n", step_count);
		}
	}
	return (0);
}
