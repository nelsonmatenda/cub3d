/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:37:22 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/04/21 12:37:26 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void	ft_set_texture(t_game *game, char *key_config, char *path)
{
	if (ft_strncmp(key_config, "NO", 2) == 0 && key_config[2] == '\0')
		game->map.no = ft_strdup(path);
	else if (ft_strncmp(key_config, "SO", 2) == 0 && key_config[2] == '\0')
		game->map.so = ft_strdup(path);
	else if (ft_strncmp(key_config, "WE", 2) == 0 && key_config[2] == '\0')
		game->map.we = ft_strdup(path);
	else if (ft_strncmp(key_config, "EA", 2) == 0 && key_config[2] == '\0')
		game->map.ea = ft_strdup(path);
	else
		ft_error("Invalid key config");
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

	parts = NULL;
	part = ft_get_first_part(str);
	if (part != NULL)
		parts = ft_append_line(parts, part);
	part = ft_get_rest_part(str);
	if (part != NULL)
		parts = ft_append_line(parts, part);
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
		if (!parts || !parts[0] || !parts[1])
			ft_error("Invalid config declaration");
		if (ft_strlen(parts[0]) == 2)
			ft_set_texture(game, parts[0], parts[1]);
		else if(ft_strlen(parts[0]) == 1)
			ft_set_color(game, parts[0], parts[1]);
		else
			ft_error("Invalid keyword config");

		i++;
	}
	if (i != 6)
		ft_error("Invalid number of configuration lines");
}