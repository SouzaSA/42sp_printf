OBJS	=	ft_printf.c

NAME	=	libftprintf.a

OBJS	=	${SRCS:.c=.o}

CC	=	clang

RM	=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS} ${BONUS_OBJS}

fclean: 	clean
			${RM} ${NAME}

re:			fclean all

bonus:		${NAME} ${BONUS_OBJS}
			ar rcs ${NAME} ${BONUS_OBJS}

.PHONY:		all clean fclean re bonus

