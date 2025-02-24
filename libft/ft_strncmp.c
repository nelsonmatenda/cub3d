/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:59:25 by gudos-sa          #+#    #+#             */
/*   Updated: 2024/05/16 17:16:23 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	contador;

	contador = 0;
	while (contador < n)
	{
		if (s1[contador] != s2[contador])
			return (s1[contador] - s2[contador]);
		if (s1[contador] == '\0')
			return (0);
		contador++;
	}
	return (0);
}
