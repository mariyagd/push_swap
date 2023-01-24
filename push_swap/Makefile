# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdanchev <mdanchev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 12:21:59 by mdanchev          #+#    #+#              #
#    Updated: 2023/01/24 16:02:21 by mdanchev         ###   lausanne.ch        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_checker_intMax_intMin.c

OBJS = ${SRCS:.c=.o}

NAME = push_swap
CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:	${NAME}

$(NAME):	${OBJS}
		${MAKE} -C libft
# va dans le dossier libft et execute make
		cp ./libft/libft.a .
# copie le fichier libft.a du dossier libft dans le dossier présent .
		${CC} ${CFLAGS} -o ${NAME} ${OBJS} libft.a
# execute gcc -Wall -Werror -Wextra -o push_swap libft.a *.o (les fichiers du dossier present!)
clean:
		${MAKE} -C libft clean
# va dans le dossier libft et execute make clean
		${RM} ${OBJS}

fclean:		clean
		${MAKE} -C libft fclean
		${RM} libft.a
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
