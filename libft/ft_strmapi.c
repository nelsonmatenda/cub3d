/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:26:29 by gudos-sa          #+#    #+#             */
/*   Updated: 2024/05/22 12:41:45 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	i;

	if (!s || !f)
		return (NULL);
	new = ft_strdup(s);
	if (!new)
		return (NULL);
	i = 0;
	while (new[i])
	{
		new[i] = (*f)(i, new[i]);
		i++;
	}
	return (new);
}
