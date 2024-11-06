/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_wind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:34:51 by ezahiri           #+#    #+#             */
/*   Updated: 2024/11/06 21:09:36 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init (W_S, H_S, "CUB3", false);
	if (!data->mlx)
		ft_exit (1);
	data->mini = mlx_new_image (data->mlx, 200, 200);
	if (!data->mini)
		ft_exit (1);
	data->img = mlx_new_image (data->mlx, W_S, H_S);
	if (!data->img)
		ft_exit (1);
	if (mlx_image_to_window (data->mlx, data->img, 0, 0) == -1)
		ft_exit (1);
	if (mlx_image_to_window (data->mlx, data->mini, 0, 0) == -1)
		ft_exit (1);
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
	t_data	*data;

	data = (t_data *)ptr;
	move_player(data);
	shoot_sprit_animation(data);
	reload_sprit_animation(data);
	open_close_door(data);
	render_map (data);
}

void	load_wind(t_data *data)
{
	init_mlx (data);
	mlx_set_cursor_mode (data->mlx, MLX_MOUSE_HIDDEN);
	ft_load_gun_shoot(data);
	ft_load_gun_reload(data);
	data->bullet_text = mlx_put_string(data->mlx, "Bullets: 9", 1050, 0);
	data->bullets = 9;
	mlx_loop_hook (data->mlx, frames, data);
	mlx_cursor_hook (data->mlx, mouse_events, data);
	mlx_key_hook(data->mlx, key_hook, data);
	mlx_loop(data->mlx);
}
