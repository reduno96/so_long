SRCM = so_long.c \
		ft_validate.c \
		so_long_utils.c \
		ft_check.c \
		ft_check_2.c \
		ft_free_ptr.c \
		game.c \
		ft_moves.c\
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \

OBJSM = ${SRCM:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

INCLUDES = ./MLX42/build/libmlx42.a -framework Cocoa -framework OpenGL -framework IOKit

NAME = so_long

RM = rm -rf

LIBFT= ./libft/libft.a
FLDLIBFT= ./libft

LIBPRINT= ./printf/libftprintf.a
FLDPRINTF= ./printf

all: ${LIBFT} ${LIBPRINT} ${NAME}

%.o: %.c so_long.h
	@$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJSM}
	@${CC} ${CFLAGS} ${OBJSM} ${INCLUDES} ${LIBFT} ${LIBPRINT} -Iinclude -lglfw -L "/Users/rel-mora/goinfre/homebrew/Cellar/glfw/3.4/lib" -o ${NAME}
	@echo "Compiling ${NAME}"

${LIBFT}:
	@make -C ${FLDLIBFT}
	@echo "Compiling libft"

${LIBPRINT}:
	@make -C ./printf

clean:
	@make fclean -C ${FLDLIBFT}
	@make fclean -C ${FLDPRINTF}
	@${RM} ${OBJSM}
	@echo "Cleaning objects"

fclean: clean
	@${RM} ${NAME} ${OBJSM}
	@echo "Cleaning ${NAME}"

re: fclean all

.PHONY: all clean fclean re bonus
