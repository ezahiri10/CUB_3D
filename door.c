/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:06:10 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/11/05 22:13:29 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	handle_open_door(t_data *d, t_door *door)
{
	int	i;
	int	j;

	i = floor(d->ray[W_S / 2].pos_wall.y / TILE_SIZE);
	j = floor(d->ray[W_S / 2].pos_wall.x / TILE_SIZE);
	if (d->ray[W_S / 2].distance <= TILE_SIZE * 2
		&& d->ray[W_S / 2].h_or_v == 'h')
	{
		door->j = j;
		if (d->ray[W_S / 2].up_down == 'd' && d->map.map[i][j] == 'D')
			door->i = i;
		else if (d->ray[W_S / 2].up_down == 'u' && d->map.map[i - 1][j] == 'D')
			door->i = i - 1;
	}
	else if (d->ray[W_S / 2].distance <= TILE_SIZE * 2
		&& d->ray[W_S / 2].h_or_v == 'v')
	{
		door->i = i;
		if (d->ray[W_S / 2].left_right == 'r' && d->map.map[i][j] == 'D')
			door->j = j;
		else if (d->ray[W_S / 2].left_right == 'l'
			&& d->map.map[i][j - 1] == 'D')
			door->j = j - 1;
	}
}

void	close_doors(t_data *data)
{
	int	i;
	int	j;
	int	ind;

	ind = 0;
	i = floor(data->player.pos.y / TILE_SIZE);
	j = floor(data->player.pos.x / TILE_SIZE);
	while (ind < data->map.door_counter)
	{
		if ((data->doors[ind].i != i || data->doors[ind].j != j)
			&& data->doors[ind].stat == 'O')
			data->doors[ind].stat = 'C';
		ind++;
	}
}

void	open_close_door(void *ptr)
{
	t_data	*data;
	int		t;
	t_door	door;

	data = (t_data *)ptr;
	if (data->is_close == true)
	{
		data->is_close = false;
		close_doors(data);
	}
	if (data->is_open == true)
	{
		data->is_open = false;
		handle_open_door(data, &door);
		t = get_door_index(data, door.i, door.j);
		if (t != -1 && data->doors[t].stat == 'C')
			data->doors[t].stat = 'O';
	}
}
