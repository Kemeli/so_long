/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:00:30 by kdaiane-          #+#    #+#             */
/*   Updated: 2022/11/08 21:20:49 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_error(char *error_message, t_game *game)
{
	ft_printf ("ERROR\n");
	ft_printf ("%s\n", error_message);
	if (!game)
		exit (0);
	ft_free_ptr((void *)&game->img);
	ft_free_ptr((void *)&game->position);
	ft_free_ptr((void *)&game->utils);
	ft_free_ptr((void *)&game->map->map_path);
	ft_free_ptr((void *)&game->player);
	ft_free_ptr((void *)&game->map);
	ft_free_ptr((void *)&game->path);
	exit (0);
}

static void	error_input(char *error_message)
{
	ft_printf ("ERROR\n");
	ft_printf ("%s\n", error_message);
	exit (0);
}

void	input_validation(int argc, char *map_path)
{
	int	fd;

	if (argc != 2)
		error_input ("invalid number of arguments");
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		error_input("couldn't open the file");
	if (close(fd) == -1)
		error_input("couldn't close fd");
}

void	free_grid(t_game *game, char *error_message)
{
	int	i;

	i = 0;
	while (game->map->grid[i])
	{
		free (game->map->grid[i]);
		i++;
	}
	free (game->map->grid);
	print_error(error_message, game);
}

void	free_vis(t_game *game, char *error_message)
{
	int	i;

	i = 0;
	while (game->map->vis[i])
	{
		free (game->map->vis[i]);
		i++;
	}
	free (game->map->vis);
	free_grid(game, error_message);
}
