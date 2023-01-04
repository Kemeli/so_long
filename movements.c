/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:27:01 by kdaiane-          #+#    #+#             */
/*   Updated: 2022/11/08 00:50:48 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_position(t_game *game)
{
	game->position->x = 0;
	game->position->y = 0;
	while (game->map->grid[game->position->x][game->position->y]
		&& game->position->x != game->map->rows - 1)
	{
		while (game->map->grid[game->position->x][game->position->y] != 'P'
			&& game->map->grid[game->position->x][game->position->y])
		{
			game->position->y++;
			if (game->map->grid[game->position->x][game->position->y] == 'P')
				break ;
		}
		if (game->map->grid[game->position->x][game->position->y] == 'P')
			break ;
		if (game->position->y == game->map->cols
			&& game->position->x != game->map->rows - 1)
			game->position->y = 0;
		game->position->x++;
	}
	return ;
}

static void	move(t_game *game, int x, int y)
{
	char	next_pos;

	next_pos = game->map->grid[x][y];
	if (next_pos == 'E'
		&& game->player->collected == game->utils->count_collect)
	{
		game->position->y = y;
		game->position->x = x;
		game->player->moves++;
		render_you_won(game);
	}
	if (next_pos != '1' && next_pos != 'E')
	{
		if (next_pos == 'C')
			game->player->collected++;
		game->map->grid[game->position->x][game->position->y] = '0';
		game->map->grid[x][y] = 'P';
		game->position->y = y;
		game->position->x = x;
		game->player->moves++;
		ft_printf ("movements: %d\n", game->player->moves);
	}
	return ;
}

static int	detect_keystroke(int keycode, t_game *game)
{
	if (keycode == XK_Escape || keycode == XK_q)
		close_window(game);
	if (keycode == XK_Up || keycode == XK_w)
		move(game, game->position->x - 1, game->position->y);
	if (keycode == XK_Left || keycode == XK_a)
	{	
		move(game, game->position->x, game->position->y - 1);
		game->player->player_dir = 'j';
	}
	if (keycode == XK_Down || keycode == XK_s)
		move(game, game->position->x + 1, game->position->y);
	if (keycode == XK_Right || keycode == XK_d)
	{
		move(game, game->position->x, game->position->y + 1);
		game->player->player_dir = 'l';
	}
	return (0);
}

void	set_hooks(t_game *game)
{
	mlx_hook(game->win, DestroyNotify, NoEventMask, &close_window, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, &detect_keystroke, game);
	mlx_loop_hook(game->mlx, &render, game);
}
