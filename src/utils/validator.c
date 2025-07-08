/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 22:23:31 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/08 22:58:17 by vmatsuda         ###   ########.fr       */
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

int	validate_line_length(char *line)
{
	static int	old_line_length;
	int			new_line_length;

	new_line_length = ft_strlen(line);
	printf("%d", old_line_length);
	printf("\n%d", new_line_length);
	printf("\n---\n");
	if (old_line_length != 0 && old_line_length != new_line_length)
		return (0);
	old_line_length = new_line_length;
	return (1);
}

int	validate_wall(char c)
{
	if (c != '1')
		return (0);
	return (1);
}

void	validate_map_objects(t_game *game)
{
	int		i;
	int		j;
	char	*error_msg;

	i = 0;
	j = 0;
	error_msg = "error occurred because map haven`t walls";
	while (i < game->map->rows)
	{
		if (i == 0 && !validate_wall(game->map->array[0][i]))
			exit_error(error_msg, game);
		else if (i == game->map->rows - 1
			&& !validate_wall(game->map->array[game->map->rows - 1][i]))
			exit_error(error_msg, game);
		while (j < game->map->cols)
		{
			if (j == 0 && !validate_wall(game->map->array[0][j]))
				exit_error(error_msg, game);
			else if (j == game->map->cols - 1
				&& !validate_wall(game->map->array[game->map->cols - 1][j]))
				exit_error(error_msg, game);
			j++;
		}
		i++;
	}
}
