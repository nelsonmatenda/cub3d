/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:48:08 by nfigueir          #+#    #+#             */
/*   Updated: 2025/04/21 15:19:58 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	clean_image(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			put_pixel(game, 0, x, y);
	}
}

int	game_loop(t_game *game)
{
	move_player(&game->player);
	clean_image(game);
	draw_map(game);
	draw_player(&game->player, 10, game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.ptr, 0, 0);
	return (0);
}
