/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:31:14 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/06/10 12:20:48 by nfigueir         ###   ########.fr       */
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
	game->delta_time = 0;
}

void	ft_load_texture_structs(t_game *game)
{
	int	i;

	game->map.textures[0].image.ptr = mlx_xpm_file_to_image(game->mlx,
			game->map.no, &game->map.textures[0].width,
			&game->map.textures[0].height);
	game->map.textures[1].image.ptr = mlx_xpm_file_to_image(game->mlx,
			game->map.so, &game->map.textures[1].width,
			&game->map.textures[1].height);
	game->map.textures[2].image.ptr = mlx_xpm_file_to_image(game->mlx,
			game->map.ea, &game->map.textures[2].width,
			&game->map.textures[2].height);
	game->map.textures[3].image.ptr = mlx_xpm_file_to_image(game->mlx,
			game->map.we, &game->map.textures[3].width,
			&game->map.textures[3].height);
	i = 0;
	while (i < 4)
	{
		game->map.textures[i].image.data = \
		mlx_get_data_addr(game->map.textures[i].image.ptr,
				&game->map.textures[i].image.bpp,
				&game->map.textures[i].image.size_line,
				&game->map.textures[i].image.endian);
		i++;
	}
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
	ft_load_texture_structs(&game);
	mlx_hook(game.win, 17, 0, ft_close_window, &game);
	mlx_hook(game.win, 2, 1L << 0, ft_key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, ft_key_release, &game.player);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	ft_free_game(game);
	return (0);
}
