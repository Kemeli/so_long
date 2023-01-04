/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 21:07:47 by kdaiane-          #+#    #+#             */
/*   Updated: 2022/11/07 19:53:04 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define FILE_WALL	"assets/FILE_WALL.xpm"
# define FILE_SPACE	"assets/FILE_SPACE.xpm"
# define FILE_COLLECTIBLE	"assets/FILE_COLLECTIBLE.xpm"
# define FILE_EXIT	"assets/FILE_EXIT.xpm"
# define FILE_PLAYER	"assets/FILE_PLAYER.xpm"
# define FILE_PLAYER_L	"assets/FILE_PLAYER_L.xpm"
# define FILE_EXIT_2	"assets/FILE_EXIT_2.xpm"
# define SIZE 32

typedef struct s_map
{
	char	*map_path;
	char	*map_extension;
	char	copy_map[1300];
	char	**grid;
	char	**vis;
	int		cols;
	int		rows;
}	t_map;

typedef struct s_path
{
	int	neighbour;
	int	up;
	int	down;
	int	left;
	int	right;
}	t_path;

typedef struct s_utils
{
	int	count_collect;
	int	count_exit;
	int	count_player;
	int	temp_collect;
}	t_utils;

typedef struct s_player
{
	char	player_dir;
	int		collected;
	int		moves;
}	t_player;

typedef struct s_img
{
	void	*walls;
	void	*floor;
	void	*collectible;
	void	*player;
	void	*player_l;
	void	*exit;
	void	*exit_2;
}	t_image;

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_utils		*utils;
	t_image		*img;
	t_position	*position;
	t_player	*player;
	t_path		*path;
}	t_game;

void	inicialize_values(t_game *game, char *map_path);
void	input_validation(int argc, char *map_path);
void	extension_map(t_game *game);
void	map_reading(t_game *game);
void	valid_map_char(t_game *game);
void	grid(t_game	*game);
void	surronded_by_walls(t_game *game);
int		print_error(char *error_message, t_game *game);
void	is_path(t_game *game);
void	initialize_mlx(t_game *game);
void	init_sprites(t_game *game);
void	init_position(t_game *game);
int		render(t_game *game);
void	set_hooks(t_game *game);
void	render_you_won(t_game *game);
int		close_window(t_game *game);
void	get_map(t_game *game);
void	ft_free_ptr(void **ptr);
void	free_grid(t_game *game, char *error_message);
void	free_vis(t_game *game, char *error_message);
void	player_dir(t_game *game, int j, int i);
void	exit_sprite(t_game *game, int i, int j);
void	img_to_win(t_game *game, void *img, int height, int width);

#endif
