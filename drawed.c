/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:40:36 by ezahiri           #+#    #+#             */
/*   Updated: 2024/11/05 16:00:55 by ezahiri          ###   ########.fr       */
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

	pos.x = data->mini_p.x;
	pos.y = data->mini_p.y;
	i = pos.y - RAY;
	j = pos.x - RAY;
	while (i <= pos.y + RAY)
	{
		j = pos.x - RAY;
		while (j <= pos.x + RAY)
		{
			if (pow(j - pos.x, 2) + pow(i - pos.y, 2) <= pow(RAY, 2))
				put_pixel (data->mini, j, i, rgb (0, 255, 0, 255));
			j++;
		}
		i++;
	}
	return (0);
}

void	put_carre(t_data *data, int x, int y, uint32_t color)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = 200 / 6;
	while (i < size)
	{
		j = 0;
		while (j <  size)
		{
			if ((x + i) < 0 || (x + i) > 200)
				return ;
			if ((y + j) < 0 || (y + j) > 200)
				return ;
			mlx_put_pixel(data->mini, (x + i), (y + j), color);
			j++;
		}
		i++;
	}
	return ;
}

void	render_map(t_data *data)
{
	double			size;
	t_vector	map;
	t_vector	start;
	uint32_t	color;
	double		i;
	double		j;

	size = 200 / 6;
	start.x = data->player.pos.x - (3 * TILE_SIZE);
	start.y = data->player.pos.y - (3 * TILE_SIZE);
	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			map.x = (start.x / TILE_SIZE) + j;
			map.y = (start.y / TILE_SIZE) + i;
			if (map.x >= 0 &&  map.x < data->map.width && map.y >= 0 && map.y <  data->map.height)
			{
				if (data->map.map[(int)map.y][(int)map.x] == '1')
				{
					color = rgb(0, 255, 255, 255);
					put_carre (data, j * size, i * size, color);
				}
				else
				{
					color = rgb (255, 255, 255, 255);
					put_carre (data, j * size, i * size, color);
				}
			}
			else
			{
				color = rgb(0, 255, 255, 255);
				put_carre (data, j * size, i * size, color);
			}
			j += 1;
		}
		i += 1;
	}
	data->mini_p.x = 200 / 2;
	data->mini_p.y = 200 / 2;
	put_cercle(data);
	// dda(data, data->mini_p, data->mini_p.x + cos (data->player.angle) * 10, data->mini_p.y + sin (data->player.angle) * 10);
}