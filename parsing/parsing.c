/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:10:49 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/11/04 08:58:59 by sel-hasn         ###   ########.fr       */
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
	data->map.map = ft_split(s, '\n', true);
	if (tmp_line[ft_strlen(tmp_line) - 1] == '\n')
	{
		close(fd);
		handl_error_missage("Error\nInvalid map7");
	}
	close(fd);
	return (0);
}

void	parse_map_member_bonus(t_data *data)
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
			add_map_bonus(data, i);
			break ;
		}
	}
	if (data->map.map[i] == NULL)
		handl_error_missage("Error\nEmpty map");
}

void	get_all_doors(t_data *d)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	t = 0;
	d->doors = ft_malloc(sizeof(t_door) * d->map.door_counter, 1);
	ft_memset(d->doors, 0, sizeof(t_door));
	while (d->map.map[i])
	{
		j = 0;
		while (d->map.map[i][j])
		{
			if (d->map.map[i][j] == 'D')
			{
				d->doors[t].i = i;
				d->doors[t].j = j;
				d->doors[t].stat = 'C';
				t++;
			}
			j++;
		}
		i++;
	}
}

void	parsing_bonus(t_data *data, char *av)
{
	int	fd;

	if (check_valide_map_name(av) == -1)
		handl_error_missage("Error\nInvalib map name");
	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_putstr_fd("Error\ncan't open the map", 2);
	get_all_map(data, fd);
	parse_map_member_bonus(data);
	get_all_doors(data);
}
