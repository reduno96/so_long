SRCM = so_long.c \
		ft_validate.c \
		so_long_utils.c \
		ft_check.c \
		ft_check_2.c \
		ft_free_ptr.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \

OBJSM = ${SRCM:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror -g 
INCLUDES = ./MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
NAME = so_long

RM = rm -rf

LIBFT= ./libft/libft.a
FLDLIBFT= ./libft

all: ${LIBFT} ${NAME}

%.o: %.c so_long.h
	@$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJSM}
	@${CC} ${CFLAGS} ${OBJSM} ${INCLUDES} ${LIBFT} -DDEBUG=1 -o ${NAME}
	@echo "Compiling ${NAME}"

${LIBFT}:
	@make -C ${FLDLIBFT}
	@echo "Compiling libft"

clean:
	@make fclean -C ${FLDLIBFT}
	@${RM} ${OBJSM}
	@echo "Cleaning objects"

fclean: clean
	@${RM} ${NAME} ${OBJSM}
	@echo "Cleaning ${NAME}"

re: fclean all

.PHONY: all clean fclean re bonus
