/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:51:47 by ezahiri           #+#    #+#             */
/*   Updated: 2024/11/07 17:14:30 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

long	ft_atoi(const char *str)
{
	long	r;
	int		s;

	r = 0;
	s = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		s = 1 - 2 * (*str == '-');
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		r = r * 10 + (*str - 48);
		if ((r > 1000 && s == 1) || (r > 1000 && s == -1))
			return (1000);
		str++;
	}
	return (r * s);
}
