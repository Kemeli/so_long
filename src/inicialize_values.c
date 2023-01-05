/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialize_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 03:12:05 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/01/05 01:02:00 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	inicialize_values(t_game *game, char *map_path)
{
	game->utils = ft_calloc(sizeof (t_utils), 1);
	game->map = ft_calloc (sizeof(t_map), 1);
	game->path = ft_calloc (sizeof (t_path), 1);
	game->map->map_path = ft_strdup(map_path);
	game->position = ft_calloc(sizeof(t_position), 1);
	game->player = ft_calloc(sizeof(t_player), 1);
	game->img = ft_calloc(sizeof(t_image), 1);
	if (!game->player || !game->utils || !game->position || !game->img)
		print_error ("couldn't allocate memory", game);
	game->player->player_dir = 'j';
	return ;
}
