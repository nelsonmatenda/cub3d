/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <gudos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:48:08 by nfigueir          #+#    #+#             */
/*   Updated: 2025/06/06 14:39:41 by gudos-sa         ###   ########.fr       */
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
	ft_rotate(&game->player.dir.x, &game->player.dir.y, 0.02);
	ft_rotate(&game->player.plane.x, &game->player.plane.y, 0.02);
	clean_image(game);
	ft_raycasting(game);
	return (0);
}
