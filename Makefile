CC = cc

DIRMLX = /Users/$(USER)/Desktop/manda/libmlx42.a


FLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

RM = rm -f

NAME = Cub3D


MLXFLAGS =  -framework Cocoa -framework OpenGL -framework IOKit -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" $(DIRMLX)
SRC = cub.c render_utils.c load_wind.c get_texture.c  move_plyer.c cast_rays.c put_pixel.c \
		 first_point.c draw_3d.c \
		parsing/parsing.c \
		parsing/utils.c  \
		parsing/pars_map_member.c  \
		parsing/map_analyse.c \
		parsing/handle_color.c \
		UTILS/ft_atoi.c \
		UTILS/ft_isdigit.c \
		UTILS/ft_lstadd_back.c \
		UTILS/ft_lstclear.c \
		UTILS/ft_malloc.c \
		UTILS/ft_memset.c \
		UTILS/ft_putendl_fd.c \
		UTILS/ft_split.c \
 		UTILS/ft_strchr.c \
		UTILS/ft_strdup.c \
		UTILS/ft_strjoin.c \
		UTILS/ft_strlcpy.c \
		UTILS/ft_strlen.c \
		UTILS/ft_strncmp.c \
		UTILS/ft_strtrim.c \
		UTILS/ft_substr.c \
		UTILS/get_line.c \
		UTILS/ft_exit.c \
		UTILS/get_line_utils.c


OBJ = $(SRC:.c=.o)

all :  $(NAME)

%.o : %.c cub.h
	$(CC)  $(FLAGS) -c  $<   -o $@

$(NAME) : $(OBJ)
	$(CC) $(MLXFLAGS) $(SRC) -o $(NAME) 


clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : $(LIBFT)