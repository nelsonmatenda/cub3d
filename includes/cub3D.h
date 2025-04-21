/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:55:48 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/04/21 15:10:22 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <libft.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>

# define BUFFER_SIZE 42
# define MAP_ERR -1
# define MLX_ERR -32
# define MALLOC_ERR -33
# define WIDTH 1280
# define HEIGHT 800
# define BITS 8
# define BLOCK 32
# define PI 3.14159265359

# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_img{
	void	*ptr;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
}			t_img;

typedef struct s_player{
	float	x;
	float	y;
	float	plane_x;
	float	plane_y;
	float	angle;
	bool	key_up;
	bool	key_down;
	bool	key_right;
	bool	key_left;
	bool	left_rotate;
	bool	right_rotate;
}			t_player;

typedef struct s_rgb{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_map{
	char	**content;
	char	**configs;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	t_rgb	f;
	t_rgb	c;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_player	player;
	t_map		map;
	char		**file_content;
}				t_game;

int		ft_exit(t_game *game, int status, char *msg);
char	*ft_get_next_line(int fd, int *new_line_end);
char	*ft_append_character(char *line, char c);
char	**ft_append_line(char **map, char *line);
void	ft_error(char *s);
void	ft_set_color(t_game *game, char *key_config, char *rgb);
void	ft_parse_config_line(t_game *game);
void	ft_read_file(char *map_path, char ***file_content);
void	init_game(t_game *game);
void	put_pixel(t_game *game, int color, int x, int y);
void	draw_line(t_point a, t_point b, t_game *game);
void	draw_map(t_game *game);
void	draw_player(t_player *player, int size, t_game *game);
int		ft_key_release(int key, t_player *player);
int		ft_key_press(int key, t_player *player);
void	move_player(t_player *player);
int		game_loop(t_game *game);

#endif
