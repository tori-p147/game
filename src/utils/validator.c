/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 22:23:31 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/19 16:58:28 by vmatsuda         ###   ########.fr       */
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
	if (old_line_length != 0 && old_line_length != new_line_length)
	{
		printf("Error: map.rows length is not same\n");
		exit(-1);
	}
	old_line_length = new_line_length;
	return (map_cols = new_line_length);
}

int	is_wall(char c)
{
	return (c == '1');
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

void	validate_tile(t_game *game, char tile, int y, int x)
{
	if ((y == 0 || y == game->map->rows - 1 || x == 0 || x == game->map->cols
			- 1) && !is_wall(tile))
		exit_error("Error occurred because map haven`t walls\n", game);
	else if (tile == 'P')
	{
		game->map->player_count++;
		game->player_x = x;
		game->player_y = y;
	}
	else if (tile == 'C')
		game->map->remain_items_count++;
	else if (tile == 'E')
	{
		game->map->exit_count++;
		game->exit_x = x;
		game->exit_y = y;
	}
	else
	{
		if (tile != '0' && tile != '1')
			exit_error("Error: map has invalid character\n", game);
	}
}
