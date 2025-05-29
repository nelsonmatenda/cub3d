/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <gudos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:18:45 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/05/29 11:31:44 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_render_column(t_game *game, int wall_height, int x, int side_impact)
{
	int	start;
	int	end;
	int	wall_color;
	int	y;

	ft_start_end_draw(&start, &end, wall_height);
	if (side_impact == 0)
		wall_color = 0xAAAAAA;
	else
		wall_color = 0xFFFFFF;
	y = 0;
	while (y < HEIGHT)
	{
		if (y < start)
			ft_set_image_pixel(game, x, y, 0x87CEEB);
		else if (y > end)
			ft_set_image_pixel(game, x, y, 0x333333);
		else
			ft_set_image_pixel(game, x, y, wall_color);
		y++;
	}
}

int	ft_wall_distance(t_game *game, t_vector ray, int *side_impact)
{
	t_dda	dda;

	dda.is_wall = 0;
	dda.side_impact = 0;
	dda.current.x = floor(game->player.pos.x);
	dda.current.y = floor(game->player.pos.y);
	ft_set_delta(ray, &dda.delta);
	ft_set_side_dist(game, &dda, ray);
	ft_set_distance(game, &dda);
	*side_impact = dda.side_impact;
	return ((int)(HEIGHT / dda.distance));
}

void	ft_ray_direction(int x, t_game *game,
	float *ray_dir_x, float *ray_dir_y)
{
	float	equivalent_x;

	equivalent_x = 2 * ((float)x / WIDTH) - 1;
	*ray_dir_x = game->player.dir.x + game->player.plane.x * equivalent_x;
	*ray_dir_y = game->player.dir.y + game->player.plane.y * equivalent_x;
}

void	ft_raycasting(t_game *game)
{
	int				x;
	int				side_impact;
	float			wall_height;
	t_vector		ray;

	x = 0;
	side_impact = 0;
	while (x < WIDTH)
	{
		ft_ray_direction(x, game, &ray.x, &ray.y);
		wall_height = ft_wall_distance(game, ray, &side_impact);
		ft_render_column(game, wall_height, x, side_impact);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.ptr, 0, 0);
}
