/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:15:44 by ezahiri           #+#    #+#             */
/*   Updated: 2024/10/29 14:54:03 by sel-hasn         ###   ########.fr       */
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

int	get_door_index(t_data *data, int i, int j)
{
	int	ind;

	ind = 0;
	while (ind < data->map.door_counter)
	{
		if (data->doors[ind].i == i && data->doors[ind].j == j)
			return (ind);
		ind++;
	}
	return (-1);
}

bool	check_door(t_data *data, double x, double y)
{
	int	i;
	int	j;
	int	t;

	i = (int)floor(y / TILE_SIZE);
	j = (int)floor(x / TILE_SIZE);
	if (data->map.map[i][j] == 'D')
	{
		t = get_door_index(data, i, j);
		if (t == -1)
			return (false);
		else if (data->doors[t].stat == 'C')
			return (true);
	}
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
		put_pixel (data->img, i, x, BLUE);
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
