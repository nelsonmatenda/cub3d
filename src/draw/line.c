/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 09:16:40 by nfigueir          #+#    #+#             */
/*   Updated: 2025/04/21 14:59:22 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	define_direction(t_point a, t_point b, int *dir_x, int *dir_y)
{
	if (a.x < b.x)
		*dir_x = 1;
	else
		*dir_x = -1;
	if (a.y < b.y)
		*dir_y = 1;
	else
		*dir_y = -1;
}

void	update_pos(int *err, int *p, int delta, int dir)
{
	*err += delta;
	*p += dir;
}

void	draw_line(t_point a, t_point b, t_game *game)
{
	int	dx;
	int	dy;
	int	dir[2];
	int	err[2];

	dx = abs(b.x - a.x);
	dy = -abs(b.y - a.y);
	define_direction(a, b, &dir[0], &dir[1]);
	err[0] = dx + dy;
	while (1)
	{
		put_pixel(game, 0x00FF00, a.x, a.y);
		if (a.x == b.x && a.y == b.y)
			break ;
		err[1] = 2 * err[0];
		if (err[1] >= dy)
			update_pos(&err[0], &a.x, dy, dir[0]);
		if (err[1] <= dx)
			update_pos(&err[0], &a.y, dx, dir[1]);
	}
}
