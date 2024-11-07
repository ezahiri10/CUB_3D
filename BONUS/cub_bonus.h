/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bonus.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:21:56 by ezahiri           #+#    #+#             */
/*   Updated: 2024/11/07 14:57:50 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_BONUS_H
# define CUB_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include ".MLX42/include/MLX42/MLX42.h"
# include <sys/time.h>

# define TILE_SIZE 40
# define H_S 864
# define W_S 1200
# define STEPS 15
# define FOV 60
# define ROT 4
# define RAY 4

typedef unsigned char	t_color;

typedef struct s_vector
{
	double	x;
	double	y;
}		t_vector;

typedef struct s_door
{
	int		i;
	int		j;
	char	stat;
}		t_door;

typedef struct s_map
{
	char		**map;
	int			i;
	int			j;
	int			door_counter;
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
	bool		is_door_v;
	bool		is_door_h;
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
	mlx_texture_t	**shoot;
	mlx_image_t		**shoot_img;
	mlx_texture_t	**reload;
	mlx_image_t		**reload_img;
	char			*no_texture;
	char			*so_texture;
	char			*we_texture;
	char			*ea_texture;
	t_ray			*ray;
	t_door			*doors;
	mlx_image_t		*mini;
	double			miniwidth;
	double			miniheight;
	t_vector		mini_p;
	t_player		player;
	t_vector		door_pos;
	t_map			map;
	bool			is_shooting;
	bool			is_reloading;
	bool			is_open;
	bool			is_close;
	int				bullets;
	mlx_image_t		*bullet_text;
}				t_data;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

uint32_t	rgb(t_color r, t_color g, t_color b, t_color a);
void		load_wind(t_data *data);
void		render_map(t_data *data);
void		move_player(t_data	*data);
double		norm_angle(double angle);
void		cast_rays(t_data *data);
double		calcul_dis(t_data *data, t_vector pos);
void		first_point_h(t_data *data, int i);
void		first_point_v(t_data *data, int i);
void		get_derictions(t_data *data, int i);
bool		check_wall(t_data *data, double x, double y);
bool		check_door(t_data *data, double x, double y);
void		draw_3d(t_data *data);
uint32_t	get_texture_pixel(mlx_texture_t *texture, int x, int y);
void		put_pixel(mlx_image_t *img, double x, double y, double color);
uint32_t	get_texture_pixel(mlx_texture_t *texture, int x, int y);
void		get_texture(t_data *data, int i);
int			get_door_index(t_data *data, int i, int j);
void		reload_sprit_animation(t_data *data);
void		shoot_sprit_animation(t_data *data);
void		ft_load_gun_reload(t_data *d);
void		ft_load_gun_shoot(t_data *d);
void		init_paths(char *paths[9]);
void		init_reload_paths(char *paths[9]);
void		ft_print_bullet(t_data *data);
void		close_doors(t_data *data);
void		open_close_door(t_data *data);
void		mouse_events(double x, double y, void *para);

//bonus parsing

void		parsing_bonus(t_data *data, char *av);
void		handl_error_missage(char *missage);
int			is_textur_or_f_c(char *line);
void		handle_start_last_of_map(char *line);
void		ft_copy_map(char **map, t_data *data, int start_index, int size);
void		add_textur_or_f_c(char *line, t_data *data, int *elem);
void		add_map_bonus(t_data *data, int i);
int			ft_skipe_spaces(char *line, int i);
int			is_player(char c);
int			is_map_member_bonus(char c);
void		get_color(char *line, t_data *data, int type);

//get_line

char		*get_line(int fd);
char		*line(char *s);
char		*rest_of_str(char *s);
char		*read_line(char *s, int fd);
size_t		ft_countlen(const char *s);
int			ft_newline(char *s);

//utils

void		*ft_memset(void *b, int c, size_t len);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s1, char const *set);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(const char *s1);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
long		ft_atoi(const char *str);
int			ft_isdigit(int c);
void		*ft_malloc(size_t size, int mod);
void		*get_add(void *ptr);
void		ft_exit(int i);
char		**ft_split(char const *s, char c, bool remove);
char		*ft_strchr(const char *s, int c);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void*));
char		*ft_itoa(int n);

#endif 