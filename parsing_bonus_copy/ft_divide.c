/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_divide.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:54:54 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/10/27 18:43:17 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int	count_words(const char *s, char c)
{
	int	cpt;

	cpt = 0;
	while (*s)
	{
		if (*s == c)
			cpt++;
		s++;
	}
	return (cpt + 1);
}

static char	**splited(char **strs, const char *s, char c)
{
	int	i;
	int	k;

	k = 0;
	while (*s)
	{
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		if (s[i] == c)
			i++;
		strs[k] = (char *)ft_malloc(i + 1, 1);
		ft_strlcpy(strs[k], s, i + 1);
		s += i;
		k++;
	}
	strs[k] = NULL;
	return (strs);
}

char	*ft_remove_char(char *s, unsigned int index)
{
	unsigned int	i;
	int				j;
	char			*str;

	i = 0;
	j = 0;
	if (ft_strlen(s) < index || !s)
		return (NULL);
	str = ft_malloc(ft_strlen(s), 1);
	while (s[i] != '\0')
	{
		if (i == index)
			i++;
		else
			str[j++] = s[i++];
	}
	str[j] = '\0';
	return (str);
}

void	remove_new_line(char **lines)
{
	int	i;
	int	j;

	i = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] == '\n')
				lines[i] = ft_remove_char(lines[i], j);
			j++;
		}
		i++;
	}
}

char	**ft_divide(char const *s, char c)
{
	char	**strs;

	if (!s)
		return (NULL);
	strs = (char **)ft_malloc(sizeof(char *) * (count_words(s, c) + 1), 1);
	if (!strs)
		return (NULL);
	strs = splited(strs, s, c);
	remove_new_line(strs);
	return (strs);
}
