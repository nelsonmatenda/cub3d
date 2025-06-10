/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:48:08 by nfigueir          #+#    #+#             */
/*   Updated: 2025/06/10 12:20:03 by nfigueir         ###   ########.fr       */
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
	double	start_time;
	double	end_time;

	ft_move_player(&game->player, game->delta_time, game->map.content);
	start_time = get_time_in_milliseconds();
	clean_image(game);
	ft_raycasting(game);
	end_time = get_time_in_milliseconds();
	game->delta_time = end_time - start_time;
	return (0);
}

int	ft_close_window(t_game *game)
{
	return (ft_exit(game, 1, "YOU END THE GAME"));
}
