/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_member.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:11:44 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/10/27 22:12:09 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	add_textur_or_f_c(char *line, t_data *data, int *elem)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] == ' ')
		i++;
	if (ft_strncmp(&line[i], "NO ", 3) == 0)
		data->no_texture = ft_strtrim(&line[i + 2], " ");
	else if (ft_strncmp(&line[i], "SO ", 3) == 0)
		data->so_texture = ft_strtrim(&line[i + 2], " ");
	else if (ft_strncmp(&line[i], "WE ", 3) == 0)
		data->we_texture = ft_strtrim(&line[i + 2], " ");
	else if (ft_strncmp(&line[i], "EA ", 3) == 0)
		data->ea_texture = ft_strtrim(&line[i + 2], " ");
	else if (ft_strncmp(&line[i], "F ", 2) == 0)
		get_color(ft_strtrim(&line[i + 1], " "), data, 1);
	else if (ft_strncmp(&line[i], "C ", 2) == 0)
		get_color(ft_strtrim(&line[i + 1], " "), data, 2);
	(*elem)++;
}

void	ft_copy_map(char **map, t_data *data, int start_index, int size)
{
	int	j;
	int	i;

	j = 0;
	while (j < size && data->map.map[start_index + j])
	{
		map[j] = ft_malloc(data->map.width + 1, 1);
		ft_strlcpy(map[j], data->map.map[start_index + j], data->map.width + 1);
		i = ft_strlen(map[j]);
		while (i < data->map.width)
		{
			map[j][i] = ' ';
			i++;
		}
		map[j][data->map.width] = '\0';
		j++;
	}
	map[j] = NULL;
}

void	handle_start_last_of_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1' || line[i] == ' ')
			i++;
		else
			handl_error_missage("Error\nInvalid map");
	}
}
