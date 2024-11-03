/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:01:51 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/10/27 22:13:10 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	is_map_member(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] == ' ')
		i++;
	if (ft_strncmp(&line[i], "NO ", 3) == 0)
		return (1);
	else if (ft_strncmp(&line[i], "SO ", 3) == 0)
		return (1);
	else if (ft_strncmp(&line[i], "WE ", 3) == 0)
		return (1);
	else if (ft_strncmp(&line[i], "EA ", 3) == 0)
		return (1);
	else if (ft_strncmp(&line[i], "F ", 2) == 0)
		return (1);
	else if (ft_strncmp(&line[i], "C ", 2) == 0)
		return (1);
	return (0);
}
