/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:21:56 by ezahiri           #+#    #+#             */
/*   Updated: 2024/10/08 14:37:29 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "/Users/sel-hasn/Desktop/CUB_3D/MLX42/include/MLX42/MLX42.h"


#define RED 0xFF0000FF
# define TILE_SIZE 40
# define H_S 1000
# define W_S 1000
# define FOV	60 * M_PI / 180 
# define STEPS 10
# define ROT 2
# define RAY TILE_SIZE / 10
# define BLUE 0x0000FFFF
# define GREEN 0x00FF00FF

typedef unsigned char t_color;

typedef struct s_vector
{
	double	x;
	double	y;
}		t_vector;

typedef struct s_map
{
	char		**map;
	int			i;
	int			j;
	int			width;
	int			height;
	uint32_t	floor;
	uint32_t	ceiling;
}			t_map;

typedef struct s_player
{
	double		angle;
	t_vector	pos;
}		t_player;

typedef struct s_ray
{
	int 		j;
	double		distance;
	double		angle;
	char		left_right;
	char		up_down;
	t_vector	steps;
	t_vector	pos_wall;
	t_vector	inter_v;
	t_vector	inter_h;
	t_vector	p_txt;
	char		h_or_v;
	double			line;
}			t_ray;

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	**texture;
	char			*no_texture;
	char			*so_texture;
	char			*we_texture;
	char			*ea_texture;
	uint32_t 		*txt;
	t_ray			*ray;
	t_player		player;
	double			width;
	double			height;
	t_map			map;
}				t_data;

uint32_t	rgb(t_color r, t_color g, t_color b, t_color a);
void		load_wind(t_data *data);
void		render_map(t_data *data);
void		move_player(void *ptr);
double		norm_angle(double angle);
void		cast_rays(t_data *data);
void		dda(t_data *data, t_vector init_p, t_vector finl_p);
double		calcul_dis(t_data *data, t_vector pos);
void 		render_wall (t_data *data);
bool		check_pixel(double x, double y, t_data *data);
void		first_point_h(t_data *data, int i);
void		first_point_v(t_data *data, int i);
void		get_derictions(t_data *data, int i);
bool		check_wall(t_data *data, double x, double y);
void		draw_3d(t_data *data);
uint32_t	get_texture_pixel(mlx_texture_t *texture, int x, int y);
void		put_pixel(mlx_image_t *img, double x, double y, double color);
uint32_t	get_texture_pixel(mlx_texture_t *texture, int x, int y);

//get_line

char	*get_line(int fd);
char	*line(char *s);
char	*rest_of_str(char *s);
char	*read_line(char *s, int fd);
size_t	ft_countlen(const char *s);
int		ft_newline(char *s);

//parsin

int		check_valide_map_name(char *map_name);
int		parsing(t_data *data, int fd);
void	handl_error_missage(char *missage);
char	**ft_divide(char const *s, char c);

#endif 