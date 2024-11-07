CC = cc

DIRMLX = MLX42/libmlx42.a


FLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME_BONUS = cub3D_bonus

NAME = cub3D


MLXFLAGS =  -framework Cocoa -framework OpenGL -framework IOKit -lglfw3 -L"/Users/$(USER)/.brew/opt/glfw/lib/" $(DIRMLX)

SRC = MANDATORY/cub.c MANDATORY/render_utils.c MANDATORY/load_wind.c MANDATORY/get_texture.c  MANDATORY/move_plyer.c MANDATORY/cast_rays.c MANDATORY/put_pixel.c \
		 MANDATORY/first_point.c MANDATORY/draw_3d.c \
		MANDATORY/parsing/parsing.c \
		MANDATORY/parsing/utils.c  \
		MANDATORY/parsing/pars_map_member.c  \
		MANDATORY/parsing/map_analyse.c \
		MANDATORY/parsing/handle_color.c \
		MANDATORY/UTILS/ft_atoi.c \
		MANDATORY/UTILS/ft_isdigit.c \
		MANDATORY/UTILS/ft_lstadd_back.c \
		MANDATORY/UTILS/ft_lstclear.c \
		MANDATORY/UTILS/ft_malloc.c \
		MANDATORY/UTILS/ft_memset.c \
		MANDATORY/UTILS/ft_putendl_fd.c \
		MANDATORY/UTILS/ft_split.c \
 		MANDATORY/UTILS/ft_strchr.c \
		MANDATORY/UTILS/ft_strdup.c \
		MANDATORY/UTILS/ft_strjoin.c \
		MANDATORY/UTILS/ft_strlcpy.c \
		MANDATORY/UTILS/ft_strlen.c \
		MANDATORY/UTILS/ft_strncmp.c \
		MANDATORY/UTILS/ft_strtrim.c \
		MANDATORY/UTILS/ft_substr.c \
		MANDATORY/UTILS/get_line.c \
		MANDATORY/UTILS/ft_exit.c \
		MANDATORY/UTILS/get_line_utils.c

SRC_BONUS = BONUS/cub_bonus.c BONUS/render_utils_bonus.c BONUS/load_wind_bonus.c BONUS/drawed_bonus.c  BONUS/move_plyer_bonus.c BONUS/cast_rays_bonus.c BONUS/put_pixel_bonus.c \
		BONUS/render_wall_bonus.c BONUS/first_point_bonus.c BONUS/draw_3d_bonus.c BONUS/sprit_bonus.c BONUS/sprit_utils_bonus.c BONUS/door_bonus.c  BONUS/mouse_events_bonus.c \
		BONUS/parsing/parsing_bonus.c \
		BONUS/parsing/utils_bonus.c  \
		BONUS/parsing/pars_map_member_bonus.c  \
		BONUS/parsing/map_analyse_bonus.c \
		BONUS/parsing/handle_color_bonus.c \
		BONUS/UTILS/ft_atoi_bonus.c \
		BONUS/UTILS/ft_itoa_bonus.c \
		BONUS/UTILS/ft_isdigit_bonus.c \
		BONUS/UTILS/ft_lstadd_back_bonus.c \
		BONUS/UTILS/ft_lstclear_bonus.c \
		BONUS/UTILS/ft_malloc_bonus.c \
		BONUS/UTILS/ft_memset_bonus.c \
		BONUS/UTILS/ft_putendl_fd_bonus.c \
		BONUS/UTILS/ft_split_bonus.c \
 		BONUS/UTILS/ft_strchr_bonus.c \
		BONUS/UTILS/ft_strdup_bonus.c \
		BONUS/UTILS/ft_strjoin_bonus.c \
		BONUS/UTILS/ft_strlcpy_bonus.c \
		BONUS/UTILS/ft_strlen_bonus.c \
		BONUS/UTILS/ft_strncmp_bonus.c \
		BONUS/UTILS/ft_strtrim_bonus.c \
		BONUS/UTILS/ft_substr_bonus.c \
		BONUS/UTILS/get_line_bonus.c \
		BONUS/UTILS/ft_exit_bonus.c \
		BONUS/UTILS/get_line_utils_bonus.c


OBJ_BONUS = $(SRC_BONUS:.c=.o)

OBJ = $(SRC:.c=.o)


all :  $(NAME)

MANDATORY/%.o : MANDATORY/%.c MANDATORY/cub.h
	$(CC)  $(FLAGS) -c  $<   -o $@

$(NAME) : $(OBJ)
	$(CC) $(MLXFLAGS) $(SRC) -o $(NAME) 

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS)
	$(CC) $(MLXFLAGS) $(SRC_BONUS) -o $(NAME_BONUS)

BONUS/%.o : BONUS/%.c BONUS/cub_bonus.h
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)  $(OBJ_BONUS)

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all