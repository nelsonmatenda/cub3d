/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:35:39 by nfigueir          #+#    #+#             */
/*   Updated: 2025/04/07 09:51:13 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	error_msg(int error, char *msg)
{
	if(error == -1)
		printf("Algum erro\n");
	if (msg)
		printf("\033[90m%s\033[0m\n", msg);
}

int ft_exit(t_game *game, int status, char *msg)
{
	if (game)
		printf("free game\n");
	if (status < 0)
	{
		error_msg(status, msg);
		return (exit(1), 1);
	}
	else
		printf("success\n");
	exit(0);
}
