SRCS	=	ft_printf_cs.c	\
			ft_printf_flags.c	\
			ft_printf_pdix.c	\
			ft_printf_utiln.c	\
			ft_printf_utils.c	\
			ft_printf.c

NAME	=	libftprintf.a

OBJS	=	${SRCS:.c=.o}

CC	=	clang

RM	=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@ar rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus

