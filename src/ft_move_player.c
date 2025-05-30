/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:36:43 by nfigueir          #+#    #+#             */
/*   Updated: 2025/05/30 09:26:09 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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

static void	ft_move_left_right(t_player *player, t_vector *strafe, int speed)
{
	if(player->key_left)
	{
		ft_set_vector(strafe, player->dir);
		ft_rotate_vector(&strafe->x, &strafe->y, -PI / 2 );
		ft_mult_vector(strafe, speed);
	}
	else if (player->key_right)
	{
		ft_set_vector(strafe, player->dir);
		ft_rotate_vector(&strafe->x, &strafe->y, PI / 2 );
		ft_mult_vector(strafe, speed);
	}
	else
		ft_mult_vector(strafe, 0);
}

static void	ft_rotate_left_right(t_player *player, float *angle)
{
	if(player->left_rotate)
		*angle = -3;
	else if (player->right_rotate)
		*angle = 3;
	else
		*angle = 0;
}

static void	ft_update(t_player *player, t_vector v, t_vector s, float angle)
{
	ft_mult_vector(&v, 1.0f / 60);
	ft_add_vector(&player->pos, v);
	ft_mult_vector(&s, 1.0f / 60);
	ft_add_vector(&player->pos, s);
	ft_rotate_vector(&player->dir.x, &player->dir.y, angle / 60);
	ft_rotate_vector(&player->plane.x, &player->plane.y, angle / 60);
}

void	ft_move_player(t_player *player)
{
	int			speed;
	float		rotate_speed;
	t_vector	strafe;
	t_vector	velocity;

	speed = 5;
	ft_move_up_down(player, &velocity, speed);
	ft_move_left_right(player, &strafe, speed);
	ft_rotate_left_right(player, &rotate_speed);
	ft_update(player, velocity, strafe, rotate_speed);
}
