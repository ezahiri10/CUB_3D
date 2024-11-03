/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:10:49 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/11/03 15:50:44 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	check_valide_map_name(char *map_name)
{
	char	*cub;
	int		len;
	int		i;

	i = 0;
	cub = ".cub";
	len = (ft_strlen(map_name) - 4);
	while (map_name[len])
	{
		if (cub[i] == map_name[len])
			i++;
		len++;
	}
	if (cub[i] == '\0')
		return (0);
	return (-1);
}

int	get_all_map(t_data *data, int fd)
{
	char	*line;
	char	*tmp_line;
	char	*s;

	s = NULL;
	line = get_line(fd);
	if (!line)
	{
		close(fd);
		handl_error_missage("Error\nEmpty map");
	}
	while (line)
	{
		s = ft_strjoin(s, line);
		tmp_line = line;
		line = get_line(fd);
	}
	data->map.map = ft_split(s, '\n', true);
	if (tmp_line[ft_strlen(tmp_line) - 1] == '\n')
		handl_error_missage("Error\nInvalid map");
	close(fd);
	return (0);
}

void	parse_map_member(t_data *data)
{
	int	i;
	int	elem;

	i = 0;
	elem = 0;
	while (data->map.map[i])
	{
		if (data->map.map[i][0] == '\0')
			i++;
		else if (is_textur_or_f_c(data->map.map[i]) == 1)
		{
			add_textur_or_f_c(data->map.map[i], data, &elem);
			i++;
		}
		else
		{
			if (elem != 6)
				handl_error_missage("Error\nInvalid map member");
			add_map(data, i);
			break ;
		}
	}
}

void	parsing(t_data *data, char *av)
{
	int	fd;

	if (check_valide_map_name(av) == -1)
		handl_error_missage("Error\nInvalib map name");
	fd = open(av, O_RDONLY);
	if (fd == -1)
		handl_error_missage("Error\ncan't open the map");
	get_all_map(data, fd);
	parse_map_member(data);
}
