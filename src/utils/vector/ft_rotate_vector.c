/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:32:44 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/06/10 12:15:09 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_rotate_vector(float *x, float *y, float angle)
{
	t_vector	tmp;

	tmp.x = *x;
	tmp.y = *y;
	*x = (tmp.x * cos(angle)) - (tmp.y * sin(angle));
	*y = (tmp.x * sin(angle)) + (tmp.y * cos(angle));
}
