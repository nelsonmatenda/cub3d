/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudos-sa <gudos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:36:43 by nfigueir          #+#    #+#             */
/*   Updated: 2025/05/28 12:25:53 by gudos-sa         ###   ########.fr       */
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

static void	move(t_player *player, int speed)
{
	float	cos_angle;
	float	sin_angle;
	
	if (player->key_up)
	{
		player->x += cos_angle * speed;
		player->y += sin_angle * speed;
	}
	if (player->key_down)
	{
		player->x -= cos_angle * speed;
		player->y -= sin_angle * speed;
	}
	if (player->key_left)
	{
		player->x += sin_angle * speed;
		player->y -= cos_angle * speed;
	}
	if (player->key_right)
	{
		player->x -= sin_angle * speed;
		player->y += cos_angle * speed;
	}
}

void	move_player(t_player *player)
{
	int		speed;

	speed = 2;
	// // rotate(player);
	move(player, speed);
}
