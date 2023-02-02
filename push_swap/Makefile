# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdanchev <mdanchev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 12:21:59 by mdanchev          #+#    #+#              #
#    Updated: 2023/02/02 16:04:23 by mdanchev         ###   lausanne.ch        #
#                                                                              #
# **************************************************************************** #
# LEAKS Checking:
# CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -fno-omit-frame-pointer
# leaks -atExit -- ./push_swap
#
# explications:
#
# 	1) ${MAKE} -C libft
# 		-> va dans le dossier libft et execute make
# 	2) cp ./libft/libft.a .
# 		-> copie le fichier libft.a du dossier libft dans le dossier présent .
# 	3) ${CC} ${CFLAGS} -o ${NAME} ${OBJS} libft.a
# 		->execute gcc -Wall -Werror -Wextra -o push_swap libft.a *.o (les fichiers du dossier present!)
# 	4) ${MAKE} -C libft clean
# 		-> va dans le dossier libft et execute make clean

SRCS = 			errors_checker.c \
				int_errors_checker.c \
				prepare_string.c \
				error_msg.c \
				sort_int_tab.c \
				nodes_ops.c \
				push_ops.c \
				rotate_ops.c \
				rev_rotate_ops.c \
				init_stack_a.c \
				push_swap.c \
				swap_ops.c \
				free_ops.c \
				index_max_min.c \
				short_sorting.c \
				short_sorting_five.c \
				median.c \
				small_sorting.c \
				big_sorting.c \
				big_sorting_helper_functions.c


OBJS = ${SRCS:.c=.o}

NAME = push_swap
CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror -g

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:	${NAME}

$(NAME):	${OBJS}
		${MAKE} -C libft
		cp ./libft/libft.a .
		${CC} ${CFLAGS} -o ${NAME} ${OBJS} libft.a
clean:
		${MAKE} -C libft clean
		${RM} ${OBJS}

fclean:		clean
		${MAKE} -C libft fclean
		${RM} libft.a
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
