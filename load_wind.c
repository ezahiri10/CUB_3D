/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_wind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:34:51 by ezahiri           #+#    #+#             */
/*   Updated: 2024/09/18 10:16:59 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init (data->width, data->height, "CUB3", false);
	data->img = mlx_new_image (data->mlx , data->width, data->height);
	mlx_image_to_window (data->mlx, data->img, 0, 0);
}

void	load_wind(t_data *data)
{
	init_mlx (data);
	render_map (data);
	mlx_loop_hook (data->mlx, move_player, data);
	mlx_loop (data->mlx);
	// mlx_terminate (data->mlx);
}
