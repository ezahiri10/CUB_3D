/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:21:41 by ezahiri           #+#    #+#             */
/*   Updated: 2024/11/04 14:30:01 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	handl_error_missage(char *missage)
{
	ft_putstr_fd(missage, 2);
	ft_exit(1);
}

void	ft_close (void)
{
	int i;

	i = 3;
	while (1)
	{
		if (close (i) == -1)
			break ;
		i++;
	}
}

void free_txt (mlx_texture_t	**txt)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (txt[i] != NULL)
			mlx_delete_texture (txt[i]);
		i++;
	}
}
void	ft_exit(int i)
{
	t_data	*data;

	data = get_add(NULL);
	if (data->texture)
		free_txt (data->texture);
	if (data->mlx && data->img)
		mlx_delete_image (data->mlx, data->img);
	if (data->mlx)
		mlx_terminate (data->mlx);
	ft_malloc (0, 0);
	ft_close ();
	exit (i);
}
