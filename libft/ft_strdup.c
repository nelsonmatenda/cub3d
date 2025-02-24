/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 09:43:26 by gudos-sa          #+#    #+#             */
/*   Updated: 2024/05/20 09:43:28 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*new;

	len = ft_strlen(s);
	new = malloc((sizeof(char) * (len + 1)));
	if (!new)
		return (0);
	ft_strlcpy(new, s, (len + 1));
	return (new);
}
