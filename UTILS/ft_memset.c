/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 06:28:17 by ezahiri           #+#    #+#             */
/*   Updated: 2024/11/02 21:57:40 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	*ft_memset(void *b, int c, size_t len)
{
	while (len--)
		*(unsigned char *)(b + len) = (unsigned char )c;
	return (b);
}
