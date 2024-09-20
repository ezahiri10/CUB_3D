/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:33:11 by ezahiri           #+#    #+#             */
/*   Updated: 2024/08/26 16:04:58 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	cpt;

	cpt = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			cpt++;
		s++;
	}
	return (cpt);
}

static char	**splited(char **strs, const char *s, char c)
{
	int	i;
	int	k;

	k = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		i = 0;
		if (*s)
		{
			while (s[i] && s[i] != c)
				i++;
			strs[k] = (char *)ft_malloc(i + 1, 1);
			ft_strlcpy(strs[k], s, i + 1);
			s += i;
			k++;
		}
	}
	strs[k] = 0;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;

	if (!s)
		return (NULL);
	strs = (char **)ft_malloc (sizeof(char *) * (count_words(s, c) + 1), 1);
	if (!strs)
		return (NULL);
	strs = splited(strs, s, c);
	return (strs);
}
