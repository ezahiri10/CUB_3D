/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:52:12 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/10/27 18:33:30 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_load_gun_shoot(t_data *d)
{
	char	*paths[9];
	int		i;

	i = 0;
	init_paths(paths);
	d->shoot = ft_malloc(sizeof(mlx_texture_t *) * 9, 1);
	d->shoot_img = ft_malloc(sizeof(mlx_image_t *) * 9, 1);
	while (i < 9)
	{
		d->shoot[i] = mlx_load_png(paths[i]);
		if (!d->shoot[i])
			handl_error_missage("Error\nInvalid texture path");
		d->shoot_img[i] = mlx_texture_to_image(d->mlx, d->shoot[i]);
		if (!d->shoot_img[i])
			handl_error_missage("Error\nCan't convert texture to img");
		if (mlx_image_to_window(d->mlx, d->shoot_img[i], 0, 0) < 0)
			handl_error_missage("Error\nCan't add image to window");
		d->shoot_img[i]->instances[0].enabled = false;
		i++;
	}
	d->shoot_img[0]->instances[0].enabled = true;
}

void	ft_load_gun_reload(t_data *d)
{
	char	*paths[16];
	int		i;

	i = 0;
	init_reload_paths(paths);
	d->reload = ft_malloc(sizeof(mlx_texture_t *) * 16, 1);
	d->reload_img = ft_malloc(sizeof(mlx_image_t *) * 16, 1);
	while (i < 16)
	{
		d->reload[i] = mlx_load_png(paths[i]);
		if (!d->reload[i])
			handl_error_missage("Error\nInvalid texture path");
		d->reload_img[i] = mlx_texture_to_image(d->mlx, d->reload[i]);
		if (!d->reload_img[i])
			handl_error_missage("Error\nCan't convert texture to img");
		if (mlx_image_to_window(d->mlx, d->reload_img[i], 0, 0) < 0)
			handl_error_missage("Error\nCan't add image to window");
		d->reload_img[i]->instances[0].enabled = false;
		i++;
	}
}

void	shoot_sprit_animation(void *ptr)
{
	t_data		*data;
	static int	i;

	data = (t_data *)ptr;
	if (data->is_shooting)
	{
		if (i > 0)
		{
			data->shoot_img[i - 1]->instances[0].enabled = false;
			data->shoot_img[i]->instances[0].enabled = true;
		}
		i++;
		if (i >= 9)
		{
			data->shoot_img[8]->instances[0].enabled = false;
			data->shoot_img[0]->instances[0].enabled = true;
			data->is_shooting = false;
			i = 0;
		}
		usleep(10000);
	}
}

void	reload_sprit_animation(void *ptr)
{
	t_data		*data;
	static int	i;

	data = (t_data *)ptr;
	if (data->bullets == 0 && !data->is_shooting)
		data->is_reloading = true;
	if (data->is_reloading)
	{
		if (i == 0)
			data->shoot_img[0]->instances[0].enabled = false;
		if (i > 0)
			data->reload_img[i - 1]->instances[0].enabled = false;
		data->reload_img[i]->instances[0].enabled = true;
		i++;
		if (i >= 16)
		{
			data->reload_img[15]->instances[0].enabled = false;
			data->shoot_img[0]->instances[0].enabled = true;
			data->is_reloading = false;
			i = 0;
			data->bullets = 9;
			ft_print_bullet(data);
		}
		usleep(50000);
	}
}
