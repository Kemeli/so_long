/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:32:13 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/01/05 01:02:14 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	img_to_win(t_game *game, void *img, int height, int width)
{
	mlx_put_image_to_window(game->mlx, game->win, img, height, width);
}

int	render(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map->grid[++i])
	{
		j = -1;
		while (game->map->grid[i][++j])
		{
			if (game->map->grid[i][j] == '1')
				img_to_win(game, game->img->walls, 32 * j, 32 * i);
			else if (game->map->grid[i][j] == 'C')
				img_to_win(game, game->img->collectible, 32 * j, 32 * i);
			else if (game->map->grid[i][j] == 'E')
				exit_sprite(game, i, j);
			else if (game->map->grid[i][j] == 'P')
				player_dir(game, j, i);
			else if (game->map->grid[i][j] == '0')
				img_to_win(game, game->img->floor, 32 * j, 32 * i);
		}
	}
	return (0);
}
