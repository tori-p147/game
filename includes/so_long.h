/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:42:59 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/15 21:05:25 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "free_utils.h"
# include "get_next_line.h"
# include "init.h"
# include "move_logic.h"
# include "render.h"
# include "validator.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <libft.h>
# include <mlx.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_map
{
	char	**array;
	int		rows;
	int		cols;
	size_t	player_count;
	size_t	exit_count;
	size_t	remain_items_count;
}			t_map;

typedef struct s_game
{
	void	*mlx_display_ptr;
	void	*user_win_ptr;
	void	*space_img;
	void	*player_img;
	void	*wall_img;
	void	*item_img;
	void	*exit_img;
	int		tile_size;
	int		win_width;
	int		win_height;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	t_map	*map;
}			t_game;

void		alloc_map_arrays(const char *map_name, t_game *game);
void		parse_map_objects(t_game *game);
int			exit_game(t_game *game);

#endif