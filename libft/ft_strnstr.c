/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:56:09 by ezahiri           #+#    #+#             */
/*   Updated: 2023/11/17 14:17:59 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nd_len;

	nd_len = ft_strlen(needle);
	if (!len && !haystack)
		return (NULL);
	if (nd_len == 0)
		return ((char *)haystack);
	while (*haystack && len >= nd_len)
	{
		if (*haystack == *needle && ft_strncmp(haystack, needle, nd_len) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
