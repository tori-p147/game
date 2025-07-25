/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 18:40:30 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/20 22:23:45 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
# define IMG_COUNT 5

# include <stdbool.h>

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
	int		images_initialized;
	int		map_initialized;
	t_map	*map;
	t_img	sprites[IMG_COUNT];
}			t_game;

typedef struct s_tile
{
	int		x;
	int		y;
}			t_tile;

typedef struct s_queue
{
	t_tile	*data;
	int		head;
	int		tail;
	int		capacity;
}			t_queue;

#endif