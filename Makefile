CC = cc

DIRMLX = /Users/$(USER)/Desktop/CUB_3D/libmlx42.a


FLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

RM = rm -f

NAME = Cub3D

NAME_BONUS = Cub3D_BON

LIBFT = libft/libft.a

MLXFLAGS =  -framework Cocoa -framework OpenGL -framework IOKit -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" $(LIBFT) $(DIRMLX) #-fsanitize=address -g

SRC = cub.c render_utils.c load_wind.c drawed.c  move_plyer.c cast_rays.c dda.c \
		render_wall.c first_point.c draw_3d.c sprit.c sprit_utils.c door.c \
		parsing/parsing.c \
		parsing/get_line.c \
		parsing/get_line_utils.c \
		parsing/ft_divide.c \
		parsing/utils.c  \
		parsing/pars_map_member.c  \
		parsing/map_analyse.c \
		parsing/handle_color.c \
		parsing/ft_handl_error.c \

BSRC = cub_bonus.c render_utils.c load_wind.c drawed.c  move_plyer.c cast_rays.c dda.c \
		render_wall.c first_point.c draw_3d.c sprit.c sprit_utils.c door.c \
		parsing_bonus_copy/parsing.c \
		parsing_bonus_copy/get_line.c \
		parsing_bonus_copy/get_line_utils.c \
		parsing_bonus_copy/ft_divide.c \
		parsing_bonus_copy/utils.c  \
		parsing_bonus_copy/pars_map_member.c  \
		parsing_bonus_copy/map_analyse.c \
		parsing_bonus_copy/handle_color.c \
		parsing_bonus_copy/ft_handl_error.c \

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

all : $(LIBFT)  $(NAME)

bonus : $(LIBFT)  $(NAME_BONUS)

%.o : %.c cub.h
	$(CC)  $(FLAGS) -c  $<   -o $@

$(NAME) : $(OBJ)
	$(CC) $(MLXFLAGS) $(SRC) -o $(NAME) 

$(NAME_BONUS) : $(BOBJ)
	$(CC) $(MLXFLAGS) $(BSRC) -o $(NAME_BONUS)

$(LIBFT) :
	@make -sC libft/

clean :
	$(RM) $(OBJ)
	$(RM) $(BOBJ)
	@make clean -sC libft/

fclean : clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	@make fclean  -sC libft/

re : fclean all

.PHONY : $(LIBFT)