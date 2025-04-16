/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:55:48 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/04/16 12:58:29 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

# define BUFFER_SIZE 42
# define MAP_ERR -1
# define MLX_ERR -32
# define WIDTH 800
# define HEIGHT 800
# define BITS 8
# define BLOCK 32

typedef struct s_img{
	void	*ptr;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
} t_img;

typedef struct s_player{
	float pos_x;
	float pos_y;
	float dir_x;
	float dir_y;
	float plane_x;
	float plane_y;
} t_player;

typedef struct s_game
{
	void*	mlx;
	void*	win;
	t_img	img;
	t_player player;
	char **map;
} t_game;

#include <libft.h>
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
# include <fcntl.h>

int		ft_exit(t_game *game, int status, char *msg);
char	*ft_get_next_line(int fd, int *new_line_end);
char	**ft_read_map(int fd);
char	*ft_putin_line(char *line, char c);
void	ft_error(char *s);
void	init_game(t_game *game);
void	put_pixel(t_game *game, int color, int x, int y);
void	draw_map(t_game *game);

#endif
