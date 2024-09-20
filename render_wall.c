/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:15:44 by ezahiri           #+#    #+#             */
/*   Updated: 2024/09/14 17:46:50 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	check_wall(t_data *data, double x, double y)
{
	if (x < 0 || y < 0 || x > data->width || y > data->height)
		return (true);
	if (data->map.map[(int)floor(y / TILE_SIZE)][(int)floor(x / TILE_SIZE)] \
		== '1')
		return (true);
	return (false);
}

void	draw_line(int i, double line, t_data *data)
{
	double	y;
	double	x;

	x = 0;
	y = data->height / 2 - line / 2;
	if (y < 0)
		y = 0;
	while (x <= y)
	{
		mlx_put_pixel (data->img, i, x, BLUE);
		x++;
	}
	x = data->height / 2 + line / 2;
	if (x >= data->height)
		x = data->height - 1;
	while (y <= x)
	{
		if (data->ray[i].h_or_v == 'v')
		{
			if (check_pixel (i, y, data) == false)
				mlx_put_pixel (data->img, i, y, rgb(0, 255, 0, 100));
		}
		else
		{
			if (check_pixel (i, y, data) == false)
				mlx_put_pixel (data->img, i, y, rgb(0, 255, 0, 255));
		}
		y++;
	}
}

void	render_wall(t_data *data)
{
	double	line;
	double	cor_ray;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < data->width)
	{
		cor_ray = data->ray[i].distance * cos(data->player.angle - data->ray[i].angle);
		line  = 10000 / cor_ray;
		draw_line (i, line, data);
		i++;
	}
}