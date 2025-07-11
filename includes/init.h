/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:40:07 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/11 15:21:13 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "so_long.h"

typedef struct s_game	t_game;

void					init_window(t_game *game);
void					init_map(const char *map_name, t_game *game);

#endif