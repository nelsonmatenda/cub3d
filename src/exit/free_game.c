/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <gudos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:50:32 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/06/10 15:22:33 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_free_matriz(char **matriz)
{
	int	i;

	if (!matriz)
		return ;
	i = 0;
	while (matriz[i])
	{
		free(matriz[i]);
		i++;
	}
	free(matriz);
}

void	ft_free_t_map(t_map map)
{
	ft_free_matriz(map.configs);
	ft_free_matriz(map.content);
	if (map.no)
		free(map.no);
	if (map.so)
		free(map.so);
	if (map.ea)
		free(map.ea);
	if (map.we)
		free(map.we);
}

void	ft_free_texture(t_game g, t_texture texture[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (texture[i].image.ptr)
			mlx_destroy_image(g.mlx, texture[i].image.ptr);
		i++;
	}
}

void	ft_free_game(t_game game)
{
	ft_free_t_map(game.map);
	ft_free_matriz(game.file_content);
	ft_free_texture(game, game.map.textures);
	if (game.img.ptr)
		mlx_destroy_image(game.mlx, game.img.ptr);
	if (game.win)
		mlx_destroy_window(game.mlx, game.win);
	if (game.mlx)
	{
		mlx_destroy_display(game.mlx);
		free(game.mlx);
	}
}
