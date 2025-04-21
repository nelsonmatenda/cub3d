/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:27:12 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/03/21 13:27:14 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_append_character1(char **new_, char c)
{
	*new_ = (char *)malloc(sizeof(char) * 2);
	if (!(*new_))
		ft_error_read_file("Cannot read map.", NULL);
	(*new_)[0] = c;
	(*new_)[1] = '\0';
}
/*
static void ft_append_character2(char **new_, char c)
{
	int i;

	i = 0;
	*new_ = (char) 
}*/

char	*ft_append_character(char *line, char c)
{
	int		i;
	char	*new;

	new = NULL;
	if (line == NULL)
		ft_append_character1(&new, c);
	else
	{
		i = 0;
		new = (char *)malloc(sizeof(char) * (ft_strlen(line) + 2));
		if (!new)
			ft_error_read_file("Cannot read map.", line);
		while (line[i] != '\0')
		{
			new[i] = line[i];
			i++;
		}
		new[i] = c;
		new[i + 1] = '\0';
	}
	free(line);
	return (new);
}
