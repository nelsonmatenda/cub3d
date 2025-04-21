/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:34:26 by nfigueir          #+#    #+#             */
/*   Updated: 2025/04/16 12:49:57 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	put_pixel(t_game *game, int color, int x, int y)
{
	int	pixel_pos;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	pixel_pos = (y * game->img.size_line) + \
					(x * (game->img.bpp / BITS));
	game->img.data[pixel_pos] = (char)color & 0xFF;
	game->img.data[pixel_pos + 1] = (color >> BITS) & 0xFF;
	game->img.data[pixel_pos + 2] = (color >> (2 * BITS)) & 0xFF;
}
