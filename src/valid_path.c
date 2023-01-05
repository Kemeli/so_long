/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:43:32 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/01/05 01:02:25 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	is_safe(int r, int c, t_game *game)
{
	if (c >= 0 && c <= game->map->cols && r >= 0 && r <= game->map->rows)
		if (game->map->grid[r][c] != '1')
			return (1);
	return (0);
}

static int	visited(t_game *game, int r, int c)
{
	if (game->map->vis[r][c] != 'v')
	{
		game->map->vis[r][c] = 'v';
		return (0);
	}
	return (1);
}

static int	valid_path(t_game *game, int r, int c, int exit_char)
{
	game->path->neighbour = visited (game, r, c);
	if (game->map->grid[r][c] == 'E')
		exit_char = 1;
	if (exit_char && game->utils->temp_collect == game->utils->count_collect)
		return (1);
	if (is_safe(r, c, game) && !game->path->neighbour)
	{
		if (game->map->grid[r][c] == 'C')
			game->utils->temp_collect++;
		game->path->up = valid_path(game, r - 1, c, exit_char);
		if (game->path->up)
			return (1);
		game->path->left = valid_path(game, r, c - 1, exit_char);
		if (game->path->left)
			return (1);
		game->path->right = valid_path(game, r, c + 1, exit_char);
		if (game->path->right)
			return (1);
		game->path->down = valid_path(game, r + 1, c, exit_char);
		if (game->path->down)
			return (1);
	}
	return (0);
}

void	is_path(t_game *game)
{
	int	x;
	int	y;
	int	exit_char;

	x = 0;
	y = 0;
	exit_char = 0;
	while (game->map->grid[x][y] && x != game->map->rows - 1)
	{
		while (game->map->grid[x][y] != 'P' && game->map->grid[x][y])
		{
			y++;
			if (game->map->grid[x][y] == 'P')
				break ;
		}
		if (game->map->grid[x][y] == 'P')
			break ;
		if (y == game->map->cols && x != game->map->rows - 1)
			y = 0;
		x++;
	}
	game->map->vis = ft_split(game->map->copy_map, '\n');
	if (!valid_path(game, x, y, exit_char))
		free_vis(game, "No valid path on the map");
}
