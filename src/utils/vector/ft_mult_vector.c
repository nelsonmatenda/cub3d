/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mult_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:46:31 by nfigueir          #+#    #+#             */
/*   Updated: 2025/05/29 15:06:06 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

/**
 * @brief Multiply a vector with a scalar
 *
 * @param a Vector with x and y
 * @param mult Scalar
 * @return t_vector New vector
 */
t_vector	ft_mult_vector(t_vector *a, float mult)
{
	a->x *= mult;
	a->y *= mult;
	return (*a);
}
