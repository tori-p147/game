/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 22:39:06 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/08 22:42:45 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATOR_H
# define VALIDATOR_H

# include "so_long.h"

void	exit_error(const char *msg, t_game *game);
int		validate_line_length(char *line);
void	validate_map_objects(t_game *game);

#endif