/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <gudos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:18:45 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/06/10 11:53:57 by gudos-sa         ###   ########.fr       */
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

void	ft_render_wall_2(t_game game, t_group_r group, t_group_rw *vars, int *id_texture)
{
	if (group.side_impact == HORIZONTAL)
	{
		vars->dist = game.player.pos.x + group.wall_distance * group.ray.x;
		if (group.ray.y > 0)
			*id_texture = 0;
		else if(group.ray.y < 0)
			*id_texture = 1;
	}
	else
	{
		vars->dist = game.player.pos.y + group.wall_distance * group.ray.y;
		if (group.ray.x > 0)
			*id_texture = 3;
		else if( group.ray.x < 0)
			*id_texture = 2;
	}
}

void	ft_render_wall(t_game *game, t_group_r group)
{
	t_group_rw vars;
	int id_texture;
	float acrescimo;

	ft_start_end_draw(&vars.start, &vars.end, (int)(HEIGHT / group.wall_distance));
	vars.y = vars.start;
	acrescimo = 0;
	if (vars.start == 0)
		acrescimo = (int)(HEIGHT / group.wall_distance)/2 - HEIGHT/2;
	ft_render_wall_2(*game, group, &vars, &id_texture);
	vars.dist -= floor(vars.dist);
	while (vars.y <= vars.end)
	{
		vars.pixel.x = vars.dist * game->map.textures[id_texture].width;

		vars.pixel.y = (game->map.textures[id_texture].height * ((vars.y + (int)acrescimo) - vars.start)) / (int)(HEIGHT / group.wall_distance);

		vars.pixel_texture = (char *)game->map.textures[id_texture].image.data + ((int)vars.pixel.y * game->map.textures[id_texture].image.size_line) + ((int)vars.pixel.x * (game->map.textures[id_texture].image.bpp / 8));
		vars.wall_color = *(int *)vars.pixel_texture;
		ft_set_image_pixel(game, group.x, vars.y, vars.wall_color);
		vars.y++;
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

void	ft_ray_direction(t_game *game,t_group_r *group)
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
