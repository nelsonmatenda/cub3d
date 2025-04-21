/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:31:14 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/04/21 14:48:28 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_get_map_e_config(char **file_content, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->map.configs = NULL;
	game->map.content = NULL;
	while (file_content[i] != NULL)
	{
		if (ft_strlen(file_content[i]) && j < 6)
		{
			game->map.configs = ft_append_line(game->map.configs,
					file_content[i]);
			j++;
		}
		else if (j == 6)
		{
			if (game->map.content != NULL || ft_strlen(file_content[i]))
				game->map.content = ft_append_line(game->map.content,
						file_content[i]);
		}
		i++;
	}
}

void	ft_process_map(char **file_content, t_game *game)
{
	ft_get_map_e_config(file_content, game);
	ft_parse_config_line(game);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_exit(NULL, MAP_ERR, \
						"Theres no maps: Try > ./cub3d maps/default.cub"), 1);
	
	ft_read_file(av[1], &game.file_content);
	
	ft_process_map(game.file_content, &game);
	
	init_game(&game);
	mlx_hook(game.win, 2, 1L << 0, ft_key_press, &game.player);
	mlx_hook(game.win, 3, 1L << 1, ft_key_release, &game.player);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
