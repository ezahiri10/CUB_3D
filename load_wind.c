/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_wind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:34:51 by ezahiri           #+#    #+#             */
/*   Updated: 2024/11/03 17:34:39 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init (W_S, H_S, "CUB3", false);
	if (!data->mlx)
		ft_exit (1);
	data->img = mlx_new_image (data->mlx, W_S, H_S);
	if (!data->img)
		ft_exit (1);
	mlx_image_to_window (data->mlx, data->img, 0, 0);
}

void	frames(void *ptr)
{
	move_player(ptr);
}

void	load_wind(t_data *data)
{
	init_mlx (data);
	mlx_loop_hook (data->mlx, frames, data);
	mlx_loop (data->mlx);
}
