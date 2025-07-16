/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 22:23:31 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/16 19:04:34 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_error(const char *msg, t_game *game)
{
	if (game)
		free_map(game->map);
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

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

void	is_wall(char c, t_game *game)
{
	if (c != '1')
		exit_error("Error occurred because map haven`t walls\n", game);
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

static int	check_neighbor(char neighbor)
{
	if (neighbor != '1')
		return (0);
	return (1);
}

void	serch_and_pop_neighbors(t_game *game, t_queue *q, t_tile curr)
{
	int		i;
	char	tile;
	t_tile	neighbor;
	int		dy[4] = {-1, 0, 1, 0};
	int		dx[4] = {0, -1, 0, 1};

	i = 0;
	while (i < 4)
	{
		tile = game->map->array[curr.y + dy[i]][curr.x + dx[i]];
		if (check_neighbor(neighbor))
		{
			neighbor.x = curr.y + dy[i];
			neighbor.y = curr.x + dx[i];
			push(q, neighbor);
		}
		i++;
	}
}

int	validate_path(t_game *game)
{
	t_queue	q;
	int		i;
	t_tile	curr;
	t_tile	neighbor;

	i = 0;
	init_queue(&q, game->map->rows * game->map->cols);
	push(&q, game->player_x, game->player_y);
	while (!is_empty(&q))
	{
		curr = pop(q);
		curr.visited = true;
		if (curr.x == game->exit_x && curr.y == game->exit_y)
			return (1);
		else
		{
			serch_and_pop_neighbors(&game, &q, &curr);
		}
	}
	return (0);
}
