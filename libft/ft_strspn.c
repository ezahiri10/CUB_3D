/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:43:54 by ezahiri           #+#    #+#             */
/*   Updated: 2024/04/29 18:17:47 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(const char *s, const char *set)
{
	int	i;
	int	j;
	int	cpt;

	cpt = 0;
	j = 0;
	i = 0;
	while (s[i])
	{
		j = 0;
		while (set[j])
		{
			if (s[i] == set[j])
			{
				cpt++;
				break ;
			}
			j++;
		}
		if (set[j] == '\0')
			return (cpt);
		i++;
	}
	return (cpt);
}
