/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:25:59 by ezahiri           #+#    #+#             */
/*   Updated: 2024/11/06 10:26:35 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


void    mouse_events(double x, double y, void *para)
{
    t_data      *data;
    t_vector    pos;

    data = para;
    pos.x = x;
    pos.y = y;

    // printf ("x00 = %f\ty00 = %f\n", x, y);
    mlx_set_mouse_pos (data->mlx, W_S / 2, H_S / 2);
    if (x > W_S / 2)
        data->player.angle = norm_angle(data->player.angle + 2 * M_PI / 180);
    else if (x < W_S / 2)
        data->player.angle = norm_angle(data->player.angle - 2 * M_PI / 180);
        
    // printf ("x0 = %f\ty0 = %f\n", x, y);
}