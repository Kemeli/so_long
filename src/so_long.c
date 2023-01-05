/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:58:08 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/01/05 01:02:18 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	char	*map_path;

	ft_bzero(&game, sizeof (t_game));
	map_path = argv[1];
	input_validation(argc, map_path);
	inicialize_values(&game, map_path);
	extension_map(&game);
	get_map(&game);
	valid_map_char(&game);
	grid(&game);
	surronded_by_walls(&game);
	is_path(&game);
	initialize_mlx(&game);
	init_sprites(&game);
	init_position(&game);
	set_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}
