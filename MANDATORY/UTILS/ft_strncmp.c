/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:22:38 by ezahiri           #+#    #+#             */
/*   Updated: 2024/11/02 21:54:49 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && n > 0)
	{
		if (*s1 != *s2)
			return ((unsigned char )*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
