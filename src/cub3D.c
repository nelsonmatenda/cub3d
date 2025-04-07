/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:31:14 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/04/07 10:08:55 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void ft_init_game(t_game *game, char *map_path)
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
	int i;
	int j;

	i = 0;
	j = 0;
	if (ac != 2)
		return (ft_exit(NULL, MAP_ERR,\
						"Theres no maps: Try > ./cub3d maps/default.cub"), 1);
	ft_init_game(&game, av[1]);
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
