/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:36:43 by nfigueir          #+#    #+#             */
/*   Updated: 2025/05/29 15:38:21 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// static void	rotate(t_player *player)
// {
// 	float	angle_speed;

// 	angle_speed = 0.03;
// 	if (player->left_rotate)
// 		player->angle -= angle_speed;
// 	if (player->right_rotate)
// 		player->angle += angle_speed;
// 	if (player->angle > 2 * PI)
// 		player->angle -= 2 * PI;
// 	if (player->angle < 0)
// 		player->angle += 2 * PI;
// }
void	ft_update_player()
{

}
static void	ft_move_up_down(t_player *player, t_vector *velocity, int speed)
{
	if(player->key_up)
	{
		ft_set_vector(velocity, player->dir);
		ft_mult_vector(velocity, speed);
	}
	else if (player->key_down)
	{
		ft_set_vector(velocity, player->dir);
		ft_mult_vector(velocity, -speed);
	}
	else
		ft_mult_vector(velocity, 0);
}

void	ft_update(t_player *player, t_vector velocity)
{
	ft_mult_vector(&velocity, 1.0f / 60);
	ft_add_vector(&player->pos, velocity);
}

void	ft_move_player(t_player *player)
{
	int			speed;
	t_vector	velocity;

	speed = 5;
	ft_move_up_down(player, &velocity, speed);
	ft_update(player, velocity);
}
