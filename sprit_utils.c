/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprit_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:55:57 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/11/06 16:46:56 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_paths(char *paths[9])
{
	paths[0] = "gun/01.png";
	paths[1] = "gun/02.png";
	paths[2] = "gun/03.png";
	paths[3] = "gun/04.png";
	paths[4] = "gun/05.png";
	paths[5] = "gun/06.png";
	paths[6] = "gun/07.png";
	paths[7] = "gun/08.png";
	paths[8] = "gun/09.png";
}

void	init_reload_paths(char *paths[9])
{
	paths[0] = "gun/10.png";
	paths[1] = "gun/11.png";
	paths[2] = "gun/12.png";
	paths[3] = "gun/13.png";
	paths[4] = "gun/14.png";
	paths[5] = "gun/15.png";
	paths[6] = "gun/16.png";
	paths[7] = "gun/17.png";
	paths[8] = "gun/18.png";
	paths[9] = "gun/19.png";
	paths[10] = "gun/20.png";
	paths[11] = "gun/21.png";
	paths[12] = "gun/22.png";
	paths[13] = "gun/23.png";
	paths[14] = "gun/24.png";
	paths[15] = "gun/25.png";
}

void	ft_print_bullet(t_data *data)
{
	char	*display_str;

	mlx_delete_image(data->mlx, data->bullet_text);
	display_str = ft_strjoin("Bullets: ", ft_itoa(data->bullets));
	data->bullet_text = mlx_put_string(data->mlx, display_str, 1050, 0);
}
