/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_validation_3_rest.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:33:19 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/06/17 09:26:13 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_parse_rgb2(char **parts)
{
	char	*s[3];
	int		flag;
	int		i;

	i = -1;
	flag = 0;
	if (!parts || !parts[0] || !parts[1] || !parts[2]
		|| !ft_strlen(parts[0]) || !ft_strlen(parts[1]) || !ft_strlen(parts[2]))
		return (0);
	while (++i < 3)
		s[i] = ft_strtrim(parts[i], " ");
	if (ft_strlen(s[0]) > 3 || ft_strlen(s[1]) > 3
		|| ft_strlen(s[2]) > 3)
		flag = 1;
	if (!ft_is_number(s[0]) || !ft_is_number(s[1])
		|| !ft_is_number(s[2]))
		flag = 1;
	if (flag)
	{
		ft_free_array(s);
		return (0);
	}
	ft_free_array(s);
	return (1);
}

void	ft_parse_config_line2(t_game *game, char **parts)
{
	if (!parts || !parts[0] || !parts[1]
		|| !ft_strlen(parts[0]) || !ft_strlen(parts[1]))
	{
		ft_free_matriz(parts);
		ft_exit(game, -1, "Invalid config declaration");
	}
}

void	ft_split_first_and_rest_2(char ***parts, char *str)
{
	char	*part;
	char	*part_trimed;

	part_trimed = NULL;
	part = ft_get_first_part(str);
	if (part != NULL)
	{
		part_trimed = ft_strtrim(part, " ");
		free(part);
	}
	if (part_trimed != NULL)
	{
		*parts = ft_append_line(*parts, part_trimed);
		free(part_trimed);
	}
}

int	ft_qtd_comma(char *rgb)
{
	int		i;
	int		qtd_comma;

	i = 0;
	qtd_comma = 0;
	while (rgb[i] != '\0')
	{
		if (rgb[i] == ',')
			qtd_comma++;
		i++;
	}
	return (qtd_comma);
}
