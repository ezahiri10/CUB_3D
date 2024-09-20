/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:23:47 by ezahiri           #+#    #+#             */
/*   Updated: 2024/03/29 18:03:20 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *str)
{
	int	count;

	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	count = 0;
	while (*str)
		count += ft_putchar(*str++);
	return (count);
}
