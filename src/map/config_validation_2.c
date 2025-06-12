/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_validation_2.c                               :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:37:22 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/04/21 12:37:26 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_is_number(char *str)
{
	int		i;
	char	*str_trimed;

	i = 0;
	str_trimed = ft_strtrim(str, " ");
	if (!str_trimed || str_trimed[0] == '\0')
		return (0);
	while (str_trimed[i] != '\0')
	{
		if (str_trimed[i] < '0' || str_trimed[i] > '9')
		{
			free(str_trimed);
			return (0);
		}
		i++;
	}
	free(str_trimed);
	return (1);
}

int	ft_analyze_rgb_range(int r, int g, int b)
{
	if (r < 0 || r > 255)
		return (0);
	if (g < 0 || g > 255)
		return (0);
	if (b < 0 || b > 255)
		return (0);
	return (1);
}

int	ft_parse_rgb(char *rgb, int *r, int *g, int *b)
{
	char	**parts;

	if (ft_qtd_comma(rgb) != 2)
		return (0);
	parts = ft_split(rgb, ',');
	if (!ft_parse_rgb2(parts))
	{
		ft_free_matriz(parts);
		return (0);
	}
	*r = ft_atoi(parts[0]);
	*g = ft_atoi(parts[1]);
	*b = ft_atoi(parts[2]);
	ft_free_matriz(parts);
	if (!ft_analyze_rgb_range(*r, *g, *b))
		return (0);
	return (1);
}

void	ft_set_color2(t_rgb *element, int r, int g, int b)
{
	element->r = r;
	element->g = g;
	element->b = b;
}

void	ft_set_color(t_game *game, char **parts)
{
	int	r;
	int	g;
	int	b;

	if (!ft_parse_rgb(parts[1], &r, &g, &b))
	{
		ft_free_matriz(parts);
		ft_exit(game, -1, "Invalid RGB declaration");
	}
	if (ft_strncmp(parts[0], "F", 1) == 0 && parts[0][1] == '\0')
		ft_set_color2(&game->map.f, r, g, b);
	else if (ft_strncmp(parts[0], "C", 1) == 0 && parts[0][1] == '\0')
		ft_set_color2(&game->map.c, r, g, b);
	else
	{
		ft_free_matriz(parts);
		ft_exit(game, -1, "Invalid key config");
	}
}
