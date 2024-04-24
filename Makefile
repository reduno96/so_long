SRCM = so_long.c \
		ft_validate.c \
		so_long_utils.c \
		ft_check.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \



CC = CC
CFLAGS = -Wall -Wextra -Werror
INFRW = MLX42/build/libmlx42.a MLX42/build/libglfw3.a -Iinclude -lm -framework Cocoa -framework OpenGL -framework IOKit

NAME = so_long

OBJSM = ${SRCM:.c=.o}

LIBFT = ./libft/libft.a

RM = rm -rf


all: ${LIBFT} ${OBJSM} ${NAME}

${NAME}: ${OBJSM}
	${CC} ${CFLAGS}  ${LIBFT} ${INFRW} ${OBJSM} -o ${NAME} -fsanitize=address -g

# *.o: *.c so_long.h
# 	$(CC) $(CFLAGS) -Imlx -c $< -o $@

${LIBFT}:
	@make -C libft

clean:
	make fclean -C libft
	${RM} ${OBJSM}

fclean: clean
	${RM} ${NAME} ${OBJSM}

re: fclean all

.PHONY: all clean fclean re bonus
