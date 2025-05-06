/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:39:08 by nfigueir          #+#    #+#             */
/*   Updated: 2025/04/21 14:54:45 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_get_player_pos(t_game *game)
{
	int		i;
	int		j;
	char	*valid_chars;

	valid_chars = ft_strdup("NSEW");
	i = 0;
	while (game->map.content[i] != NULL)
	{
		j = 0;
		while (game->map.content[i][j] != '\0')
		{
			if (ft_strchr(valid_chars, game->map.content[i][j]))
			{
				game->player.x = i;
				game->player.y = j;
				free(valid_chars);
				return ;
			}
			j++;
		}
		i++;
	}
	free(valid_chars);
}

void	ft_set_dir_player(t_game *game)
{
	int		player_x;
	int		player_y;
	char	char_id;

	player_x = game->player.x;
	player_y = game->player.y;
	char_id = game->map.content[player_x][player_y];
	game->player.dir_x = 0;
	game->player.dir_y = 0;
	if (char_id == 'N')
		game->player.dir_y = -1;
	else if (char_id == 'S')
		game->player.dir_y = 1;
	else if (char_id == 'E')
		game->player.dir_x = 1;
	else if (char_id == 'W')
		game->player.dir_x = -1;
}

void	ft_set_plane(t_game *game)
{
	int		player_x;
	int		player_y;
	char	char_id;

	player_x = game->player.x;
	player_y = game->player.y;
	char_id = game->map.content[player_x][player_y];
	game->player.plane_x = 0;
	game->player.plane_y = 0;
	if (char_id == 'N')
		game->player.plane_x = -0.66;
	else if (char_id == 'S')
		game->player.plane_x = 0.66;
	else if (char_id == 'E')
		game->player.plane_y = -0.66;
	else if (char_id == 'W')
		game->player.plane_y = 0.66;
}

void	init_player(t_game *game)
{
	game->player.angle = -PI / 2;
	game->player.key_up = false;
	game->player.key_down = false;
	game->player.key_left = false;
	game->player.key_right = false;
	game->player.right_rotate = false;
	game->player.left_rotate = false;
	ft_get_player_pos(game);
	ft_set_dir_player(game);
	ft_set_plane(game);
}

void	init_game(t_game *game)
{
	init_player(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_exit(game, MLX_ERR, "Something wrong with mlx");
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Cub3d");
	game->img.ptr = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->img.data = mlx_get_data_addr(game->img.ptr, &game->img.bpp, \
								&game->img.size_line, &game->img.endian);
	mlx_put_image_to_window(game->mlx, game->win, game->img.ptr, 0, 0);
}
