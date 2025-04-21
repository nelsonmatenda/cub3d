/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 09:16:40 by nfigueir          #+#    #+#             */
/*   Updated: 2025/04/21 15:19:23 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	init_point(float points[3][2], int size)
{
	points[0][0] = size / 2;
	points[0][1] = 0;
	points[1][0] = -size / 2;
	points[1][1] = -size / 2;
	points[2][0] = -size / 2;
	points[2][1] = size / 2;
}

void	draw_player(t_player *player, int size, t_game *game)
{
	float	points[3][2];
	float	rotated[2];
	int		p_x[3];
	int		p_y[3];
	int		i;

	i = 0;
	init_point(points, size);
	while (i < 3)
	{
		rotated[0] = (cos(player->angle) * points[i][0]) - \
							(sin(player->angle) * points[i][1]);
		rotated[1] = (sin(player->angle) * points[i][0]) + \
							(cos(player->angle) * points[i][1]);
		p_x[i] = player->x + rotated[0];
		p_y[i] = player->y + rotated[1];
		i++;
	}
	draw_line((t_point){p_x[0], p_y[0]}, (t_point){p_x[1], p_y[1]}, game);
	draw_line((t_point){p_x[1], p_y[1]}, (t_point){p_x[2], p_y[2]}, game);
	draw_line((t_point){p_x[2], p_y[2]}, (t_point){p_x[0], p_y[0]}, game);
}
