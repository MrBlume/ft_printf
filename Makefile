SRCS		= $(wildcard *.c)
OBJS		= ${SRCS:.c=.o}
HEADERS		= ft_printf.h
NAME		= libftprintf.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

%.o: %.c ${HEADERS}
			${CC} ${CFLAGS} -I. -c $< -o ${<:.c=.o}

$(NAME):	${OBJS} ${HEADERS}
			ar rcs ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
