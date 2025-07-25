/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:42:59 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/20 19:41:59 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "bfs.h"
# include "free_utils.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "init.h"
# include "move_logic.h"
# include "queue.h"
# include "render.h"
# include "structs.h"
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

int		exit_error(const char *msg, t_game *game);
void	alloc_map_arrays(const char *map_name, t_game *game);
void	parse_map_objects(t_game *game);

#endif