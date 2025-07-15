/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 22:23:31 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/15 23:16:27 by vmatsuda         ###   ########.fr       */
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

void	validate_wall(char c, t_game *game)
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
// add point in queue
static void	enqueue(t_queue *q, int x, int y)
{
	t_point	new_point;

	new_point.x = x;
	new_point.y = y;
	q->data[q->tail] = new_point;
	q->tail++;
}

// pull point from queue
dequeue(t_queue *q)
{
}

is_empty(t_queue *q)
{
}

void	validate_path(t_game *game)
{
	t_queue	queue;
	char	**visited;
	char	*map_row;
	int		i;

	i = 0;
	visited = malloc(sizeof(char *) * game->map->rows + 1);
	map_row = game->map->array[i];
	while (i < game->map->cols - 1)
		visited[i] = ft_strdup(game->map->array[i]);
	visited[i] = NULL;
	init_queue(&queue, game->map->rows * game->map->cols);
	enqueue(&queue, game->player_x, game->player_y);
	visited[game->player_y][game->player_x] = 1;
}
