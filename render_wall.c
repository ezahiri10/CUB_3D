/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:15:44 by ezahiri           #+#    #+#             */
/*   Updated: 2024/11/02 22:25:08 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	check_wall(t_data *data, double x, double y)
{
	int	i;
	int	j;

	i = (int)floor(y / TILE_SIZE);
	j = (int)floor(x / TILE_SIZE);
	if (i < 0 || j < 0 || j >= data->map.width || i >= data->map.height)
		return (true);
	if (data->map.map[i][j] == '1')
		return (true);
	return (false);
}

void	draw_line(int i, double line, t_data *data)
{
	double	y;
	double	x;

	x = 0;
	y = H_S / 2 - line / 2;
	if (y < 0)
		y = 0;
	while (x <= y)
	{
		put_pixel (data->img, i, x, 20);
		x++;
	}
	x = H_S / 2 + line / 2;
	if (x >= H_S)
		x = H_S - 1;
	while (y <= x)
	{
		if (data->ray[i].h_or_v == 'v')
			put_pixel (data->img, i, y, rgb(0, 255, 0, 100));
		else
			put_pixel (data->img, i, y, rgb(0, 255, 0, 255));
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
	while (i < W_S)
	{
		cor_ray = data->ray[i].distance * cos(data->player.angle \
		- data->ray[i].angle);
		line = 10000 / cor_ray;
		draw_line (i, line, data);
		i++;
	}
}
