/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:20:06 by nfigueir          #+#    #+#             */
/*   Updated: 2025/04/16 12:56:53 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void draw_square(int x, int y, int size, int color, t_game *game)
{
	int i = -1;
	while (++i < size)
		put_pixel(game, color, x + i, y);
	i = -1;
	while (++i < size)
		put_pixel(game, color, x, y + i);
	i = -1;
	while (++i < size)
		put_pixel(game, color, x + size, y + i);
	i = -1;
	while (++i < size)
		put_pixel(game, color, x + i, y + size);
}

void	draw_map(t_game *game)
{
	char	**map;
	int		y;
	int		x;

	map = game->map;
	y = -1;
	while(map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '1')
				draw_square((x * BLOCK), (y * BLOCK), BLOCK, 0x0000FF, game);
		}
	}
}
