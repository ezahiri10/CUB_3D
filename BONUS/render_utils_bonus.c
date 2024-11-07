/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:22:01 by ezahiri           #+#    #+#             */
/*   Updated: 2024/11/07 15:11:42 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

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

uint32_t	get_texture_pixel(mlx_texture_t *texture, int x, int y)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
	int		index;

	if (x >= 0 && (uint32_t)x < texture->width
		&& y >= 0 && (uint32_t)y < texture->height)
	{
		index = (y * texture->width + x) * 4;
		r = texture->pixels[index];
		g = texture->pixels[index + 1];
		b = texture->pixels[index + 2];
		a = texture->pixels[index + 3];
		return (r << 24 | g << 16 | b << 8 | a);
	}
	return (0x000000FF);
}
