/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:31:14 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/04/21 14:48:28 by nfigueir         ###   ########.fr       */
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

	equivalent_x = 2 * x / WIDTH - 1;
	*ray_dir_x = game->player.dir_x + game->player.plane_x * equivalent_x;
	*ray_dir_y = game->player.dir_y + game->player.plane_y * equivalent_x;
}

int ft_wall_distance(t_game *game, float ray_dir_x, float ray_dir_y, int *side_impact)
{
	float delta_dist_x;
	float delta_dist_y;
	float side_dist_x;
	float side_dist_y;
	float distance;
	int side_direction_x;
	int side_direction_y;
	int current_cell_x;
	int current_cell_y;
	int find_wall;

	find_wall = 0;
	current_cell_x = game->player.x;
	current_cell_y = game->player.y;
	delta_dist_x = fabs(1 / ray_dir_x); // deves ler: com passos do tamanho do raio em x(ray_dir_x), quantos passos serão dados percorrer 1 unidade(que é o tamnho da celula)
	delta_dist_y = fabs(1 / ray_dir_y);

	if (ray_dir_x < 0)
	{
		side_direction_x = -1;
		side_dist_x = fabs((game->player.x - current_cell_x) / ray_dir_x);
	}
	else
	{
		side_direction_x = 1;
		side_dist_x = fabs((current_cell_x + 1 - game->player.x) / ray_dir_x);
	}

	if (ray_dir_y < 0)
	{
		side_direction_y = -1;
		side_dist_y = fabs((game->player.y - current_cell_y) / ray_dir_y);
	}
	else
	{
		side_direction_y = 1;
		side_dist_y = fabs((current_cell_y + 1 - game->player.y) / ray_dir_y);
	}

	while (!find_wall)
	{
		if (side_dist_x < side_dist_y)
		{
			current_cell_x +=side_direction_x;
			side_dist_x += delta_dist_x;
			*side_impact = 0;
		}
		else
		{
			current_cell_y += side_direction_y;
			side_dist_y += delta_dist_y;
			*side_impact = 1;
		}
		if (game->map.content[current_cell_x][current_cell_y] != '0')
			find_wall = 1;
	}
	if (*side_impact == 0)
		distance = side_dist_x - delta_dist_x;
	else
		distance = side_dist_y - delta_dist_y;
	return (int)(HEIGHT / distance);
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
	int pos_start_draw;
	int pos_end_draw;
	int wall_color;
	int y;

	ft_start_end_draw(&pos_start_draw, &pos_end_draw, wall_height);
	if (side_impact == 0)
		wall_color = 0xAAAAAA;
	else
		wall_color = 0xFFFFFF;
	y = 0;
	while (y < HEIGHT)
	{
		if (y < pos_start_draw)
			ft_set_image_pixel(game, x, y, 0x87CEEB);
		else if (y > pos_end_draw)
			ft_set_image_pixel(game, x, y, 0x333333);
		else
			ft_set_image_pixel(game, x, y, wall_color);
		y++;
	}
}

void	ft_raycasting(t_game *game)
{
	int x;
	float ray_dir_x;
	float ray_dir_y;
	float wall_height;
	int side_impact;

	x = 0;
	side_impact = 0;
	while (x < WIDTH)
	{
		ft_ray_direction(x, game, &ray_dir_x, &ray_dir_y);
		wall_height = ft_wall_distance(game, ray_dir_x, ray_dir_y, &side_impact);
		ft_render_column(game, wall_height, x, side_impact);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.ptr, 0, 0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_exit(NULL, MAP_ERR, \
						"Theres no maps: Try > ./cub3d maps/default.cub"), 1);
	ft_init_game_struct(&game);
	ft_read_file(av[1], &game);
	ft_process_map(&game);
	init_game(&game);
	mlx_hook(game.win, 2, 1L << 0, ft_key_press, &game.player);
	mlx_hook(game.win, 3, 1L << 1, ft_key_release, &game.player);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	ft_free_game(game);
	return (0);
}
