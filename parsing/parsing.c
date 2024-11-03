/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:10:49 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/10/28 20:36:36 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	check_valide_map_name(char *map_name)
{
	int		i;
	int		len;
	char	*cub;

	cub = ".cub";
	len = (ft_strlen(map_name) - 4);
	i = 0;
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
	data->map.map = ft_divide(s, '\n');
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

int	parsing(t_data *data, char *av)
{
	int	fd;

	if (check_valide_map_name(av) == -1)
		handl_error_missage("Error\nInvalib map name");
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error\ncan't open the map", 2), -1);
	get_all_map(data, fd);
	parse_map_member(data);
	printf("'%s'\n", data->no_texture);
	printf("'%s'\n", data->so_texture);
	printf("'%s'\n", data->we_texture);
	printf("'%s'\n", data->ea_texture);
	return (0);
}
