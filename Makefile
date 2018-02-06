NAME = fdf

RM	= rm -rf

LIB = -L ./libft/ -lft -L ./minilibx_macos/ -lft

HEADER = -I ./includes

CC = gcc -Werror -Wextra -Wall -I./includes

MLX = -lmlx -framework OpenGL -framework AppKit

SRCS = 	srcs/main.c \
		srcs/parsing.c \
		srcs/tools.c \
		srcs/create_map.c \
		srcs/error.c \
		srcs/exec_fdf.c \

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	make -C libft/
	make -C minilibx_macos/
	$(CC) $(MLX) -o $(NAME) -g $(OBJS) $(LIB) $(HEADER)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C libft/
	make clean -C minilibx_macos/

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft/

re: fclean all