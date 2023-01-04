/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:03:55 by kdaiane-          #+#    #+#             */
/*   Updated: 2022/11/07 19:35:14 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*get_sprites(char *spr_path, t_game *game)
{
	int	h;
	int	w;

	h = SIZE;
	w = SIZE;
	return (mlx_xpm_file_to_image(game->mlx, spr_path, &h, &w));
}

void	init_sprites(t_game *game)
{
	game->img->floor = get_sprites(FILE_SPACE, game);
	game->img->walls = get_sprites(FILE_WALL, game);
	game->img->collectible = get_sprites(FILE_COLLECTIBLE, game);
	game->img->player = get_sprites(FILE_PLAYER, game);
	game->img->player_l = get_sprites(FILE_PLAYER_L, game);
	game->img->exit = get_sprites(FILE_EXIT, game);
	game->img->exit_2 = get_sprites(FILE_EXIT_2, game);
}

void	player_dir(t_game *game, int j, int i)
{
	if (game->player->player_dir == 'j')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->player, 32 * j, 32 * i);
	if (game->player->player_dir == 'l')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->player_l, 32 * j, 32 * i);
}

void	exit_sprite(t_game *game, int i, int j)
{
	if (game->player->collected == game->utils->count_collect)
		img_to_win(game, game->img->exit_2, 32 * j, 32 * i);
	else
		img_to_win(game, game->img->exit, 32 * j, 32 * i);
}
