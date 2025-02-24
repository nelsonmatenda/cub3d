/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:42:39 by gudos-sa          #+#    #+#             */
/*   Updated: 2024/05/16 10:42:41 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;

	p = s;
	while (*p != '\0')
		p++;
	while (p >= s)
	{
		if (*p == (char)c)
			return ((char *)p);
		p--;
	}
	return (NULL);
}
