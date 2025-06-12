/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:35:39 by nfigueir          #+#    #+#             */
/*   Updated: 2025/06/12 13:34:17 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error_msg(int error, char *msg)
{
	printf("Error\n");
	if (error == MALLOC_ERR)
		printf("Falha na alocação");
	if (msg)
		printf("\033[90m%s\033[0m\n", msg);
}

int	ft_exit(t_game *game, int status, char *msg)
{
	if (game)
		ft_free_game(*game);
	if (status < 0)
	{
		error_msg(status, msg);
		return (exit(EXIT_FAILURE), 1);
	}
	else
		printf("\033[90m%s\033[0m\n", msg);
	exit(EXIT_SUCCESS);
}
