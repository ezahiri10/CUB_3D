CC = cc

DIRMLX = /Users/$(USER)/libmlx42.a


FLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME = Cub3D

LIBFT = libft/libft.a

MLXFLAGS =  -framework Cocoa -framework OpenGL -framework IOKit -lglfw $(LIBFT) $(DIRMLX) -fsanitize=address -g

SRC = cub.c render_utils.c load_wind.c drawed.c  move_plyer.c cast_rays.c dda.c \
		render_wall.c first_point.c draw_3d.c  

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