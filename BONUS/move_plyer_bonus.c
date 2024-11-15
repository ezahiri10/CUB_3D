/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_plyer_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:18:10 by ezahiri           #+#    #+#             */
/*   Updated: 2024/11/07 15:11:42 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

bool	ft_check_wall(t_data *data, double x, double y)
{
	int	i;
	int	j;

	i = (int)floor(y / TILE_SIZE);
	j = (int)floor(x / TILE_SIZE);
	if (i < 0 || j < 0 || j >= data->map.width || i >= data->map.height)
		return (true);
	if (data->map.map[i][j] == '1')
		return (true);
	if (check_door(data, x, y) == true)
		return (true);
	return (false);
}

bool	check_move(t_data *data, double new_x, double new_y)
{
	int			rest;
	t_vector	pos;
	double		alpha;
	int			i;

	i = 0;
	pos.x = new_x + data->player.pos.x;
	pos.y = new_y + data->player.pos.y;
	rest = TILE_SIZE / 4;
	while (i < 360)
	{
		alpha = i * M_PI / 180;
		if (ft_check_wall (data, pos.x + rest * cos(alpha), \
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
	t_vector	pos;

	ft_memset (&pos, 0, sizeof (pos));
	if (move == 'D')
	{
		pos.x = sin(data->player.angle) * STEPS * -1;
		pos.y = cos(data->player.angle) * STEPS;
	}
	if (move == 'A')
	{
		pos.x = sin(data->player.angle) * STEPS;
		pos.y = cos(data->player.angle) * STEPS * -1;
	}
	if (move == 'S')
	{
		pos.x = cos(data->player.angle) * STEPS * -1;
		pos.y = sin(data->player.angle) * STEPS * -1;
	}
	if (move == 'W')
	{
		pos.x = cos(data->player.angle) * STEPS;
		pos.y = sin(data->player.angle) * STEPS;
	}
	check_move(data, pos.x, pos.y);
}

void	move_player(t_data *data)
{
	if (mlx_is_key_down (data->mlx, MLX_KEY_ESCAPE))
		ft_exit (0);
	if (mlx_is_key_down (data->mlx, MLX_KEY_D))
		ft_mover (data, 'D');
	if (mlx_is_key_down (data->mlx, MLX_KEY_A))
		ft_mover (data, 'A');
	if (mlx_is_key_down (data->mlx, MLX_KEY_W))
		ft_mover (data, 'W');
	if (mlx_is_key_down (data->mlx, MLX_KEY_S))
		ft_mover (data, 'S');
	if (mlx_is_key_down (data->mlx, MLX_KEY_LEFT))
		data->player.angle = norm_angle(data->player.angle - 3 * M_PI / 180);
	if (mlx_is_key_down (data->mlx, MLX_KEY_RIGHT))
		data->player.angle = norm_angle(data->player.angle + 3 * M_PI / 180);
	cast_rays (data);
}
