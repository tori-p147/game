/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 22:34:44 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/19 19:00:01 by vmatsuda         ###   ########.fr       */
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
	free(map->array);
	free(map);
}

int	free_game(t_game *game)
{
	int	i;

	i = IMG_COUNT;
	while (--i >= 0)
		mlx_destroy_image(game->mlx_display_ptr, game->sprites[i].img_ptr);
	mlx_clear_window(game->mlx_display_ptr, game->user_win_ptr);
	mlx_destroy_window(game->mlx_display_ptr, game->user_win_ptr);
	mlx_destroy_display(game->mlx_display_ptr);
	free(game->mlx_display_ptr);
	free_map(game->map);
	exit(EXIT_SUCCESS);
}
