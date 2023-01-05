/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:28:29 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/01/05 01:01:49 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	grid(t_game	*game)
{	
	int	i;

	game->map->grid = ft_split(game->map->copy_map, '\n');
	game->map->cols = ft_strlen(game->map->grid[0]);
	game->map->rows = 0;
	i = -1;
	while (game->map->grid[++i])
	{
		if (ft_strlen(game->map->grid[i]) != (size_t)game->map->cols)
		{
			free_grid(game, "map is not rectangular");
			return ;
		}
		game->map->rows++;
	}
	if (game->map->cols > 40 || game->map->rows > 30)
		free_grid(game, "map is too big! (max 1280 x 960)");
	return ;
}
