/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:25:20 by ezahiri           #+#    #+#             */
/*   Updated: 2024/11/07 15:11:42 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

double	get_x(t_data *data, int i)
{
	double	x;
	int		indx;

	indx = data->ray[i].j;
	if (data->ray[i].h_or_v == 'v')
		x = fmod(data->ray[i].pos_wall.y, TILE_SIZE);
	else
		x = fmod(data->ray[i].pos_wall.x, TILE_SIZE);
	x = x * data->texture[indx]->width / TILE_SIZE;
	return (x);
}

void	put_txt(t_data *data, int i, double y, int j)
{
	double		x_txt;
	double		y_txt;
	uint32_t	color;

	x_txt = data->ray[i].p_txt.x;
	y_txt = data->ray[i].p_txt.y;
	if (i < 0 || y < 0 || i > W_S || y > H_S)
		return ;
	color = get_texture_pixel(data->texture[j], x_txt, y_txt);
	put_pixel (data->img, i, y, color);
}

void	draw_fl_cl(t_data *data, int i)
{
	int	x;
	int	y;

	x = 0;
	y = H_S / 2 - data->ray[i].line / 2;
	if (y < 0)
		y = 0;
	while (x <= y)
	{
		put_pixel (data->img, i, x, data->map.ceiling);
		x++;
	}
	x = H_S / 2 + data->ray[i].line / 2;
	if (x > H_S)
		x = H_S;
	y = H_S;
	while (x <= y)
	{
		put_pixel (data->img, i, x, data->map.floor);
		x++;
	}
}

void	draw_lines(t_data *data, int i, int j)
{
	double	y;
	double	x;
	double	height;

	height = data->texture[j]->height;
	draw_fl_cl(data, i);
	y = H_S / 2 - data->ray[i].line / 2;
	if (y < 0)
		y = 0;
	x = H_S / 2 + data->ray[i].line / 2;
	if (x >= H_S)
		x = H_S;
	while (y <= x)
	{
		data->ray[i].p_txt.y = (y - (H_S / 2 - data->ray[i].line / 2))
			* height / data->ray[i].line;
		put_txt (data, i, y, j);
		y++;
	}
}

void	draw_3d(t_data *data)
{
	double	cor_ray;
	int		i;

	i = 0;
	while (i < W_S)
	{
		get_texture(data, i);
		if (data->ray[i].is_door_h || data->ray[i].is_door_v)
			data->ray[i].j = 4;
		data->ray[i].p_txt.x = get_x(data, i);
		cor_ray = data->ray[i].distance * \
			cos(data->player.angle - data->ray[i].angle);
		data->ray[i].line = 40000 / cor_ray;
		draw_lines(data, i, data->ray[i].j);
		i++;
	}
}
