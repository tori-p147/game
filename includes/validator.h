/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 22:39:06 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/18 22:57:15 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATOR_H
# define VALIDATOR_H

# include "so_long.h"

typedef struct s_game	t_game;

size_t					validate_rows_length(char *line);
int						is_wall(char c);
void					validate_objects_count(t_game *game);
void					count_map_lines(const char *map_name, t_game *game);
void					validate_tile(t_game *game, char tile, int y, int x);

#endif