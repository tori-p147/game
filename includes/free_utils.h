/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 22:39:09 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/11 15:20:51 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_UTILS_H
# define FREE_UTILS_H

# include "so_long.h"

typedef struct s_map	t_map;
typedef struct s_game	t_game;

void					free_map(t_map *map);
void					free_game(t_game *game);

#endif