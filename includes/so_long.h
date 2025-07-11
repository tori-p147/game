/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:42:59 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/11 18:44:27 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "free_utils.h"
# include "get_next_line.h"
# include "init.h"
# include "validator.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <libft.h>
# include <mlx.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_map
{
	char	**array;
	size_t	rows;
	size_t	cols;
	size_t	player_count;
	size_t	exit_count;
	size_t	collect_count;
}			t_map;

typedef struct s_game
{
	void	*mlx_display_ptr;
	void	*user_win_ptr;
	t_map	*map;
}			t_game;

int			event_handler(int key, void *mlx);
void		alloc_map_arrays(const char *map_name, t_game *game);
void		parse_map_objects(t_game *game);

#endif