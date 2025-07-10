/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 22:23:31 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/10 18:15:30 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_utils.h"
#include "so_long.h"
#include "validator.h"

void	exit_error(const char *msg, t_game *game)
{
	perror(msg);
	if (game)
		free_game(game);
	exit(EXIT_FAILURE);
}

void	validate_line_length(char *line)
{
	static int	old_line_length;
	int			new_line_length;

	new_line_length = ft_strlen(line);
	printf("%d", old_line_length);
	printf("\n%d", new_line_length);
	printf("\n---\n");
	if (old_line_length != 0 && old_line_length != new_line_length)
		exit_error("map.rows length is not same", NULL);
	old_line_length = new_line_length;
}

void	validate_wall(char c, t_game *game)
{
	const char	*err_no_walls_msg;

	err_no_walls_msg = "error occurred because map haven`t walls";
	if (c != '1')
		exit_error(err_no_walls_msg, game);
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
