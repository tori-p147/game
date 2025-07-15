/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 22:39:06 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/15 22:38:44 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATOR_H
# define VALIDATOR_H
# include "so_long.h"

typedef struct s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct s_queue
{
	t_point				*data;
	int					head;
	int					tail;
	int					capacity;
}						t_queue;

typedef struct s_game	t_game;

int						exit_error(const char *msg, t_game *game);
size_t					validate_rows_length(char *line);
void					validate_wall(char c, t_game *game);
void					validate_objects_count(t_game *game);
void					validate_path(t_game *game);

#endif