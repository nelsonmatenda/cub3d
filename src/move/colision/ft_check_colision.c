/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_colision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:01:40 by nfigueir          #+#    #+#             */
/*   Updated: 2025/05/30 15:23:26 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/cub3D.h"

t_vector	ft_square_colision(t_vector p, t_vector p_next, t_vector m, \
								char **map)
{
	t_vector	res;

	ft_set_vector(&res, (t_vector){0, 0});
	if (map[(int)m.y][(int)m.x] == '1')
	{
		if((p_next.x + LIMIT < m.x) || (p_next.x - LIMIT > m.x + 1) \
			|| (p.y + LIMIT < m.y) || (p.y - LIMIT > m.y + 1))
			res.x = 1;
		if((p_next.y + LIMIT < m.y) || (p_next.y - LIMIT > m.y + 1) || \
			(p.x + LIMIT < m.x) || (p.x - LIMIT > m.x + 1))
			res.y = 1;
		return (res);
	}
	return ((t_vector){1, 1});
}

t_vector	ft_check_colision(t_player *player, t_vector p_next, t_vector m, \
								char **map)
{
	t_vector	col;
	t_vector	p;

	p = player->pos;
	ft_set_vector(&col, (t_vector){1, 1});
	if (ft_mag_vector(m) > 0)
	{
		ft_mult_two_vector(&col ,ft_square_colision(p, p_next, \
			(t_vector){floor(p.x) -1, floor(p.y) - 1}, map));
		ft_mult_two_vector(&col ,ft_square_colision(p, p_next, \
			(t_vector){floor(p.x) -1, floor(p.y)}, map));
		ft_mult_two_vector(&col ,ft_square_colision(p, p_next, \
			(t_vector){floor(p.x) -1, floor(p.y) + 1}, map));
		ft_mult_two_vector(&col ,ft_square_colision(p, p_next, \
			(t_vector){floor(p.x), floor(p.y) - 1}, map));
		ft_mult_two_vector(&col ,ft_square_colision(p, p_next, \
			(t_vector){floor(p.x) , floor(p.y) + 1}, map));
		ft_mult_two_vector(&col ,ft_square_colision(p, p_next, \
			(t_vector){floor(p.x) +1, floor(p.y) -1}, map));
		ft_mult_two_vector(&col ,ft_square_colision(p, p_next, \
			(t_vector){floor(p.x) +1, floor(p.y)}, map));
		ft_mult_two_vector(&col ,ft_square_colision(p, p_next, \
			(t_vector){floor(p.x) +1, floor(p.y) +1}, map));
	}
	return (col);
}
