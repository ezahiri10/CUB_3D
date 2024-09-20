/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:03:00 by ezahiri           #+#    #+#             */
/*   Updated: 2024/09/20 11:46:19 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_data(t_data *data)
{
	data->map.map = (char **)malloc (sizeof (char *) * 20);
	data->map.map[0] = ft_strdup ("111111111111111111111111111111");
	data->map.map[1] = ft_strdup ("100000000000000000000000000001");
	data->map.map[2] = ft_strdup ("100000000000000000000000000001");
	data->map.map[3] = ft_strdup ("100000000000000000000000000001");
	data->map.map[4] = ft_strdup ("100000000000000000000000000001");
	data->map.map[5] = ft_strdup ("100000000010000000000000000001");
	data->map.map[6] = ft_strdup ("100000000000000000000000000001");
	data->map.map[7] = ft_strdup ("100000000000000110000000000001");
	data->map.map[8] = ft_strdup ("100000000000000000000000000001");
	data->map.map[9] = ft_strdup ("100000000000000000000000000001");
	data->map.map[10] = ft_strdup ("1000000000000P0000000000000001");
	data->map.map[11] = ft_strdup ("100000000000000000000000000001");
	data->map.map[12] = ft_strdup ("100000000000000000000000000001");
	data->map.map[13] = ft_strdup ("111111111111110111111111111111");
	data->map.map[14] = ft_strdup ("100000000000000000000000000001");
	data->map.map[15] = ft_strdup ("100000000000000000000000000001");
	data->map.map[16] = ft_strdup ("100000000000000000000000000001");
	data->map.map[17] = ft_strdup ("100000000000000000000000000001");
	data->map.map[18] = ft_strdup ("111111111111111111111111111111");
	data->map.map[19] = NULL;
	data->map.height = 19;
	data->map.width = 30;
	data->map.i = 13;
	data->map.j = 10;
	data->map.floor = rgb (220, 100, 0, 255);
	data->map.ceiling = rgb (225, 30, 0, 255);
	data->player.pos.x = data->map.i * TILE_SIZE + TILE_SIZE / 2;
	data->player.pos.y = data->map.j * TILE_SIZE + TILE_SIZE / 2;
	data->player.angle = M_PI / 2;
	data->height = data->map.height * TILE_SIZE;
	data->width = data->map.width * TILE_SIZE;
	data->texture = malloc (sizeof (mlx_texture_t *) * 4);
	data->texture[0] = mlx_load_png ("textur/sh3.png");
	data->texture[1] = mlx_load_png ("textur/uchi1.png");
	data->texture[2] = mlx_load_png ("textur/uchi2.png");
	data->texture[3] = mlx_load_png ("textur/uchi3.png");
}

int	main(int ac, char **av)
{
	t_data	data;

	(void)ac;
	(void)av;
	ft_memset (&data, 0, sizeof (t_data));
	init_data(&data);
	load_wind (&data);
	return (0);
}
	// if (ac != 2)
	// {
	// 	ft_putendl_fd ("invalid input", 2);
	// 	return (1);
	// }