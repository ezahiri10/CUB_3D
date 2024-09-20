/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:25:20 by ezahiri           #+#    #+#             */
/*   Updated: 2024/09/20 11:35:54 by ezahiri          ###   ########.fr       */
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


void	put_pixels(t_data *data, int i, double y, int j)
{
	double		x_txt;
	double		y_txt;
	double		pos;
	uint32_t	color;

	x_txt = data->ray[i].p_txt.x;
	y_txt = data->ray[i].p_txt.y;
	pos = (data->texture[j]->width * y_txt) + x_txt;
	if (i < 0 || y < 0 || i > data->width || y > data->height
		|| pos < 0 || pos > data->texture[j]->width * data->texture[j]->height)
		return ;
	// color = data->txt[(int)pos];
	color = get_texture_pixel(data->texture[j], x_txt, y_txt);
	mlx_put_pixel (data->img, i, y, color);
}

void	draw_lines(t_data *data, int i, int j)
{
	double	y;
	double	x;
	double	height;

	height = data->texture[j]->height;
	x = 0;
	y = data->height / 2 - data->ray[i].line / 2;
	if (y < 0)
		y = 0;
	while (x <= y)
	{
		mlx_put_pixel (data->img, i, x, RED);
		x++;
	}
	x = data->height / 2 + data->ray[i].line / 2;
	if (x >= data->height)
		x = data->height;
	while (y <= x)
	{
		data->ray[i].p_txt.y = (y - (data->height / 2 - data->ray[i].line / 2))
			* height / data->ray[i].line;
		put_pixels (data, i, y, j);
		y++;
	}
}

void	get_texture(t_data *data, int i)
{
	if (data->ray[i].up_down == 'u' && data->ray[i].h_or_v == 'v')
		data->ray[i].j = 0;
	else if (data->ray[i].up_down == 'd' && data->ray[i].h_or_v == 'v')
		data->ray[i].j = 1;
	else if (data->ray[i].left_right == 'l' && data->ray[i].h_or_v == 'h')
		data->ray[i].j = 2;
	else if (data->ray[i].left_right == 'r' && data->ray[i].h_or_v == 'h')
		data->ray[i].j = 3;
}

void	draw_3d(t_data *data)
{
	double	cor_ray;
	int		i;

	i = 0;
	while (i < data->width)
	{
		get_texture(data, i);
		data->ray[i].p_txt.x = get_x(data, i);
		cor_ray = data->ray[i].distance * \
			cos(data->player.angle - data->ray[i].angle);
		data->ray[i].line  = 50000 / cor_ray;
		draw_lines(data, i, data->ray[i].j);
		i++;
	}
}