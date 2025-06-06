/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <gudos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:18:45 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/06/06 11:40:30 by gudos-sa         ###   ########.fr       */
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

void	ft_render_wall(t_game *game, float wall_distance, int x, int side_impact, t_vector ray)
{
	int	start;
	int	end;
	int	wall_color;
	int	y;
	t_vector	pixel;
	float dist;
	char *pixel_texture;

	ft_start_end_draw(&start, &end, (int)(HEIGHT / wall_distance));
	y = start;
	while (y <= end)
	{
		if (side_impact == HORIZONTAL)
			dist = game->player.pos.x + wall_distance * ray.x;
		else
			dist = game->player.pos.y + wall_distance * ray.y;
		dist -= floor(dist);
		pixel.x = dist * game->map.textures[3].width;
		pixel.y = (game->map.textures[3].height * (y - start)) / (int)(HEIGHT / wall_distance);
		pixel_texture = (char *)game->map.textures[3].image.data + ((int)pixel.y * game->map.textures[3].image.size_line) + ((int)pixel.x * (game->map.textures[3].image.bpp / 8));
		wall_color = *(int *)pixel_texture;
		ft_set_image_pixel(game, x, y, wall_color);
		y++;
	}
}

float	ft_wall_distance(t_game *game, t_vector ray, int *side_impact)
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
	return (dda.distance);
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
	float			wall_distance;
	t_vector		ray;

	x = 0;
	side_impact = 0;
	ft_draw_ceil_floor(game);
	while (x < WIDTH)
	{
		ft_ray_direction(x, game, &ray.x, &ray.y);
		wall_distance = ft_wall_distance(game, ray, &side_impact);
		ft_render_wall(game, wall_distance, x, side_impact, ray);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.ptr, 0, 0);
}
