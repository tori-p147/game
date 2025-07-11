/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:41:22 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/11 19:09:55 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

int	event_handler(int key, void *mlx)
{
	(void)key;
	(void)mlx;
	printf("called\n");
	return (0);
}

void	count_map_lines(const char *map_name, t_game *game)
{
	int		fd;
	char	*line;
	size_t	rows_count;
	size_t	cols_count;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		exit_error("error occurred when trying read map file", NULL);
	line = get_next_line(fd);
	rows_count = 0;
	while (line != NULL)
	{
		cols_count = validate_rows_length(line);
		rows_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		exit_error("game.map allocation fail", game);
	game->map->rows = rows_count;
	game->map->cols = cols_count;
}

void	alloc_map_arrays(const char *map_name, t_game *game)
{
	size_t	i;

	count_map_lines(map_name, game);
	game->map->array = malloc(sizeof(char *) * (game->map->rows + 1));
	if (!game->map->array)
		exit_error("map.array[] memory allocation fail", game);
	i = 0;
	while (i < game->map->cols - 1)
	{
		game->map->array[i] = malloc(sizeof(char) * (game->map->cols + 1));
		if (!game->map->array[i])
			exit_error("map.array[][] memory allocation fail", game);
		i++;
	}
}

void	parse_map_objects(t_game *game)
{
	size_t	i;
	size_t	j;
	char	**map_array;

	i = 0;
	while (i < game->map->rows)
	{
		j = 0;
		map_array = game->map->array;
		printf("%s", map_array[i]);
		validate_wall(map_array[i][0], game);
		// validate_wall(map_array[i][game->map->cols - 1], game);
		while (j < game->map->cols)
		{
			// validate_wall(map_array[0][j], game);
			// validate_wall(map_array[game->map->rows - 1][j], game);
			if (map_array[i][j] == 'P')
				game->map->player_count++;
			else if (map_array[i][j] == 'C')
				game->map->collect_count++;
			else if (map_array[i][j] == 'E')
				game->map->exit_count++;
			j++;
		}
		i++;
	}
	validate_objects_count(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		perror("args error");
		exit(EXIT_FAILURE);
	}
	init_map(argv[1], &game);
	parse_map_objects(&game);
	init_window(&game);
	mlx_loop(game.mlx_display_ptr);
	return (0);
}
