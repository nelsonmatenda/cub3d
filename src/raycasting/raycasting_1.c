/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:18:45 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/06/10 12:52:23 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_draw_ceil_floor(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT / 2)
		{
			ft_set_image_pixel(game, x, y, 0x87CEEB);
			y++;
		}
		x++;
	}
	x = 0;
	while (x < WIDTH)
	{
		y = HEIGHT / 2;
		while (y < HEIGHT)
		{
			ft_set_image_pixel(game, x, y, 0x333333);
			y++;
		}
		x++;
	}
}

float	ft_wall_distance(t_game *game, t_group_r *group)
{
	t_dda	dda;

	dda.is_wall = 0;
	dda.side_impact = 0;
	dda.current.x = floor(game->player.pos.x);
	dda.current.y = floor(game->player.pos.y);
	ft_set_delta(group->ray, &dda.delta);
	ft_set_side_dist(game, &dda, group->ray);
	ft_set_distance(game, &dda);
	group->side_impact = dda.side_impact;
	return (dda.distance);
}

void	ft_ray_direction(t_game *game, t_group_r *group)
{
	float	equivalent_x;

	equivalent_x = 2 * ((float)group->x / WIDTH) - 1;
	group->ray.x = game->player.dir.x + game->player.plane.x * equivalent_x;
	group->ray.y = game->player.dir.y + game->player.plane.y * equivalent_x;
}

void	ft_raycasting(t_game *game)
{
	t_group_r	group;

	group.x = 0;
	group.side_impact = 0;
	ft_draw_ceil_floor(game);
	while (group.x < WIDTH)
	{
		ft_ray_direction(game, &group);
		group.wall_distance = ft_wall_distance(game, &group);
		ft_render_wall(game, group);
		group.x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.ptr, 0, 0);
}
