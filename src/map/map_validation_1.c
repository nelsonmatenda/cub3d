/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <gudos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:36:47 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/06/11 10:32:10 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_has_player_start(char **map_content)
{
	int		found;
	int		col;
	int		row;
	char	*chars_player;

	found = 0;
	col = 0;
	row = 0;
	chars_player = ft_strdup("NSEW");
	while (map_content[row] != NULL)
	{
		col = 0;
		while (map_content[row][col] != '\0')
		{
			if (ft_strchr(chars_player, map_content[row][col]))
				found++;
			col++;
		}
		row++;
	}
	free(chars_player);
	return (found == 1);
}

static int	ft_only_valid_chars(char **map_content)
{
	int		col;
	int		row;
	char	*valid_chars;

	row = 0;
	valid_chars = ft_strdup(" 01NSEW");
	while (map_content[row] != NULL)
	{
		col = 0;
		while (map_content[row][col] != '\0')
		{
			if (!ft_strchr(valid_chars, map_content[row][col]))
			{
				free(valid_chars);
				return (0);
			}
			col++;
		}
		row++;
	}
	free(valid_chars);
	return (1);
}

void	ft_parse_content_map(t_game *game)
{
	if (!ft_only_valid_chars(game->map.content))
		ft_exit(game, -1, "Invalid character in map");
	if (!ft_has_player_start(game->map.content))
		ft_exit(game, -1,
			"There must be one character to represent the player");
	if (!ft_around1(game->map.content))
		ft_exit(game, -1, "The map must be around 1 \
			and must not have empty space inside");
}
