/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:49:44 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/01/05 01:02:06 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	extension_map(t_game *game)
{
	game->map->map_extension = ft_strrchr(game->map->map_path, '.');
	if (ft_memcmp(game->map->map_extension, ".ber", 4))
		print_error("problem with map extension", game);
	return ;
}

void	get_map(t_game *game)
{
	int		fd;
	int		read_count;
	char	*buffer;

	fd = open(game->map->map_path, O_RDONLY);
	if (fd < 0)
		print_error("couldn't open the file to get the map", game);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL)
		print_error("couldn't allocate memory for map", game);
	buffer[BUFFER_SIZE] = '\0';
	read_count = read(fd, buffer, BUFFER_SIZE);
	while (read_count > 0)
	{
		buffer[read_count] = '\0';
		ft_strlcat(game->map->copy_map, buffer, 1300);
		read_count = read(fd, buffer, BUFFER_SIZE);
	}
	if (!*game->map->copy_map)
		print_error("Map is empty", game);
	if (close(fd) == -1)
		print_error("couldn't close fd", game);
	free(buffer);
	return ;
}

static void	non_valid_map_char(t_game	*game)
{
	if (game->utils->count_collect < 1)
		print_error("map has no collectibles", game);
	if (game->utils->count_exit < 1)
		print_error("map has no exit", game);
	if (game->utils->count_exit > 1)
		print_error("map should have only one exit", game);
	if (game->utils->count_player < 1)
		print_error("map has no player", game);
	if (game->utils->count_player > 1)
		print_error("map has too many players", game);
	return ;
}

void	valid_map_char(t_game	*game)
{
	int	i;

	i = 0;
	while (game->map->copy_map[i])
	{
		if (game->map->copy_map[i] == 'C')
			game->utils->count_collect++;
		if (game->map->copy_map[i] == 'E')
			game->utils->count_exit++;
		if (game->map->copy_map[i] == 'P')
			game->utils->count_player++;
		if (game->map->copy_map[i] != '\n'
			&& !ft_strchr("EPC10", game->map->copy_map[i]))
			print_error("Invalid char, only EPC10 are allowed", game);
		i++;
	}
	non_valid_map_char(game);
	return ;
}

void	surronded_by_walls(t_game *game)
{
	int	j;
	int	k;
	int	p;

	k = -1;
	j = 0;
	while (game->map->grid[j])
	{
		if (game->map->grid[0][++k] != '1'
			|| game->map->grid[0][game->map->cols -1] != '1')
			free_grid (game, "not surrounded by walls - first line");
		p = 0;
		if (game->map->grid[j][0] != '1'
			|| game->map->grid[j][game->map->cols -1] != '1')
			free_grid(game, "not surrounded by walls - middle lines");
		j++;
		if (game->map->grid[game->map->rows - 1][k] != '1'
			|| game->map->grid[game->map->rows - 1][game->map->cols - 1] != '1')
			free_grid(game, "not surrounded by walls - last line");
	}
	return ;
}
