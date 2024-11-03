/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_wind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:34:51 by ezahiri           #+#    #+#             */
/*   Updated: 2024/10/29 14:59:37 by sel-hasn         ###   ########.fr       */
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

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_RIGHT_CONTROL && keydata.action == MLX_PRESS
		&& !data->is_reloading && !data->is_shooting)
	{
		if (data->bullets > 0)
		{
			data->is_shooting = true;
			data->bullets--;
		}
	}
	else if (!data->is_shooting && keydata.key == MLX_KEY_R
		&& keydata.action == MLX_PRESS)
	{
		data->is_reloading = true;
	}
	else if (keydata.key == MLX_KEY_SPACE
		&& keydata.action == MLX_PRESS)
		data->is_open = true;
	else if (keydata.key == MLX_KEY_C
		&& keydata.action == MLX_PRESS)
		data->is_close = true;
	ft_print_bullet(data);
}

void	frames(void *ptr)
{
	move_player(ptr);
	shoot_sprit_animation(ptr);
	reload_sprit_animation(ptr);
	open_close_door(ptr);
}

void	load_wind(t_data *data)
{
	init_mlx (data);
	ft_load_gun_shoot(data);
	ft_load_gun_reload(data);
	data->bullet_text = mlx_put_string(data->mlx, "Bullets: 9", 0, 0);
	data->bullets = 9;
	// mlx_loop_hook (data->mlx, move_player, data);
	// mlx_loop_hook (data->mlx, shoot_sprit_animation, data);
	// mlx_loop_hook (data->mlx, reload_sprit_animation, data);
	// mlx_loop_hook (data->mlx, open_close_door, data);
	mlx_loop_hook (data->mlx, frames, data);
	mlx_key_hook(data->mlx, key_hook, data);
	mlx_loop (data->mlx);
}
// mlx_terminate (data->mlx);
	// render_map (data);
