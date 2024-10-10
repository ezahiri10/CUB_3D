CC = cc

DIRMLX = /Users/$(USER)/Desktop/CUB_3D/libmlx42.a


FLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

RM = rm -f

NAME = Cub3D

LIBFT = libft/libft.a

MLXFLAGS =  -framework Cocoa -framework OpenGL -framework IOKit -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" $(LIBFT) $(DIRMLX) #-fsanitize=address -g

SRC = cub.c render_utils.c load_wind.c drawed.c  move_plyer.c cast_rays.c dda.c \
		render_wall.c first_point.c draw_3d.c  \
		parsing/parsing.c \
		parsing/get_line.c \
		parsing/get_line_utils.c \
		parsing/ft_divide.c 

OBJ = $(SRC:.c=.o)

all : $(LIBFT)  $(NAME)

%.o : %.c cub.h
	$(CC)  $(FLAGS) -c  $<   -o $@

$(NAME) : $(OBJ)
	$(CC) $(MLXFLAGS) $(SRC) -o $(NAME) 

$(LIBFT) :
	@make -sC libft/

clean :
	$(RM) $(OBJ)
	@make clean -sC libft/

fclean : clean
	$(RM) $(NAME)
	@make fclean  -sC libft/

re : fclean all

.PHONY : $(LIBFT)