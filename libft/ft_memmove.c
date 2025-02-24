/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:12:01 by gudos-sa          #+#    #+#             */
/*   Updated: 2024/05/15 14:12:05 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*aux;

	if (dest == NULL || src == NULL)
		return (NULL);
	aux = dest;
	if (src < dest && src + n > dest)
	{
		src += n;
		dest += n;
		while (n--)
			*(char *)--dest = *(char *)--src;
	}
	else
		while (n--)
			*(char *)dest++ = *(char *)src++;
	return (aux);
}
