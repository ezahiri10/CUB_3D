/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 06:28:17 by ezahiri           #+#    #+#             */
/*   Updated: 2024/11/07 15:11:42 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

void	*ft_memset(void *b, int c, size_t len)
{
	while (len--)
		*(unsigned char *)(b + len) = (unsigned char )c;
	return (b);
}
