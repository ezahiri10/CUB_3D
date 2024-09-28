/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_wind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:34:51 by ezahiri           #+#    #+#             */
/*   Updated: 2024/09/28 12:20:00 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init (W_S, H_S, "CUB3", false);
	data->img = mlx_new_image (data->mlx, W_S, H_S);
	mlx_image_to_window (data->mlx, data->img, 0, 0);
}

void	load_wind(t_data *data)
{
	init_mlx (data);
	mlx_loop_hook (data->mlx, move_player, data);
	mlx_loop (data->mlx);
}
// mlx_terminate (data->mlx);
	// render_map (data);
