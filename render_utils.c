/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:22:01 by ezahiri           #+#    #+#             */
/*   Updated: 2024/09/12 10:42:51 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

uint32_t	rgb(t_color r, t_color g, t_color b, t_color a)
{
	uint32_t	res;

	res = r * pow (2, 24) + g * pow (2, 16) + b * pow (2, 8) + a;
	return (res);
}

double	norm_angle(double angle)
{
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

double	calcul_dis(t_data *data, t_vector pos)
{
	double	dis;

	dis = sqrt(pow(data->player.pos.x - pos.x, 2) \
		+ pow(data->player.pos.y - pos.y, 2));
	return (dis);
}

bool	check_pixel(double x, double y, t_data *data)
{
	if (x < 0 || y < 0 || x >= data->width || y >= data->height)
		return (true);
	return (false);
}

void	get_derictions(t_data *data, int i)
{
	double	angle;

	angle = data->ray[i].angle;
	if (angle > 0 && angle < M_PI)
		data->ray[i].up_down = 'd';
	else
		data->ray[i].up_down = 'u';
	if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
		data->ray[i].left_right = 'l';
	else
		data->ray[i].left_right = 'r';
}
