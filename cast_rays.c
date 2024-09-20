/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:17:41 by ezahiri           #+#    #+#             */
/*   Updated: 2024/09/20 11:36:20 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	inter_h(t_data *data, int i)
{
	double	y_a;

	first_point_h (data, i);
	data->ray[i].steps.y = TILE_SIZE;
	if (data->ray[i].up_down == 'u')
		data->ray[i].steps.y *= -1;
	data->ray[i].steps.x = fabs(TILE_SIZE / tan(data->ray[i].angle));
	if (data->ray[i].left_right == 'l')
		data->ray[i].steps.x *= -1;
	y_a = data->ray[i].inter_h.y;
	while (1)
	{
		if (data->ray[i].up_down == 'u')
			y_a -= 0.001;
		if (check_wall (data, data->ray[i].inter_h.x, y_a) == true)
			break ;
		data->ray[i].inter_h.x += data->ray[i].steps.x;
		data->ray[i].inter_h.y += data->ray[i].steps.y;
		y_a = data->ray[i].inter_h.y;
	}
}

void	inter_v(t_data *data, int i)
{
	double	x_a;

	first_point_v (data, i);
	data->ray[i].steps.x = TILE_SIZE;
	if (data->ray[i].left_right == 'l')
		data->ray[i].steps.x *= -1;
	data->ray[i].steps.y = fabs(TILE_SIZE * tan(data->ray[i].angle));
	if (data->ray[i].up_down == 'u')
		data->ray[i].steps.y *= -1;
	x_a = data->ray[i].inter_v.x;
	while (1)
	{
		if (data->ray[i].left_right == 'l')
			x_a -= 0.001;
		if (check_wall (data, x_a, data->ray[i].inter_v.y) == true)
			break ;
		data->ray[i].inter_v.x += data->ray[i].steps.x;
		data->ray[i].inter_v.y += data->ray[i].steps.y;
		x_a = data->ray[i].inter_v.x;
	}
}

void	wall_distance(t_data *data, int i)
{
	double	dis_h;
	double	dis_v;

	dis_h = calcul_dis (data, data->ray[i].inter_h);
	dis_v = calcul_dis (data, data->ray[i].inter_v);
	if (dis_v <= dis_h)
	{
		data->ray[i].pos_wall = data->ray[i].inter_v;
		data->ray[i].distance = dis_v;
		data->ray[i].h_or_v = 'v';
	}
	else
	{
		data->ray[i].pos_wall = data->ray[i].inter_h;
		data->ray[i].distance = dis_h;
		data->ray[i].h_or_v = 'h';
	}
}

void	reset_img(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->width)
	{
		j = 0;
		while (j < data->height)
		{
			if (check_pixel (i, j, data) == false)
				mlx_put_pixel (data->img, i, j, 0);
			j++;
		}
		i++;
	}
}

void	cast_rays(t_data *data)
{
	t_ray	ray[(int)data->width];
	int		i;
	double	angle;

	i = 0;
	data->ray = ray;
	angle = data->player.angle - FOV / 2;
	while (i < data->width)
	{
		data->ray[i].angle = norm_angle (angle);
		get_derictions (data, i);
		inter_h (data, i);
		inter_v (data, i);
		wall_distance (data, i);
		angle += FOV / data->width;
		i++;
	}
	reset_img (data);
	draw_3d (data);
}

	// render_wall (data);
	// i = 0;
	// while (i < 1)
	// {
		// DDA(data->player.pos.x, data->player.pos.y, data->ray[i].inter_h.x, \
		// 	data->ray[i].inter_h.y, data);
		// printf("angle: %f\n", data->ray[i].distance);
// 		DDA(data->player.pos.x, data->player.pos.y, data->ray[i].pos_wall.x, \
// 			data->ray[i].pos_wall.y, data);
// 		i++;
// 	}