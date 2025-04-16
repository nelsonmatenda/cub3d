/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:47:49 by gudos-sa          #+#    #+#             */
/*   Updated: 2024/05/21 17:47:51 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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
		printf("Caracter: %c\n", s[contador]);
		if(s[contador] == 32)
			printf("ESPACO\n");
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

char	**ft_split(const char *s, char c)
{
	char	**vet_words;
	size_t	i;
	size_t	len;

	if (!s)
		return (0);
	i = 0;
	int w = count_words(s, c);
	printf("Words: %d\n",w );
	vet_words = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!vet_words)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			vet_words[i++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
	vet_words[i] = NULL;
	return (vet_words);
}
