/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <gudos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:23:21 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/06/03 10:02:53 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_set_image_pixel(t_game *game, int x, int y, int wall_color)
{
	char	*pixel;

	pixel = game->img.data
		+ (y * game->img.size_line + x * (game->img.bpp / BITS));
	*(int *)pixel = wall_color;
}

void	ft_start_end_draw(int *start_draw, int *end_draw, int wall_height)
{
	*start_draw = (HEIGHT / 2) - (wall_height / 2);
	*end_draw = (HEIGHT / 2) + (wall_height / 2);
	if (*start_draw < 0)
		*start_draw = 0;
	if (*end_draw >= HEIGHT)
		*end_draw = HEIGHT - 1;
}

void	ft_set_delta(t_vector ray, t_vector *delta)
{
	if (ray.x == 0)
	{
		delta->x = 0;
		delta->y = 1;
	}
	else
		delta->x = fabs(1 / ray.x);
	if (ray.y == 0)
	{
		delta->y = 0;
		delta->x = 1;
	}
	else
		delta->y = fabs(1 / ray.y);
}

void	ft_set_side_dist(t_game *game, t_dda	*dda, t_vector ray)
{
	dda->step_x = 1;
	dda->step_y = 1;
	if (ray.x < 0)
	{
		dda->step_x = -1;
		dda->side_dist.x = fabs((game->player.pos.x - dda->current.x) / ray.x);
	}
	else
		dda->side_dist.x = fabs((dda->current.x + 1
					- game->player.pos.x) / ray.x);
	if (ray.y < 0)
	{
		dda->step_y = -1;
		dda->side_dist.y = fabs((game->player.pos.y - dda->current.y) / ray.y);
	}
	else
		dda->side_dist.y = fabs((dda->current.y + 1
					- game->player.pos.y) / ray.y);
}

void	ft_set_distance(t_game *game, t_dda *dda)
{
	while (!dda->is_wall)
	{
		if (dda->side_dist.x < dda->side_dist.y)
		{
			dda->current.x += dda->step_x;
			dda->side_dist.x += dda->delta.x;
			dda->side_impact = VERTICAL;
		}
		else
		{
			dda->current.y += dda->step_y;
			dda->side_dist.y += dda->delta.y;
			dda->side_impact = HORIZONTAL;
		}
		if (dda->current.y >= 0 &&	dda->current.x >= 0 && \
			game->map.content[(int)dda->current.y][(int)dda->current.x] && \
			game->map.content[(int)dda->current.y][(int)dda->current.x] == '1')
			dda->is_wall = 1;
	}
	if (dda->side_impact == VERTICAL)
		dda->distance = dda->side_dist.x - dda->delta.x;
	else
		dda->distance = dda->side_dist.y - dda->delta.y;
}
