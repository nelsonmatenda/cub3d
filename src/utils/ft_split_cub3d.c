/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cub3d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 08:36:58 by nfigueir          #+#    #+#             */
/*   Updated: 2025/06/17 08:57:23 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_words(char const *s, char c)
{
	size_t	qtd_word;
	size_t	contador;
	int		find_caracter;

	qtd_word = 0;
	contador = 0;
	find_caracter = 0;
	while (s[contador] != '\0')
	{
		if (s[contador] != c && find_caracter == 0)
		{
			qtd_word++;
			find_caracter = 1;
		}
		else if (s[contador] == c)
			find_caracter = 0;
		contador ++;
	}
	return (qtd_word);
}

char	**ft_split_cub3d(const char *s, char c)
{
	char	**vet_words;
	size_t	i;
	size_t	len;

	if (!s)
		return (0);
	i = 0;
	vet_words = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!vet_words)
		return (0);
	while (*s)
	{
		if (*s != c && *s != ' ' && !(*s >= 9 && *s <= 13))
		{
			len = 0;
			while (*s && *s != c && *s != ' ' && !(*s >= 9 && *s <= 13) \
					&& ++len)
				++s;
			vet_words[i++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
	vet_words[i] = NULL;
	return (vet_words);
}
