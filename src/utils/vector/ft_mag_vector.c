/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mag_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:19:59 by nfigueir          #+#    #+#             */
/*   Updated: 2025/05/30 12:21:36 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

/**
 * @brief Calculate the magnitude of a vector.
 *
 * @param a A vector with x and y
 * @return Magnitude of the vector
 */
float	ft_mag_vector(t_vector a)
{
	return (sqrt(pow(a.x, 2) + pow(a.y, 2)));
}
