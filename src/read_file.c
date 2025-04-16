/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:47:42 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/03/21 10:47:44 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_append_line1(char ***new_, char *line)
{
	*new_ = (char **)malloc(sizeof(char *) * 2);
	if (!(*new_))
		ft_error("Cannot read map.");
	(*new_)[0] = line;
	(*new_)[1] = NULL;
}

static void	ft_append_line2(char ***new_, char *line, char **m, int i)
{
	int	j;

	j = 0;
	*new_ = (char **)malloc(sizeof(char *) * (i + 1));
	if (!(*new_))
		ft_error("Cannot read map.");
	while (j < i - 1)
	{
		(*new_)[j] = m[j];
		j++;
	}
	(*new_)[j] = line;
	(*new_)[j + 1] = NULL;
}

char	**ft_append_line(char **map, char *line)
{
	char			**novo;
	static int		i = 0;

	novo = NULL;
	if (map == NULL)
	{
		ft_append_line1(&novo, line);
		i = 2;
	}
	else
	{
		ft_append_line2(&novo, line, map, (int)i);
		i++;
	}
	free(map);
	return (novo);
}

void	ft_read_file(char *map_path, char ***file_content)
{
	int			new_line_end;
	int			fd;
	char		*line;

	new_line_end = 1;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		ft_error("Cannot read map.");
	line = ft_get_next_line(fd, &new_line_end);
	while (line != NULL)
	{
		*file_content = ft_append_line(*file_content, line);
		line = ft_get_next_line(fd, &new_line_end);
	}
	close(fd);
}
