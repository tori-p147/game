/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 22:23:31 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/11 18:58:00 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(const char *msg, t_game *game)
{
	perror(msg);
	if (game)
		free_game(game);
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
		exit_error("map.rows length is not same", NULL);
	old_line_length = new_line_length;
	return (map_cols = new_line_length);
}

void	validate_wall(char c, t_game *game)
{
	if (c != '1')
		exit_error("error occurred because map haven`t walls", game);
}

void	validate_objects_count(t_game *game)
{
	if (game->map->player_count > 1 || game->map->player_count == 0)
		exit_error("error occurred because player not one", game);
	if (game->map->player_count == 0)
		exit_error("error occurred because player undefined", game);
	if (game->map->collect_count == 0)
		exit_error("error occurred because collectable not exist", game);
	if (game->map->exit_count == 0)
		exit_error("error occurred because exit not exists", game);
}
