/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:21:41 by ezahiri           #+#    #+#             */
/*   Updated: 2024/11/05 23:14:41 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_close(void)
{
	int	i;

	i = 3;
	while (1)
	{
		if (close (i) == -1)
			break ;
		i++;
	}
}

void	free_txt(t_data *data)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (data->texture[i] != NULL && i < 5)
			mlx_delete_texture (data->texture[i]);
		else if (data->shoot[i] != NULL && i < 9)
			mlx_delete_texture (data->shoot[i]);
		else if (data->reload[i] != NULL && i < 16)
			mlx_delete_texture (data->reload[i]);
		i++;
	}
}

void	ft_exit(int i)
{
	t_data	*data;

	data = get_add(NULL);
	if (data->texture)
		free_txt (data);
	if (data->mlx && data->img)
		mlx_delete_image (data->mlx, data->img);
	if (data->mlx)
		mlx_terminate (data->mlx);
	ft_malloc(0, 0);
	ft_close();
	exit (i);
}
