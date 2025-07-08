/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 22:34:44 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/08 22:43:55 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "free_utils.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	i = -1;
	while (i < map->rows)
		free(map->array[i++]);
	free(map->array);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	free(game->mlx_ptr);
	free(game->win_ptr);
	free_map(game->map);
}
