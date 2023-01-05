/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:37:22 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/01/05 01:01:38 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_ptr(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static void	destroy_images(t_game *game)
{
	if (game->img->floor)
		mlx_destroy_image(game->mlx, game->img->floor);
	if (game->img->walls)
		mlx_destroy_image(game->mlx, game->img->walls);
	if (game->img->collectible)
		mlx_destroy_image(game->mlx, game->img->collectible);
	if (game->img->exit)
		mlx_destroy_image(game->mlx, game->img->exit);
	if (game->img->player)
		mlx_destroy_image(game->mlx, game->img->player);
	if (game->img->player_l)
		mlx_destroy_image(game->mlx, game->img->player_l);
	if (game->img->exit_2)
		mlx_destroy_image(game->mlx, game->img->exit_2);
	return ;
}

void	game_close(t_game *game)
{
	int	i;

	destroy_images(game);
	mlx_destroy_display(game->mlx);
	free (game->mlx);
	ft_free_ptr((void *)&game->img);
	ft_free_ptr((void *)&game->position);
	ft_free_ptr((void *)&game->utils);
	ft_free_ptr((void *)&game->map->map_path);
	ft_free_ptr((void *)&game->player);
	ft_free_ptr((void *)&game->path);
	i = 0;
	while (game->map->grid[i])
	{
		free (game->map->grid[i]);
		free (game->map->vis[i]);
		i++;
	}
	free (game->map->grid);
	free (game->map->vis);
	ft_free_ptr((void *)&game->map);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	game->win = NULL;
	game_close(game);
	exit(0);
}

void	render_you_won(t_game *game)
{
	ft_printf("you won\n", game);
	close_window(game);
}
