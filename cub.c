/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:03:00 by ezahiri           #+#    #+#             */
/*   Updated: 2024/11/03 14:58:17 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	player_dirction(t_data *data)
{
	int	i;
	int	j;

	i = data->map.i;
	j = data->map.j;
	if (data->map.map[i][j] == 'N')
		data->player.angle = 3 * M_PI / 2;
	else if (data->map.map[i][j] == 'S')
		data->player.angle = M_PI / 2;
	else if (data->map.map[i][j] == 'E')
		data->player.angle = 0;
	else if (data->map.map[i][j] == 'W')
		data->player.angle = M_PI;
}

void	init_data(t_data *data)
{
	data->player.pos.y = data->map.i * TILE_SIZE + TILE_SIZE / 2;
	data->player.pos.x = data->map.j * TILE_SIZE + TILE_SIZE / 2;
	player_dirction (data);
	data->height = data->map.height * TILE_SIZE;
	data->width = data->map.width * TILE_SIZE;
	data->texture = ft_malloc (sizeof (mlx_texture_t *) * 4, 1);
	data->texture[0] = mlx_load_png (data->no_texture);
	data->texture[1] = mlx_load_png (data->so_texture);
	data->texture[2] = mlx_load_png (data->ea_texture);
	data->texture[3] = mlx_load_png (data->we_texture);
	if (!data->texture[0] || !data->texture[1] || !data->texture[2]
		|| !data->texture[3])
		handl_error_missage("Error\nInvalid texture path");
}

void	f(void)
{
	system("leaks Cub3D");
	system("lsof -c Cub3D");
}

int	main(int ac, char **av)
{
	t_data	data;

	atexit (f);
	get_add(&data);
	if (ac != 2)
	{
		ft_putendl_fd ("Error\ninvalid input", 2);
		return (1);
	}
	ft_memset (&data, 0, sizeof (t_data));
	if (parsing(&data, av[1]) == -1)
		return (1);
	init_data(&data);
	load_wind (&data);
	return (0);
}
