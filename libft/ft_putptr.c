/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:57:41 by ezahiri           #+#    #+#             */
/*   Updated: 2024/03/29 18:03:19 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(unsigned long n, int flag)
{
	int	count;

	count = 0;
	if (flag == 0)
	{
		count += ft_putstr("0x");
		flag = 1;
	}
	if (n >= 16)
	{
		count += ft_putptr(n / 16, flag);
		count += ft_putptr (n % 16, flag);
	}
	else if (n < 10)
		count += ft_putchar(n + 48);
	else
		count += ft_putchar (n - 10 + 'a');
	return (count);
}
