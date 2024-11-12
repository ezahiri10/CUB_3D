/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:21:56 by ezahiri           #+#    #+#             */
/*   Updated: 2024/11/08 10:20:47 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include <math.h>
# include <fcntl.h>
# include "../MLX42/.MLX42.h"

# define TILE_SIZE 40
# define H_S 864
# define W_S 1200
# define STEPS 10
# define FOV 60
# define ROT 2
# define RAY 4

typedef unsigned char	t_color;

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
	int			j;
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
	double		line;
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
	t_ray			*ray;
	t_player		player;
	t_map			map;
	mlx_image_t		*bullet_text;
}				t_data;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/*========================= mlx_utils =========================*/

void		put_pixel(mlx_image_t *img, double x, double y, double color);
uint32_t	get_texture_pixel(mlx_texture_t *texture, int x, int y);
uint32_t	get_texture_pixel(mlx_texture_t *texture, int x, int y);
uint32_t	rgb(t_color r, t_color g, t_color b, t_color a);
bool		check_wall(t_data *data, double x, double y);
double		calcul_dis(t_data *data, t_vector pos);
void		get_derictions(t_data *data, int i);
void		first_point_h(t_data *data, int i);
void		first_point_v(t_data *data, int i);
void		get_texture(t_data *data, int i);
double		norm_angle(double angle);
void		load_wind(t_data *data);
void		move_player(void *ptr);
void		cast_rays(t_data *data);
void		draw_3d(t_data *data);

/*========================= get_next_line =========================*/

char		*read_line(char *s, int fd);
size_t		ft_countlen(const char *s);
char		*rest_of_str(char *s);
int			ft_newline(char *s);
char		*get_line(int fd);
char		*line(char *s);

/*========================= parsing =========================*/

void		ft_copy_map(char **map, t_data *data, int start_index, int size);
void		add_textur_or_f_c(char *line, t_data *data, int *elem);
void		get_color(char *line, t_data *data, int type);
void		handle_start_last_of_map(char *line);
void		handl_error_missage(char *missage);
int			ft_skipe_spaces(char *line, int i);
void		parsing(t_data *data, char *av);
int			is_textur_or_f_c(char *line);
void		add_map(t_data *data, int i);
int			is_map_member(char c);
int			is_player(char c);

/*========================= utils =========================*/

char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		**ft_split(char const *s, char c, bool remove);
void		ft_lstclear(t_list **lst, void (*del)(void*));
char		*ft_strtrim(char const *s1, char const *set);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		*ft_memset(void *b, int c, size_t len);
char		*ft_strchr(const char *s, int c);
void		*ft_malloc(size_t size, int mod);
char		*ft_strjoin(char *s1, char *s2);
void		ft_putendl_fd(char *s, int fd);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strdup(const char *s1);
t_list		*ft_lstnew(void *content);
size_t		ft_strlen(const char *s);
long		ft_atoi(const char *str);
void		*get_add(void *ptr);
int			ft_isdigit(int c);
void		ft_exit(int i);

#endif 