/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:01:51 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/11/07 21:05:12 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	is_map_member_bonus(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == 'D')
		return (1);
	return (0);
}

int	ft_skipe_spaces(char *line, int i)
{
	while (line[i] != '\0' && line[i] == ' ')
		i++;
	return (i);
}

int	is_textur_or_f_c(char *line)
{
	int			i;
	static int	elme_check[6];

	i = 0;
	while (line[i] != '\0' && line[i] == ' ')
		i++;
	if (ft_strncmp(&line[i], "NO ", 3) == 0)
		return (elme_check[0]++, 1);
	else if (ft_strncmp(&line[i], "SO ", 3) == 0)
		return (elme_check[1]++, 1);
	else if (ft_strncmp(&line[i], "WE ", 3) == 0)
		return (elme_check[2]++, 1);
	else if (ft_strncmp(&line[i], "EA ", 3) == 0)
		return (elme_check[3]++, 1);
	else if (ft_strncmp(&line[i], "F ", 2) == 0)
		return (elme_check[4]++, 1);
	else if (ft_strncmp(&line[i], "C ", 2) == 0)
		return (elme_check[5]++, 1);
	i = 0;
	while (i < 6)
	{
		if (elme_check[i++] != 1)
			return (2);
	}
	return (0);
}
