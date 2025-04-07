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

#include <stdio.h>

# define BUFFER_SIZE 42
# define MAP_ERR -1

typedef struct s_mlx{
    void *ptr_mlx;
    void *win;
} t_mlx;

typedef struct s_player{
    float pos_x;
    float pos_y;
    float dir_x;
    float dir_y;
    float plane_x;
    float plane_y;
} t_player;

typedef struct {
    t_mlx graphic;
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

#endif
