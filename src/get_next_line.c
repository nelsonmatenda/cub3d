/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:29:28 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/04/21 14:51:54 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	ft_read_to_buf(int fd, char *buf, int *i)
{
	int	qtd_read;

	qtd_read = read(fd, buf, BUFFER_SIZE);
	if (qtd_read == -1)
		ft_exit(NULL, MALLOC_ERR, "Error\nCannot read map");
	*i = 0;
	return (qtd_read);
}

static char	*ft_case_zero(char *line, int *new_line_end)
{
	if (line == NULL && *new_line_end == 1)
	{
		*new_line_end = 0;
		line = (char *)malloc(sizeof(char));
		if (!line)
			ft_error("Cannot read map.");
		line[0] = '\0';
	}
	*new_line_end = 0;
	return (line);
}

static int	ft_build_line(int *i, int q, char *b, char **l)
{
	while (*i < q)
	{
		if (b[*i] == '\n')
		{
			(*i)++;
			if (*l == NULL)
			{
				*l = (char *)malloc(sizeof(char));
				if (!(*l))
					ft_exit(NULL, MALLOC_ERR, "Error\nCannot read map");
				(*l)[0] = '\0';
			}
			return (1);
		}
		*l = ft_append_character(*l, b[*i]);
		(*i)++;
	}
	return (0);
}

char	*ft_get_next_line(int fd, int *new_line_end)
{
	char				*line;
	static int			index_read = 0;
	static int			qtd_read = 0;
	static char			buf[BUFFER_SIZE];

	line = NULL;
	while (1)
	{
		if (index_read >= qtd_read)
		{
			qtd_read = ft_read_to_buf(fd, buf, &index_read);
			if (qtd_read == 0)
				return (ft_case_zero(line, new_line_end));
		}
		if (ft_build_line(&index_read, qtd_read, buf, &line))
			return (line);
	}
}
