/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <gudos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:39:48 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/06/11 10:29:54 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_height_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

static int	ft_is_around_space(char **map_content, int row, int col)
{
	if (row == 0 || col == 0 || row == ft_height_map(map_content) - 1
		|| col == (int)ft_strlen(map_content[row]) - 1)
		return (1);
	if (!map_content[row - 1][col] || map_content[row - 1][col] == ' ')
		return (1);
	if (!map_content[row][col - 1] || map_content[row][col - 1] == ' ')
		return (1);
	if (!map_content[row][col + 1] || map_content[row][col + 1] == ' ')
		return (1);
	if (!map_content[row + 1][col] || map_content[row + 1][col] == ' ')
		return (1);
	return (0);
}

static int	ft_around1_2(char **map_content, int row, int col)
{
	char	*chars_to_analyze;

	chars_to_analyze = ft_strdup("0NSEW");
	if (ft_strchr(chars_to_analyze, map_content[row][col]))
	{
		if (ft_is_around_space(map_content, row, col))
		{
			free(chars_to_analyze);
			return (0);
		}
	}
	free(chars_to_analyze);
	return (1);
}

int	ft_around1(char **map_content)
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	while (map_content[row] != NULL)
	{
		col = 0;
		while (map_content[row][col] != '\0')
		{
			if (!ft_around1_2(map_content, row, col))
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}
