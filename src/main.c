/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:50:52 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/26 21:04:22 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map_name(char *name)
{
	size_t	len;

	len = ft_strlen(name);
	if (ft_strncmp(&name[len - 4], ".ber", 4) != 0)
	{
		write(2, "Error: map format error", 23);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		if (!validate_map_name(argv[1]))
			return (1);
		init_map(argv[1], &game);
		parse_map_objects(&game);
		init_window(&game);
		render_map(&game);
		mlx_hook(game.user_win_ptr, KeyPress, KeyPressMask, key_press, &game);
		mlx_hook(game.user_win_ptr, DestroyNotify, NoEventMask, close_win,
			&game);
		mlx_loop(game.mlx_display_ptr);
		return (0);
	}
	ft_printf("args error");
	return (1);
}
