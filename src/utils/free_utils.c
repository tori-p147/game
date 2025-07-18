/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 22:34:44 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/18 10:50:25 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_visited(bool **visited, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->rows)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < map->rows)
	{
		free(map->array[i]);
		i++;
	}
	free(map);
}

int	free_game(t_game *game)
{
	free(game->player_img);
	free(game->wall_img);
	free(game->exit_img);
	free(game->item_img);
	free(game->space_img);
	mlx_clear_window(game->mlx_display_ptr, game->user_win_ptr);
	mlx_destroy_window(game->mlx_display_ptr, game->user_win_ptr);
	mlx_destroy_display(game->mlx_display_ptr);
	free(game->mlx_display_ptr);
	free_map(game->map);
	exit(EXIT_SUCCESS);
}
