/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:42:59 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/07 22:29:01 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	*map;
}			t_game;

int			event_handler(int key, void *mlx);

#endif