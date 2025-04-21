/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_validation2.c                                :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:37:22 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/04/21 12:37:26 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	str = ft_strtrim(str, " ");
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	free(str);
	return (1);
}

void	ft_analyze_rgb_range(int r, int g, int b)
{
	if (r < 0 || r > 255)
		ft_error("Invalid RGB value");
	if (g < 0 || g > 255)
		ft_error("Invalid RGB value");
	if (b < 0 || b > 255)
		ft_error("Invalid RGB value");
}

void	ft_parse_rgb(char *rgb, int *r, int *g, int *b)
{
	int		i;
	int		qtd_comma;
	char	**parts;

	i = 0;
	qtd_comma = 0;
	while (rgb[i] != '\0')
	{
		if (rgb[i] == ',')
			qtd_comma++;
		i++;
	}
	if (qtd_comma != 2)
		ft_error("Invalid RGB declaration");
	parts = ft_split(rgb, ',');
	if (!ft_strlen(parts[0]) || !ft_strlen(parts[1]) || !ft_strlen(parts[2]))
		ft_error("Invalid RGB declaration");
	if (!ft_is_number(parts[0]) || !ft_is_number(parts[1])
		|| !ft_is_number(parts[2]))
		ft_error("Invalid RGB value declaration");
	*r = ft_atoi(parts[0]);
	*g = ft_atoi(parts[1]);
	*b = ft_atoi(parts[2]);
	ft_analyze_rgb_range(*r, *g, *b);
}

void	ft_set_color(t_game *game, char *key_config, char *rgb)
{
	int	r;
	int	g;
	int	b;

	ft_parse_rgb(rgb, &r, &g, &b);
	if (ft_strncmp(key_config, "F", 1) == 0 && key_config[1] == '\0')
	{
		game->map.f.r = r;
		game->map.f.g = g;
		game->map.f.b = b;
	}
	else if (ft_strncmp(key_config, "C", 1) == 0 && key_config[1] == '\0')
	{
		game->map.c.r = r;
		game->map.c.g = g;
		game->map.c.b = b;
	}
	else
		ft_error("Invalid key config");
}