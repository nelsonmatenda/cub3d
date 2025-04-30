/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_validation_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:37:22 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/04/21 12:37:26 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_set_texture(t_game *game, char **parts)
{
	if (ft_strncmp(parts[0], "NO", 2) == 0 && parts[0][2] == '\0')
		game->map.no = ft_strdup(parts[1]);
	else if (ft_strncmp(parts[0], "SO", 2) == 0 && parts[0][2] == '\0')
		game->map.so = ft_strdup(parts[1]);
	else if (ft_strncmp(parts[0], "WE", 2) == 0 && parts[0][2] == '\0')
		game->map.we = ft_strdup(parts[1]);
	else if (ft_strncmp(parts[0], "EA", 2) == 0 && parts[0][2] == '\0')
		game->map.ea = ft_strdup(parts[1]);
	else
	{
		ft_free_matriz(parts);
		ft_exit(game, -1, "Invalid key config");
	}
}

char	*ft_get_first_part(char *str)
{
	int		i;
	char	*part;

	i = 0;
	part = NULL;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == 9))
		i++;
	while (str[i] != '\0' && str[i] != 32 && str[i] != 9)
	{
		part = ft_append_character(part, str[i]);
		i++;
	}
	return (part);
}

char	*ft_get_rest_part(char *str)
{
	int		i;
	char	*part;

	i = 0;
	part = NULL;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == 9))
		i++;
	while (str[i] != '\0' && str[i] != 32 && str[i] != 9)
		i++;
	while (str[i] != '\0')
	{
		part = ft_append_character(part, str[i]);
		i++;
	}
	return (part);
}

char	**ft_split_first_and_rest(char *str)
{
	char	*part;
	char	**parts;
	char	*part_trimed;

	parts = NULL;
	part = ft_get_first_part(str);
	part_trimed = ft_strtrim(part, " ");
	free(part);
	if (part_trimed != NULL)
	{
		parts = ft_append_line(parts, part_trimed);
		free(part_trimed);
	}
	part = ft_get_rest_part(str);
	part_trimed = ft_strtrim(part, " ");
	free(part);
	if (part_trimed != NULL)
	{
		parts = ft_append_line(parts, part_trimed);
		free(part_trimed);
	}
	return (parts);
}

void	ft_parse_config_line(t_game *game)
{
	int		i;
	char	**parts;

	i = 0;
	while (game->map.configs[i] != NULL)
	{
		parts = ft_split_first_and_rest(game->map.configs[i]);
		ft_parse_config_line2(game, parts);
		if (ft_strlen(parts[0]) == 2)
			ft_set_texture(game, parts);
		else if (ft_strlen(parts[0]) == 1)
			ft_set_color(game, parts);
		else
		{
			ft_free_matriz(parts);
			ft_exit(game, -1, "Invalid keyword config");
		}
		i++;
		ft_free_matriz(parts);
	}
	if (i != 6)
		ft_exit(game, -1, "Invalid number of configuration lines");
}
