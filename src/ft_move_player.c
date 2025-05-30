/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:36:43 by nfigueir          #+#    #+#             */
/*   Updated: 2025/05/30 10:15:38 by nfigueir         ###   ########.fr       */
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

static void	ft_update(t_player *player, t_move move, double time)
{
	ft_mult_vector(&move.velocity, time / 1000);
	ft_add_vector(&player->pos, move.velocity);
	ft_mult_vector(&move.strafe, time / 1000);
	ft_add_vector(&player->pos, move.strafe);
	ft_rotate_vector(&player->dir.x, &player->dir.y, \
						move.rotate_speed * time / 1000);
	ft_rotate_vector(&player->plane.x, &player->plane.y, \
						move.rotate_speed * time / 1000);
}

void	ft_move_player(t_player *player, double time)
{
	t_move	move;

	move.speed = 5;
	ft_move_up_down(player, &move.velocity, move.speed);
	ft_move_left_right(player, &move.strafe, move.speed);
	ft_rotate_left_right(player, &move.rotate_speed);
	ft_update(player, move, time);
}
