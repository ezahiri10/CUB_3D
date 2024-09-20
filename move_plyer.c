/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_plyer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:18:10 by ezahiri           #+#    #+#             */
/*   Updated: 2024/09/20 11:35:24 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	check_move(t_data *data, double new_x, double new_y)
{
	int			rest;
	t_vector	pos;
	double		alpha;
	int			i;

	pos.x = new_x + data->player.pos.x;
	pos.y = new_y + data->player.pos.y;
	rest = TILE_SIZE / 10;
	i = 0;
	while (i < 360)
	{
		alpha = i * M_PI / 180;
		if (check_wall (data, pos.x + rest * cos(alpha), \
			pos.y + rest * sin(alpha)))
			return (true);
		i++;
	}
	data->player.pos.x += new_x;
	data->player.pos.y += new_y;
	return (false);
}

void	ft_mover(t_data *data, char move)
{
	double	new_x;
	double	new_y;

	new_x = 0;
	new_y = 0;
	if (move == 'D')
	{
		new_x = sin(data->player.angle) * STEPS * -1;
		new_y = cos(data->player.angle) * STEPS;
	}
	if (move == 'A')
	{
		new_x = sin(data->player.angle) * STEPS;
		new_y = cos(data->player.angle) * STEPS * -1;
	}
	if (move == 'S')
	{
		new_x = cos(data->player.angle) * STEPS * -1;
		new_y = sin(data->player.angle) * STEPS * -1;
	}
	if (move == 'W')
	{
		new_x = cos(data->player.angle) * STEPS;
		new_y = sin(data->player.angle) * STEPS;
	}
	check_move(data, new_x, new_y);
}

void	ft_exit(t_data *data)
{
	int	i;

	i = 0;
	mlx_delete_image (data->mlx, data->img);
	mlx_terminate (data->mlx);
	while (i < data->map.height)
	{
		free (data->map.map[i]);
		i++;
	}
	free (data->map.map);
	exit (0);
}

void	move_player(void *ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	if (mlx_is_key_down (data->mlx, MLX_KEY_ESCAPE))
		ft_exit (data);
	if (mlx_is_key_down (data->mlx, MLX_KEY_D))
		ft_mover (data, 'D');
	if (mlx_is_key_down (data->mlx, MLX_KEY_A))
		ft_mover (data, 'A');
	if (mlx_is_key_down (data->mlx, MLX_KEY_W))
		ft_mover (data, 'W');
	if (mlx_is_key_down (data->mlx, MLX_KEY_S))
		ft_mover (data, 'S');
	if (mlx_is_key_down (data->mlx, MLX_KEY_LEFT))
		data->player.angle = norm_angle(data->player.angle - M_PI / 180);
	if (mlx_is_key_down (data->mlx, MLX_KEY_RIGHT))
		data->player.angle = norm_angle(data->player.angle + M_PI / 180);
	render_map (data);
	cast_rays (data);
}
