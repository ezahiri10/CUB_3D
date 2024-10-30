/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:40:36 by ezahiri           #+#    #+#             */
/*   Updated: 2024/10/27 18:27:11 by sel-hasn         ###   ########.fr       */
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

	pos.x = data->player.pos.x;
	pos.y = data->player.pos.y;
	i = pos.y - RAY;
	j = pos.x - RAY;
	while (i <= pos.y + RAY)
	{
		j = pos.x - RAY;
		while (j <= pos.x + RAY)
		{
			if (pow(j - pos.x, 2) + pow(i - pos.y, 2) <= pow(RAY, 2))
				mlx_put_pixel (data->img, j, i, rgb (0, 255, 0, 255));
			j++;
		}
		i++;
	}
	return (0);
}

int	put_carre(t_data *data, int x, int y, uint32_t color)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			mlx_put_pixel(data->img, x + i, y + j, color);
			j++;
		}
		i++;
	}
	return (0);
}

void	render_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.width)
		{
			if (data->map.map[i][j] == '1')
				put_carre (data, j * TILE_SIZE, i * TILE_SIZE,
					rgb (0, 255, 255, 255));
			else
				put_carre (data, j * TILE_SIZE, i * TILE_SIZE,
					rgb (255, 255, 255, 255));
			j++;
		}
		i++;
	}
	put_cercle(data);
}
