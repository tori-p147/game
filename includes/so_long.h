/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:42:59 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/10 16:52:19 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <libft.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_map
{
	char	**array;
	int		rows;
	int		cols;
	int		player_count;
	int		exit_count;
	int		collect_count;
}			t_map;

typedef struct s_game
{
	void	*mlx_display_ptr;
	void	*user_win_ptr;
	t_map	*map;
}			t_game;

int			event_handler(int key, void *mlx);
int			count_map_lines(const char *map_name);
void		alloc_map_array(const char *map_name, t_game *game);
void		parse_map_objects(t_game *game);

#endif