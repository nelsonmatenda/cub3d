/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:51:11 by nfigueir          #+#    #+#             */
/*   Updated: 2025/06/10 13:04:33 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_render_wall_2(t_game game, t_group_r group, \
							t_group_rw *vars, int *id_texture)
{
	if (group.side_impact == HORIZONTAL)
	{
		vars->dist = game.player.pos.x + group.wall_distance * group.ray.x;
		if (group.ray.y > 0)
			*id_texture = 0;
		else if (group.ray.y < 0)
			*id_texture = 1;
	}
	else
	{
		vars->dist = game.player.pos.y + group.wall_distance * group.ray.y;
		if (group.ray.x > 0)
			*id_texture = 3;
		else if (group.ray.x < 0)
			*id_texture = 2;
	}
}

char	*ft_pixer_in_texture(t_game *g, t_group_rw	vars, int id_texture)
{
	char	*pixel_texture;

	pixel_texture = (char *)g->map.textures[id_texture].image.data + \
		((int)vars.pixel.y * g->map.textures[id_texture].image.size_line) \
		+ ((int)vars.pixel.x * (g->map.textures[id_texture].image.bpp / 8));
	return (pixel_texture);
}

void	ft_render_wall(t_game *game, t_group_r group)
{
	t_group_rw	vars;
	int			id_texture;
	float		acrescimo;

	ft_start_end_draw(&vars.start, &vars.end, \
						(int)(HEIGHT / group.wall_distance));
	vars.y = vars.start;
	acrescimo = 0;
	if (vars.start == 0)
		acrescimo = (int)(HEIGHT / group.wall_distance) / 2 - HEIGHT / 2;
	ft_render_wall_2(*game, group, &vars, &id_texture);
	vars.dist -= floor(vars.dist);
	while (vars.y <= vars.end)
	{
		vars.pixel.x = vars.dist * game->map.textures[id_texture].width;
		vars.pixel.y = (game->map.textures[id_texture].height * \
							((vars.y + (int)acrescimo) - vars.start)) / \
							(int)(HEIGHT / group.wall_distance);
		vars.pixel_texture = ft_pixer_in_texture(game, vars, id_texture);
		vars.wall_color = *(int *)vars.pixel_texture;
		ft_set_image_pixel(game, group.x, vars.y, vars.wall_color);
		vars.y++;
	}
}
