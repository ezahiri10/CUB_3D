/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:01:27 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/10/27 22:16:13 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	add_colors(char **colors, t_data *data, int type)
{
	int	nb_color[4];

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

void	validate_color_format(char *line, int cama, int i)
{
	int	j;

	while (line[i] != '\0')
	{
		i = ft_skipe_spaces(line, i);
		j = i;
		while (line[i] && ft_isdigit(line[i]))
			i++;
		if (i == j)
			handl_error_missage("Error\nInvalid color");
		i = ft_skipe_spaces(line, i);
		if (line[i] == '\0')
			break ;
		else if (line[i] == ',')
			cama++;
		else
			handl_error_missage("Error\nInvalid color");
		i++;
		if (line[i] == '\0')
			handl_error_missage("Error\nInvalid color");
	}
	if (cama != 2)
		handl_error_missage("Error\nInvalid color");
}

void	get_color(char *line, t_data *data, int type)
{
	validate_color_format(line, 0, 0);
	add_colors(ft_split(line, ','), data, type);
}
