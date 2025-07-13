/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 22:34:44 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/13 20:24:38 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < map->rows - 1)
	{
		free(map->array[i]);
		i++;
	}
	free(map->array);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	// if (game->user_win_ptr && game->mlx_display_ptr)
	// 	mlx_destroy_window(game->mlx_display_ptr, game->user_win_ptr);
	// if (game->mlx_display_ptr)
	// {
	// 	mlx_destroy_display(game->mlx_display_ptr);
	// 	free(game->mlx_display_ptr);
	// }
	if (game->map)
		free_map(game->map);
}
