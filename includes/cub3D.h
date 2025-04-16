/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:55:48 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/04/07 09:58:17 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define BUFFER_SIZE 42
# define MAP_ERR -1
# include <libft.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#include <stdio.h>

typedef struct s_mlx{
	void	*ptr_mlx;
	void	*win;
}	t_mlx;

typedef struct s_player{
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
}	t_player;

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

typedef struct s_game{
	t_map		map;
	t_mlx		graphic;
	t_player	player;
}	t_game;

int		ft_exit(t_game *game, int status, char *msg);
char	*ft_get_next_line(int fd, int *new_line_end);
char	*ft_append_character(char *line, char c);
char	**ft_append_line(char **map, char *line);
void	ft_error(char *s);
void	ft_read_file(char *map_path, char ***file_content);

#endif
