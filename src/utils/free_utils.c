/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 22:34:44 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/25 20:10:33 by vmatsuda         ###   ########.fr       */
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

void	free_game(t_game *game)
{
	if (game->images_initialized)
		free_all_images(game);
	if (game->user_win_ptr)
		mlx_clear_window(game->mlx_display_ptr, game->user_win_ptr);
	if (game->user_win_ptr)
		mlx_destroy_window(game->mlx_display_ptr, game->user_win_ptr);
	if (game->mlx_display_ptr)
	{
		mlx_destroy_display(game->mlx_display_ptr);
		free(game->mlx_display_ptr);
	}
	if (game->map_initialized)
		free_map(game->map);
}

void	free_images_ptrs(t_game *game, int last_index)
{
	int	i;

	i = 0;
	while (i <= last_index)
	{
		if (game->sprites[i].img_ptr)
		{
			mlx_destroy_image(game->mlx_display_ptr, game->sprites[i].img_ptr);
			game->sprites[i].img_ptr = NULL;
		}
		i++;
	}
}

void	free_all_images(t_game *game)
{
	free_images_ptrs(game, IMG_COUNT - 1);
}
