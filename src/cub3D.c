/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <gudos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:31:14 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/05/29 11:30:23 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_get_map_e_config(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->file_content[i] != NULL)
	{
		if (ft_strlen(game->file_content[i]) && j < 6)
		{
			game->map.configs = ft_append_line(game->map.configs,
					game->file_content[i]);
			j++;
		}
		else if (j == 6)
		{
			if (game->map.content != NULL || ft_strlen(game->file_content[i]))
				game->map.content = ft_append_line(game->map.content,
						game->file_content[i]);
		}
		i++;
	}
}

void	ft_process_map(t_game *game)
{
	ft_get_map_e_config(game);
	ft_parse_config_line(game);
	ft_parse_content_map(game);
}

void	ft_init_game_struct(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->file_content = NULL;
	game->img.ptr = NULL;
	game->img.data = NULL;
	game->map.configs = NULL;
	game->map.content = NULL;
	game->map.so = NULL;
	game->map.no = NULL;
	game->map.ea = NULL;
	game->map.we = NULL;
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_exit(NULL, MAP_ERR,
				"Theres no maps: Try > ./cub3d maps/default.cub"), 1);
	ft_init_game_struct(&game);
	ft_read_file(av[1], &game);
	ft_process_map(&game);
	init_game(&game);
	mlx_hook(game.win, 2, 1L << 0, ft_key_press, &game.player);
	mlx_hook(game.win, 3, 1L << 1, ft_key_release, &game.player);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	ft_free_game(game);
	return (0);
}
