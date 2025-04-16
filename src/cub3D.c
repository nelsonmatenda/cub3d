/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:31:14 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/04/16 12:32:03 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void get_map(t_game *game, char *map_path)
{
	int fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		ft_error("Cannot read map1.");
	game->map = ft_read_map(fd);
	close(fd);
}

int main(int ac, char **av)
{
	t_game game;

	if (ac != 2)
		return (ft_exit(NULL, MAP_ERR,\
						"Theres no maps: Try > ./cub3d maps/default.cub"), 1);
	get_map(&game, av[1]);
	// (void)av;
	init_game(&game);
	draw_map(&game);


	mlx_loop(game.mlx);
	return (0);
}
