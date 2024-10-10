/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:25:20 by ezahiri           #+#    #+#             */
/*   Updated: 2024/10/08 14:35:32 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	double		pos;
	uint32_t	color;

	x_txt = data->ray[i].p_txt.x;
	y_txt = data->ray[i].p_txt.y;
	pos = (data->texture[j]->width * y_txt) + x_txt;
	if (i < 0 || y < 0 || i > W_S || y > H_S
		|| pos < 0 || pos > data->texture[j]->width * data->texture[j]->height)
		return ;
	color = get_texture_pixel(data->texture[j], x_txt, y_txt);
	put_pixel (data->img, i, y, color);
}

void draw_fl_cl(t_data *data, int i)
{
	int	x;
	int y;

	x = 0;
	y = H_S / 2 - data->ray[i].line / 2;
	if (y < 0)
		y = 0;
	while (x <= y)
	{
		put_pixel (data->img, i, x, data->map.floor);
		x++;
	}
	x = H_S / 2 + data->ray[i].line / 2;
	if (x > H_S)
		x = H_S;
	y = H_S;
	while (x <= y)
	{
		put_pixel (data->img, i, x, data->map.ceiling);
		x++;
	}
}
void	draw_lines(t_data *data, int i, int j)
{
	double	y;
	double	x;
	double	height;

	height = data->texture[j]->height;
	// x = 0;
	// while (x <= y)
	// {
	// 	put_pixel (data->img, i, x, data->map.floor);
	// 	x++;
	// }
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

void	get_texture(t_data *data, int i)
{
	if (data->ray[i].h_or_v == 'v')
	{
		if (data->ray[i].left_right == 'l')
			data->ray[i].j = 2;
		if (data->ray[i].left_right == 'r')
			data->ray[i].j = 3;
	}
	if (data->ray[i].h_or_v == 'h')
	{
		if (data->ray[i].up_down == 'u')
			data->ray[i].j = 0;
		if (data->ray[i].up_down == 'd')
			data->ray[i].j = 1;
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
		data->ray[i].p_txt.x = get_x(data, i);
		cor_ray = data->ray[i].distance * \
			cos(data->player.angle - data->ray[i].angle);
		data->ray[i].line = 40000 / cor_ray;
		draw_lines(data, i, data->ray[i].j);
		i++;
	}
}
