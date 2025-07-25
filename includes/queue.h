/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:36:09 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/20 18:45:19 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include "structs.h"

t_tile					*init_data(t_game *game);
void					push(t_queue *q, t_tile new_point);
t_tile					pop(t_queue *q);
int						is_empty(t_queue *q);
t_tile					create_node(int y, int x);

#endif