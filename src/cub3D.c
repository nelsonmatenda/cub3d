/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:31:14 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/05/29 15:58:04 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_get_map_e_config(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->file_content[i] != NULL)
	{
		if (ft_strlen(game->file_content[i]) && j < 6)
		{
			game->map.configs = ft_append_line(game->map.configs,
					game->file_content[i]);
			j++;
		}
		else if (j == 6)
		{
			if (game->map.content != NULL || ft_strlen(game->file_content[i]))
				game->map.content = ft_append_line(game->map.content,
						game->file_content[i]);
		}
		i++;
	}
}

void	ft_process_map(t_game *game)
{
	ft_get_map_e_config(game);
	ft_parse_config_line(game);
	ft_parse_content_map(game);
}

void	ft_init_game_struct(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->file_content = NULL;
	game->img.ptr = NULL;
	game->img.data = NULL;
	game->map.configs = NULL;
	game->map.content = NULL;
	game->map.so = NULL;
	game->map.no = NULL;
	game->map.ea = NULL;
	game->map.we = NULL;
}

void	ft_ray_direction(int x, t_game *game, float *ray_dir_x, float *ray_dir_y)
{
	float	equivalent_x;

	equivalent_x = 2 * ((float)x / WIDTH) - 1;
	*ray_dir_x = game->player.dir.x + game->player.plane.x * equivalent_x;
	*ray_dir_y = game->player.dir.y + game->player.plane.y * equivalent_x;
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

void ft_set_side_dist(t_game *game, t_dda	*dda, t_vector ray)
{
	dda->step_x = 1;
	dda->step_y = 1;
	if (ray.x < 0)
	{
		dda->step_x = -1;
		dda->side_dist.x = fabs((game->player.pos.x - dda->current.x) / ray.x);
	}
	else
		dda->side_dist.x = fabs((dda->current.x + 1 - game->player.pos.x) / ray.x);
	if (ray.y < 0)
	{
		dda->step_y = -1;
		dda->side_dist.y = fabs((game->player.pos.y - dda->current.y) / ray.y);
	}
	else
		dda->side_dist.y = fabs((dda->current.y + 1 - game->player.pos.y) / ray.y);
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
		if (game->map.content[(int)dda->current.y][(int)dda->current.x] != '0')
			dda->is_wall = 1;
	}
	if (dda->side_impact == VERTICAL)
		dda->distance = dda->side_dist.x - dda->delta.x;
	else
		dda->distance = dda->side_dist.y - dda->delta.y;
}

int ft_wall_distance(t_game *game, t_vector ray, int *side_impact)
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
	return (int)(HEIGHT / dda.distance);
}

void ft_set_image_pixel(t_game *game, int x, int y, int wall_color)
{
	char *pixel;

	pixel = game->img.data + (y * game->img.size_line + x * (game->img.bpp/BITS));
	*(int *)pixel = wall_color;
}

void ft_start_end_draw(int *start_draw, int *end_draw, int wall_height)
{
	*start_draw = (HEIGHT/2) - (wall_height/2);
	*end_draw =  (HEIGHT/2) + (wall_height/2);
	if (*start_draw < 0)
		*start_draw = 0;
	if (*end_draw >= HEIGHT)
		*end_draw = HEIGHT - 1;
}

void ft_render_column(t_game *game, int wall_height, int x, int side_impact)
{
	int start;
	int end;
	int wall_color;
	int y;

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

void	ft_raycasting(t_game *game)
{
	int x;
	t_vector	ray;
	float wall_height;
	int side_impact;

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

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_exit(NULL, MAP_ERR,
						"Theres no maps: Try > ./cub3d maps/default.cub"), 1);

	ft_init_game_struct(&game);
	ft_read_file(av[1], &game);
	ft_process_map(&game);
	init_game(&game);
	mlx_hook(game.win, 2, 1L << 0, ft_key_press, &game.player);
	mlx_hook(game.win, 3, 1L << 1, ft_key_release, &game.player);
	ft_rotate_vector(&game.player.dir.x, &game.player.dir.y, PI / 4);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	ft_free_game(game);
	return (0);
}
