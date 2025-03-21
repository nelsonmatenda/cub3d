/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:31:14 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/02/20 12:31:20 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void ft_init_game(t_game *game)
{
    int fd;

    fd = open("./maps/map1.cub", O_RDONLY);
    if (fd == -1)
        ft_error("Cannot read map1.");
    game->map = ft_read_map(fd);
    close(fd);
}

int main(void)
{
    t_game game;
    int i;
    int j;

    i = 0;
    j = 0;

    ft_init_game(&game);
    while (game.map[i] != NULL)
    {
        j = 0;
        while (game.map[i][j] != '\0')
        {
            write(1, &game.map[i][j], 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }

    return (0);
}