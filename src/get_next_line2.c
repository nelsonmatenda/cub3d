/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:27:12 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/04/21 14:52:29 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_putin_line1(char **new_, char c)
{
	*new_ = (char *)malloc(sizeof(char) * 2);
	if (!(*new_))
		ft_error("Cannot read map.");
	(*new_)[0] = c;
	(*new_)[1] = '\0';
}

char	*ft_putin_line(char *line, char c)
{
	int		i;
	char	*new;

	new = NULL;
	if (line == NULL)
		ft_putin_line1(&new, c);
	else
	{
		i = 0;
		new = (char *)malloc(sizeof(char) * (ft_strlen(line) + 2));
		if (!new)
			ft_error("Cannot read map.");
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
