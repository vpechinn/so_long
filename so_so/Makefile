NAME = so_long

NAME_BONUS = so_long_bonus

SRCS =	so_long.c get_next_line.c get_next_line_utils.c map_name.c ft_check_map.c draw_map.c\
		utils.c\

SRCS_B	=	so_long_bonus.c get_next_line_bonus.c  get_next_line_utils_bonus.c\
			 map_name_bonus.c 	ft_check_map_bonus.c	draw_map_bonus.c\
			utils_bonus.c	ft_render_bonus.c\

INCLUDE = so_long.h

INCLUDE_B = so_long_bonus.h

OBJS = $(SRCS:.c=.o)

OBJ_B = $(SRCS_B:.c=.o)

CC = gcc 

CFLAGS = -Wall -Wextra -Werror

MLX = -framework OpenGL -framework AppKit -lmlx

all : $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@  

$(NAME) : $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJS) -I./include $(MLX) libmlx.dylib -o $(NAME)

bonus: $(OBJ_B) $(INCLUDE_B)
	$(CC) $(CFLAGS) $(OBJ_B) -I./include $(MLX) libmlx.dylib -o ${NAME_BONUS}

clean :
	rm -rf $(OBJS) $(OBJ_B)

fclean : clean
	rm -rf $(NAME) ${NAME_BONUS}

re : fclean all

.PHONY: clean fclean re all