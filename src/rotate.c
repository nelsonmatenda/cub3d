/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <gudos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:32:44 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/05/28 15:12:03 by gudos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void    ft_rotate(float *x, float *y, float a)
{
    t_vector    tmp;

    tmp.x = *x;
    tmp.y = *y;
    *x = (tmp.x * cos(a)) - (tmp.y * sin(a));
    *y = (tmp.x * sin(a)) + (tmp.y * cos(a));
}
