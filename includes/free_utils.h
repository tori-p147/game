/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 22:39:09 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/20 22:50:12 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_UTILS_H
# define FREE_UTILS_H

# include "structs.h"
# include <stdbool.h>

void	free_map(t_map *map);
void	free_game(t_game *game);
void	free_visited(bool **visited, t_game *game);
void	free_images_ptrs(t_game *game, int i);
void	free_all_images(t_game *game);

#endif