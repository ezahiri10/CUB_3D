/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:40:36 by ezahiri           #+#    #+#             */
/*   Updated: 2024/11/05 23:25:39 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

int	put_cercle(t_data *data)
{
	t_vector	pos;
	int			i;
	int			j;

	pos.x = 100;
	pos.y = 100;
	i = pos.y - RAY;
	while (i <= pos.y + RAY)
	{
		j = pos.x - RAY;
		while (j <= pos.x + RAY)
		{
			if (pow(j - pos.x, 2) + pow(i - pos.y, 2) <= pow(RAY, 2))
			{
				if (j < 0 || j >= 200 || i < 0 || i >= 200)
					return (0);
				mlx_put_pixel(data->mini, j, i, rgb (255, 0, 0, 255));
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_rest_mini_map(t_data *data)
{
	double			i;
	double			j;

	i = 0;
	while (i < 200)
	{
		j = 0;
		while (j < 200)
		{
			mlx_put_pixel(data->mini, j, i, rgb (40, 40, 40, 255));
			j++;
		}
		i++;
	}
}

void	minimap_mlx_put_pixel(t_data *data, double x, double y, uint32_t color)
{
	if (x < 0 || x >= 200 || y < 0 || y >= 200)
		return ;
	mlx_put_pixel (data->mini, x, y, color);
}

void	render_map(t_data *data)
{
	double			y;
	double			x;
	uint32_t		color;

	y = -1;
	ft_rest_mini_map(data);
	while (++y < data->miniheight)
	{
		x = 0;
		while (x < data->miniwidth)
		{
			if (data->map.map[(int)y * 2 / TILE_SIZE]
				[(int)x * 2 / TILE_SIZE] == '1')
				color = rgb (0, 0, 255, 255);
			else if (data->map.map[(int)y * 2 / TILE_SIZE]
				[(int)x * 2 / TILE_SIZE] == 'D')
				color = rgb (0, 255, 255, 255);
			else
				color = rgb (0, 255, 0, 255);
			minimap_mlx_put_pixel(data, x - data->player.pos.x / 2
				+ 100, y - data->player.pos.y / 2 + 100, color);
			x++;
		}
	}
	put_cercle(data);
}
