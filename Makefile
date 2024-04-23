SRCM = so_long.c \
		ft_validate.c \
		so_long_utils.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \



CC = CC
CFLAGS = -Wall -Wextra -Werror
INFRW = -framework OpenGL -framework AppKit
INLIB = -lmlx

NAME = so_long

OBJSM = ${SRCM:.c=.o}

LIBFT = ./libft/libft.a

RM = rm -rf


all: ${LIBFT} ${OBJSM} ${NAME}

${NAME}: ${OBJSM}
	${CC} ${CFLAGS} ${INLIB} ${INFRW} ${LIBFT} ${OBJSM} -o ${NAME}

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
