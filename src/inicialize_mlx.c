/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialize_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 04:21:17 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/01/05 01:01:56 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	initialize_mlx(t_game *game)
{
	int		x;
	int		y;

	x = game->map->rows * SIZE;
	y = game->map->cols * SIZE;
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		print_error("mlx_init\n", game);
	game->win = mlx_new_window(game->mlx, y, x, "cats will be cats");
	if (!game->win)
		print_error("couldn't inicialize window\n", game);
	return ;
}
