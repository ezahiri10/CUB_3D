/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:40:36 by ezahiri           #+#    #+#             */
/*   Updated: 2024/11/04 20:48:37 by ezahiri          ###   ########.fr       */
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

	i = 0;
	while (i < TILE_SIZE / 2)
	{
		j = 0;
		while (j < TILE_SIZE / 2)
		{
			if (x + i < 0 || x + i >= W_S / 3)
				return ;
			if (y + j < 0 || y + j >= H_S / 3)
				return ;
			mlx_put_pixel(data->mini, x + i, y + j, color);
			j++;
		}
		i++;
	}
	return ;
}

void	render_map(t_data *data)
{
	double			i;
	double			j;
	// t_vector 	pos;

	i = floor (data->player.pos.x/ TILE_SIZE) - 2;
	if (i < 0)
		i = 0;
	while (i < floor (data->player.pos.x / TILE_SIZE)  + 2)
	{
		printf ("data->player i:%f j:%f\n", i, j);
		j = floor (data->player.pos.y/ TILE_SIZE)  - 2;
		if (j < 0)
			j = 0;
		while (j < floor (data->player.pos.y/ TILE_SIZE)  + 2)
		{
			if (data->map.map[(int)i][(int)j] == '1')
				put_carre (data,( j * TILE_SIZE) / 2, (i * TILE_SIZE) / 2,
					rgb (0, 255, 255, 255));
			else
				put_carre (data, j * TILE_SIZE / 2, i * TILE_SIZE / 2,
					rgb (255, 255, 255, 255));
			j++;
		}
		i++;
	}
	data->mini_p.x = data->player.pos.x / 4;
	data->mini_p.y = data->player.pos.y / 4;
	 //put_cercle(data);
	// dda(data, data->mini_p, data->mini_p.x + cos (data->player.angle) * 10, data->mini_p.y + sin (data->player.angle) * 10);
}
