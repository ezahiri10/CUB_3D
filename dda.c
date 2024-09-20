/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:55:21 by ezahiri           #+#    #+#             */
/*   Updated: 2024/09/11 13:06:52 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void put_pixel(mlx_image_t *img, double x, double y, double color , t_data *data)
{
    if (x < 0 || x >= data->width)
        return ;
    if (y < 0 || y >= data->height)
        return ;
    mlx_put_pixel (img, x, y, color);
}

void DDA(double X0, double Y0, double X1, double Y1, t_data *data)
{
    double dx = X1 - X0; 
    double dy = Y1 - Y0; 


    double steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy); 
    double Xinc = dx / (double)steps; 
    double Yinc = dy / (double)steps; 
    double X = X0;
    double Y = Y0;
    for (double i = 0; i <= steps; i++) 
    {
            if (X < 0 || X >= data->width || (Y < 0 || Y >= data->height))
                break ;
            put_pixel(data->img, X , Y, rgb (0, 0, 0, 255), data);
            X += Xinc;
            Y += Yinc;
    }
}
