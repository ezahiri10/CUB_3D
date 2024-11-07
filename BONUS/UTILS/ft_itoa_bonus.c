/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:02:21 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/11/07 15:11:42 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

static int	nbrlen(int nbr)
{
	int				i;
	long long int	n;

	n = nbr;
	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				len;
	long long int	nb;
	char			*s;

	len = nbrlen(n);
	nb = n;
	if (n < 0)
		nb = -nb;
	s = ft_malloc(sizeof(char) * (len + 1), 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (nb == 0)
		s[0] = '0';
	else
	{
		if (n < 0)
			s[0] = '-';
		while (nb != 0 && len-- >= 0)
		{
			s[len] = (nb % 10) + 48;
			nb = (nb / 10);
		}
	}
	return (s);
}
