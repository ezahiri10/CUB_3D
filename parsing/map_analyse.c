/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_analyse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:01:02 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/11/06 15:14:49 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	is_map_member_or_space_bonus(char c)
{
	if (c == '1' || c == '0' || c == ' ' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W' || c == 'D')
		return (1);
	return (0);
}

bool	handle_door(t_data *data, char **map, int i, int j)
{
	if (map[i][j] != 'D')
		return (true);
	else
	{
		if ((map[i][j + 1] == '1' && map[i][j - 1] == '1')
			|| (map[i + 1][j] == '1' && map[i - 1][j] == '1'))
		{
			data->map.door_counter++;
			return (true);
		}
		else
			handl_error_missage("Error\nInvalid door");
	}
	return (false);
}

int	check_map_position(t_data *data, char **map, int i, int j)
{
	int	player_counter;

	player_counter = 0;
	if (map[i][j] == '0' || is_player(map[i][j]) || map[i][j] == 'D')
	{
		if (is_player(map[i][j]))
		{
			data->map.j = j;
			data->map.i = i;
			player_counter = 1;
		}
		if (is_map_member_bonus(map[i][j + 1]) &&
			is_map_member_bonus(map[i][j - 1]) &&
			is_map_member_bonus(map[i + 1][j]) &&
			is_map_member_bonus(map[i - 1][j]) &&
			handle_door(data, map, i, j) == true)
			return (player_counter);
		else
			handl_error_missage("Error\nInvalid map");
	}
	else if (map[i][j] != ' ' && map[i][j] != '1')
		handl_error_missage("Error\nInvalid map");
	return (player_counter);
}

void	check_map_member_bonus(t_data *data, char **map, int size
	, int player_counter)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		if (i == 0 || i == size - 1)
			handle_start_last_of_map(map[i]);
		else
		{
			while (map[i][j])
			{
				if (is_map_member_or_space_bonus(map[i][j]))
					player_counter += check_map_position(data, map, i, j);
				else
					handl_error_missage("Error\nInvalid map");
				j++;
			}
		}
		i++;
	}
	if (player_counter != 1)
		handl_error_missage("Error\nInvalid map");
}

void	add_map_bonus(t_data *data, int i)
{
	int		j;
	char	**map;
	size_t	max_len;

	j = i;
	max_len = ft_strlen(data->map.map[i]);
	while (data->map.map[i] != NULL)
	{
		if (max_len < ft_strlen(data->map.map[i]))
			max_len = ft_strlen(data->map.map[i]);
		if (data->map.map[i][0] == '\0')
			handl_error_missage("Error\nInvalid map5");
		i++;
	}
	if (i == j)
		handl_error_missage("Error\nEmpty map");
	data->map.height = (i - j);
	data->map.width = max_len;
	map = (char **)ft_malloc(sizeof(char *) * ((i - j) + 1), 1);
	ft_memset(map, 0, sizeof(char *) * ((i - j) + 1));
	ft_copy_map(map, data, j, i - j);
	check_map_member_bonus(data, map, i - j, 0);
	data->map.map = map;
}
