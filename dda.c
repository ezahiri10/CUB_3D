/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:55:21 by ezahiri           #+#    #+#             */
/*   Updated: 2024/11/05 22:27:40 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	put_pixel(mlx_image_t *img, double x, double y, double color)
{
	if (x < 0 || x >= W_S)
		return ;
	if (y < 0 || y >= H_S)
		return ;
	mlx_put_pixel (img, x, y, color);
}

// void	dda(t_data *data, t_vector init_p, t_vector finl_p)
// {
// 	t_vector	dpos;
// 	t_vector	posinc;
// 	double		steps;
// 	int			i;

// 	i = 0;
// 	dpos.x = finl_p.x - init_p.x;
// 	dpos.y = finl_p.y - init_p.y;
// 	if (fabs(dpos.x) > fabs(dpos.y))
// 		steps = fabs(dpos.x);
// 	else
// 		steps = fabs(dpos.y);
// 	posinc.x = dpos.x / steps;
// 	posinc.y = dpos.y / steps;
// 	while (i <= steps)
// 	{
// 		if (init_p.x < 0 || init_p.x >= W_S || init_p.y < 0 || init_p.y >= H_S)
// 			break ;
// 		put_pixel(data->img, init_p.x, init_p.y, rgb (0, 0, 0, 255));
// 		init_p.x += posinc.x;
// 		init_p.y += posinc.y;
// 		i++;
// 	}
// }
