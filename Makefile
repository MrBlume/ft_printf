SRCS		= $(wildcard *.c)
OBJS		= ${SRCS:.c=.o}
HEADERS		= ft_printf.h
NAME		= libftprintf.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror


LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

all:		${NAME}

%.o: %.c $(LIBFT) ${HEADERS}
			cp	$(LIBFT) $(NAME)
			${CC} ${CFLAGS} -I. -c $< -o ${<:.c=.o}

$(NAME):	${OBJS} ${HEADERS}
			ar rcs ${NAME} ${OBJS}

$(LIBFT):
			make -C $(LIBFT_PATH) all

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
