/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <gudos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:39:08 by nfigueir          #+#    #+#             */
/*   Updated: 2025/06/06 09:49:28 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
				game->player.pos.x = j + 0.5;
				game->player.pos.y = i + 0.5;
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

	player_x = game->player.pos.x;
	player_y = game->player.pos.y;
	char_id = game->map.content[player_y][player_x];
	game->player.dir.x = 0;
	game->player.dir.y = 0;
	if (char_id == 'N')
		game->player.dir.y = -1;
	else if (char_id == 'S')
		game->player.dir.y = 1;
	else if (char_id == 'E')
		game->player.dir.x = 1;
	else if (char_id == 'W')
		game->player.dir.x = -1;
}

void	ft_set_plane(t_game *game)
{
	int		player_x;
	int		player_y;
	char	char_id;

	player_x = game->player.pos.x;
	player_y = game->player.pos.y;
	char_id = game->map.content[player_y][player_x];
	game->player.plane.x = 0;
	game->player.plane.y = 0;
	if (char_id == 'N')
		game->player.plane.x = 0.66;
	else if (char_id == 'S')
		game->player.plane.x = -0.66;
	else if (char_id == 'E')
		game->player.plane.y = 0.66;
	else if (char_id == 'W')
		game->player.plane.y = -0.66;
}

void	init_player(t_game *game)
{
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
	if (!game->win)
		ft_exit(game, MLX_ERR, "in mlx_new_window");
	game->img.ptr = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img.ptr)
		ft_exit(game, MLX_ERR, "in mlx_new_image");
	game->img.data = mlx_get_data_addr(game->img.ptr, &game->img.bpp, \
								&game->img.size_line, &game->img.endian);
}
