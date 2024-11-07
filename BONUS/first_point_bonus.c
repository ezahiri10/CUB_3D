/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_point_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:25:35 by ezahiri           #+#    #+#             */
/*   Updated: 2024/11/07 15:11:42 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	first_point_v(t_data *data, int i)
{
	double	x_p;
	double	y_p;

	x_p = data->player.pos.x;
	y_p = data->player.pos.y;
	data->ray[i].inter_v.x = floor(x_p / TILE_SIZE) * TILE_SIZE;
	if (data->ray[i].left_right == 'r')
		data->ray[i].inter_v.x += TILE_SIZE;
	data->ray[i].inter_v.y = (data->ray[i].inter_v.x - x_p) \
		* tan(data->ray[i].angle) + y_p;
}

void	first_point_h(t_data *data, int i)
{
	double	x_p;
	double	y_p;

	x_p = data->player.pos.x;
	y_p = data->player.pos.y;
	data->ray[i].inter_h.y = floor (y_p / TILE_SIZE) * TILE_SIZE;
	if (data->ray[i].up_down == 'd')
		data->ray[i].inter_h.y += TILE_SIZE;
	data->ray[i].inter_h.x = (data->ray[i].inter_h.y - y_p) / \
		tan(data->ray[i].angle) + x_p;
}
