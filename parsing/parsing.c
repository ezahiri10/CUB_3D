/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:10:49 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/10/10 14:55:01 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	handl_error_missage(char *missage)
{
	ft_putstr_fd(missage, 2);
	ft_malloc(0, 2);
	exit(1);
}

int check_valide_map_name(char *map_name)
{
	int     i;
	int     len;
	char    *cub;

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

int get_all_map(t_data *data, int fd)
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

int	is_textur_or_F_C(char *line)
{
	int i;

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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_skipe_spaces(char *line, int i)
{
	while (line[i] == ' ' && line[i] != '\0')
		i++;
	return (i);
}

void	add_colors(char **colors, t_data *data, int type)
{
	int nb_color[4];

	(void)data;
	nb_color[0] = ft_atoi(colors[0]);
	nb_color[1] = ft_atoi(colors[1]);
	nb_color[2] = ft_atoi(colors[2]);
	if ((nb_color[0] >= 0 && nb_color[0] <= 255)
	&& (nb_color[1] >= 0 && nb_color[1] <= 255)
	&& (nb_color[2] >= 0 && nb_color[2] <= 255))
	{
		if (type == 1)
		{
			printf("floor :");
			data->map.floor = rgb(nb_color[0], nb_color[1], nb_color[2], 255);
		}
		else if (type == 2)
		{
			printf("ceiling :");
			data->map.ceiling = rgb(nb_color[0], nb_color[1], nb_color[2], 255);
		}
		printf(" %d, %d, %d\n", nb_color[0], nb_color[1], nb_color[2]);
	}
	else
		handl_error_missage("Error\nInvalid color");
}

void	get_color(char *line, t_data *data, int type)
{
	int		i;
	int		cama;
	char	**colors;

	i = 0;
	cama = 0;
	(void)data;
	while (line[i] != '\0')
	{
		i = ft_skipe_spaces(line, i);
		while (line[i] && ft_isdigit(line[i]))
			i++;
		i = ft_skipe_spaces(line, i);
		if (line[i] == '\0')
			break ;
		else if (line[i] == ',')
			cama++;
		else
			handl_error_missage("Error\nInvalid color");
		i++;
	}
	if (cama != 2)
		handl_error_missage("Error\nInvalid color");
	colors = ft_split(line, ',');
	add_colors(colors, data, type);
}

void	add_textur_or_F_C(char *line, t_data *data, int *elem)
{
	int i;

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

void ft_copy_map(char **map, t_data *data, int start_index, int size)
{
    int j = 0;
    int i;

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
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1' || line[i] == ' ')
			i++;
		else
			handl_error_missage("Error\nInvalid map");
	}
}

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

int	is_map_member_or_space(char c)
{
	if (c == '1' || c == '0' || c == ' ' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	check_map_member(t_data *data, char **map, int size)
{
	int i;
	int j;
	int player_counter;

	i = 0;
	player_counter = 0;
	(void)data;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
            if (i == 0 || i == size - 1)
            {
                handle_start_last_of_map(map[i]);
                break ;
            }
			else if (is_map_member_or_space(map[i][j]))
			{
				if (map[i][j] == '0' || is_player(map[i][j]))
				{
					if (is_player(map[i][j]))
					{
						data->map.j = j;
						data->map.i = i;
						player_counter++;
						// printf ("data->map.map[i][j] = %c\n" ,data->map.map[i][j]);
					}
					if (is_map_member(map[i][j + 1]) && is_map_member(map[i][j - 1])
						&& is_map_member(map[i + 1][j]) && is_map_member(map[i - 1][j]))
						j++;
					// if ((map[i][j + 1] == '1' || map[i][j + 1] == '0' || is_player(map[i][j + 1]))
					// && (map[i][j - 1] == '1' || map[i][j - 1] == '0' || is_player(map[i][j - 1]))
					// && (map[i - 1][j] == '1' || map[i - 1][j] == '0' || is_player(map[i - 1][j]))
					// && (map[i + 1][j] == '1' || map[i + 1][j] == '0' || is_player(map[i + 1][j])))
					// 	j++;
					else
						handl_error_missage("Error\nInvalid map");
				}
				else if (map[i][j] == ' ' || map[i][j] == '1')
					j++;
			}
			else
				handl_error_missage("Error\nInvalid map");
		}
		i++;
	}
	if (player_counter != 1)
		handl_error_missage("Error\nInvalid map");
}

void add_map(t_data *data, int i)
{
    int     j;
    char    **map;
    size_t  max_len;

    j = i;
    max_len = ft_strlen(data->map.map[i]);
    while (data->map.map[i] != NULL)
    {
        if (max_len < ft_strlen(data->map.map[i]))
            max_len = ft_strlen(data->map.map[i]);
		if (data->map.map[i][0] == '\0')
			handl_error_missage("Error\nInvalid map");
        i++;
    }
	data->map.height = (i - j);
	data->map.width = max_len;
    map = (char **)ft_malloc(sizeof(char *) * ((i - j) + 1), 1);
    ft_memset(map, 0, sizeof(char *) * ((i - j) + 1));
    ft_copy_map(map, data, j, i - j);
	check_map_member(data, map, i - j);
	data->map.map = map;
}

void	parse_map_member(t_data *data)
{
	int i;
	int elem;

	i = 0;
	elem = 0;
	while (data->map.map[i])
	{
		if (data->map.map[i][0] == '\0')
			i++;
		else if (is_textur_or_F_C(data->map.map[i]) == 1)
		{
			add_textur_or_F_C(data->map.map[i], data, &elem);
			i++;
		}
		else
		{
			if (elem != 6)
				handl_error_missage("Error\nInvalid map");
			add_map(data, i);
			break ;
		}
	}
}

int parsing(t_data *data, int fd)
{
	int i = 0;

	get_all_map(data, fd);
	parse_map_member(data);
	printf("ceiling '%u'\n", data->map.ceiling);
	printf("floor '%u'\n", data->map.floor);
	printf("'%s'\n", data->no_texture);
	printf("'%s'\n", data->so_texture);
	printf("'%s'\n", data->we_texture);
	printf("'%s'\n", data->ea_texture);
	while (data->map.map[i])
	{
		printf("[i]%d '%s'\n", i, data->map.map[i]);
		i++;
	}
	printf("player i :%d player j :%d\n", data->map.j, data->map.i);
	printf("map width :%d map height :%d\n", data->map.width, data->map.height);
	return (0);
}
