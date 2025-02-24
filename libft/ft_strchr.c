/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:32:55 by gudos-sa          #+#    #+#             */
/*   Updated: 2024/05/16 10:32:58 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	conta;

	conta = 0;
	while (s[conta] != '\0')
	{
		if (s[conta] == (unsigned char)c)
			return ((char *)(s + conta));
		conta++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)(s + conta));
	return (NULL);
}
