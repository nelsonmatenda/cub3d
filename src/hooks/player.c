/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 09:25:06 by nfigueir          #+#    #+#             */
/*   Updated: 2025/04/21 15:19:43 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_key_press(int key, t_player *player)
{
	if (key == W)
		player->key_up = true;
	if (key == S)
		player->key_down = true;
	if (key == A)
		player->key_left = true;
	if (key == D)
		player->key_right = true;
	if (key == LEFT)
		player->left_rotate = true;
	if (key == RIGHT)
		player->right_rotate = true;
	return (0);
}

int	ft_key_release(int key, t_player *player)
{
	if (key == W)
		player->key_up = false;
	if (key == S)
		player->key_down = false;
	if (key == A)
		player->key_left = false;
	if (key == D)
		player->key_right = false;
	if (key == LEFT)
		player->left_rotate = false;
	if (key == RIGHT)
		player->right_rotate = false;
	return (0);
}
