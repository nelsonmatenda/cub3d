/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:39:08 by nfigueir          #+#    #+#             */
/*   Updated: 2025/04/16 12:44:01 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void init_game(t_game *game)
{
	game->mlx = mlx_init();
	if(!game->mlx)
		ft_exit(game, MLX_ERR, "Something wrong with mlx");
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Cub3d");
	game->img.ptr = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->img.data = mlx_get_data_addr(game->img.ptr, &game->img.bpp, \
								&game->img.size_line, &game->img.endian);
	mlx_put_image_to_window(game->mlx, game->win, game->img.ptr, 0, 0);
}
