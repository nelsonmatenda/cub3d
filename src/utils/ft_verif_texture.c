/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <gudos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:51:36 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/06/13 12:29:59 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_verif_texture(t_game *g, char **parts)
{
	int	len;
	int	fd;

	if (!parts[1])
	{
		ft_free_matriz(parts);
		ft_exit(g, -1, "Invalid texture declaration.");
	}
	len = ft_strlen(parts[1]);
	if (len < 4 || ft_strncmp(parts[1] + len - 4, ".xpm",
			ft_strlen(".xpm")))
	{
		ft_free_matriz(parts);
		ft_exit(g, MAP_ERR, "Invalid type of sprite");
	}
	fd = open(parts[1], O_RDONLY);
	if (fd == -1)
	{
		ft_free_matriz(parts);
		ft_exit(g, -1, "Sprite doesn't exist.");
	}
	close(fd);
}
