/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 02:18:00 by ezahiri           #+#    #+#             */
/*   Updated: 2024/08/26 15:58:26 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(int n)
{
	int	len;

	if (n <= 0)
		len = 2;
	else
		len = 1;
	while (n != 0 && ++len)
		n /= 10;
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	long int	tmp;

	tmp = n;
	len = count_len(n);
	str = (char *) ft_malloc(len, 1);
	if (!str)
		return (NULL);
	str[--len] = '\0';
	if (tmp < 0)
		str[0] = '-';
	else if (tmp == 0)
		str[0] = '0';
	while (tmp != 0)
	{
		if (tmp < 0)
			str[--len] = -tmp % 10 + 48;
		else
			str[--len] = tmp % 10 + 48;
		tmp /= 10;
	}
	return (str);
}
