/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mult_two_vectorr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:46:31 by nfigueir          #+#    #+#             */
/*   Updated: 2025/05/30 12:05:32 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

/**
 * @brief Multiply two vector
 *
 * @param a Vector with x and y
 * @param mult Scalar
 * @return t_vector New vector
 */
t_vector	ft_mult_two_vector(t_vector *a, t_vector b)
{
	a->x *= b.x;
	a->y *= b.y;
	return (*a);
}
