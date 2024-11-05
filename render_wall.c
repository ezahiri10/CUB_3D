/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:15:44 by ezahiri           #+#    #+#             */
/*   Updated: 2024/11/04 21:08:04 by sel-hasn         ###   ########.fr       */
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
