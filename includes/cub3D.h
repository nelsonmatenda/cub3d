/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <gudos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:55:48 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/06/04 16:45:36 by gudos-sa         ###   ########.fr       */
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
# define VERTICAL 0
# define HORIZONTAL 1
# define PI 3.14159265359

# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363

typedef struct s_vector
{
	float	x;
	float	y;
}		t_vector;

typedef struct s_img{
	void	*ptr;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
}			t_img;

typedef struct s_player{
	t_vector	pos;
	t_vector	plane;
	t_vector	dir;
	bool		key_up;
	bool		key_down;
	bool		key_right;
	bool		key_left;
	bool		left_rotate;
	bool		right_rotate;
}			t_player;

typedef struct s_dda
{
	t_vector	delta;
	t_vector	side_dist;
	t_vector	current;
	float		distance;
	int			step_x;
	int			step_y;
	int			is_wall;
	int			side_impact;
}				t_dda;

typedef struct s_rgb{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef	struct s_texture
{
	t_img image;
	int	width;
	int	height;
}	t_texture;

typedef struct s_map{
	char		**content;
	char		**configs;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	t_texture	textures[4];
	t_rgb		f;
	t_rgb		c;
}	t_map;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_player		player;
	t_map			map;
	char			**file_content;
}				t_game;

void	ft_rotate(float *x, float *y, float a);
int		ft_exit(t_game *game, int status, char *msg);
char	*ft_get_next_line(int fd, int *new_line_end);
char	*ft_append_character(char *line, char c);
char	**ft_append_line(char **map, char *line);
void	ft_free_game(t_game game);
void	ft_free_matriz(char **matriz);
void	ft_free_t_map(t_map map);
void	ft_set_color(t_game *game, char **parts);
int		ft_parse_rgb2(char **parts);
int		ft_qtd_comma(char *rgb);
int		ft_is_number(char *str);
void	ft_parse_config_line(t_game *game);
void	ft_parse_config_line2(t_game *game, char **parts);
void	ft_read_file(char *map_path, t_game *game);
void	ft_parse_content_map(t_game *game);
int		ft_around1(char **map_content);
void	init_game(t_game *game);
void	ft_raycasting(t_game *game);
void	ft_start_end_draw(int *start_draw, int *end_draw, int wall_height);
void	ft_set_image_pixel(t_game *game, int x, int y, int wall_color);
void	ft_set_delta(t_vector ray, t_vector *delta);
void	ft_set_side_dist(t_game *game, t_dda	*dda, t_vector ray);
void	ft_set_distance(t_game *game, t_dda *dda);
void	put_pixel(t_game *game, int color, int x, int y);
int		ft_key_release(int key, t_player *player);
int		ft_key_press(int key, t_player *player);
void	move_player(t_player *player);
int		game_loop(t_game *game);

#endif
