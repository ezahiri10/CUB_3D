/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:40:36 by ezahiri           #+#    #+#             */
/*   Updated: 2024/11/07 12:06:35 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_texture(t_data *data, int i)
{
	if (data->ray[i].h_or_v == 'v')
	{
		if (data->ray[i].left_right == 'l')
			data->ray[i].j = 3;
		if (data->ray[i].left_right == 'r')
			data->ray[i].j = 2;
	}
	if (data->ray[i].h_or_v == 'h')
	{
		if (data->ray[i].up_down == 'u')
			data->ray[i].j = 0;
		if (data->ray[i].up_down == 'd')
			data->ray[i].j = 1;
	}
}
