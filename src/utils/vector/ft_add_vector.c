/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:24:45 by nfigueir          #+#    #+#             */
/*   Updated: 2025/06/10 12:16:21 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

/**
 * @brief Calculate the sum of two vectors.
 *
 * @param a Vector with x and y do want add
 * @param b Vector with x and y
 * @return New vector result of sum
 */
t_vector	ft_add_vector(t_vector *a, t_vector b)
{
	a->x += b.x;
	a->y += b.y;
	return (*a);
}
