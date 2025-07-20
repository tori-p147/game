/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:42:59 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/19 16:58:12 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define IMG_COUNT 5

# include "bfs.h"
# include "free_utils.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "init.h"
# include "move_logic.h"
# include "queue.h"
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

typedef struct s_img
{
	void	*img_ptr;
	int		width;
	int		height;
}			t_img;

typedef struct s_map
{
	char	**array;
	int		rows;
	int		cols;
	int		player_count;
	int		exit_count;
	int		remain_items_count;
	int		collected_items_count;
	bool	found_exit;
}			t_map;

typedef struct s_game
{
	void	*mlx_display_ptr;
	void	*user_win_ptr;
	int		tile_size;
	int		win_width;
	int		win_height;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		steps_count;
	t_map	*map;
	t_img	sprites[IMG_COUNT];
}			t_game;

int			exit_error(const char *msg, t_game *game);
void		alloc_map_arrays(const char *map_name, t_game *game);
void		parse_map_objects(t_game *game);

#endif