/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_xpm_to_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:01:08 by nfigueir          #+#    #+#             */
/*   Updated: 2025/06/12 13:01:34 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_xpm_to_img(t_game *game)
{
	game->map.textures[0].image.ptr = mlx_xpm_file_to_image(game->mlx,
			game->map.no, &game->map.textures[0].width,
			&game->map.textures[0].height);
	game->map.textures[1].image.ptr = mlx_xpm_file_to_image(game->mlx,
			game->map.so, &game->map.textures[1].width,
			&game->map.textures[1].height);
	game->map.textures[2].image.ptr = mlx_xpm_file_to_image(game->mlx,
			game->map.ea, &game->map.textures[2].width,
			&game->map.textures[2].height);
	game->map.textures[3].image.ptr = mlx_xpm_file_to_image(game->mlx,
			game->map.we, &game->map.textures[3].width,
			&game->map.textures[3].height);
}
