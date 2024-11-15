/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:55:21 by ezahiri           #+#    #+#             */
/*   Updated: 2024/11/07 15:11:42 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	put_pixel(mlx_image_t *img, double x, double y, double color)
{
	if (x < 0 || x >= W_S)
		return ;
	if (y < 0 || y >= H_S)
		return ;
	mlx_put_pixel (img, x, y, color);
}
