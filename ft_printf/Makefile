# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/11 05:54:15 by rogeriorslf       #+#    #+#              #
#    Updated: 2022/03/12 10:48:54 by wrosendo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBPATH = ./libft
CC = gcc
CFLAGS =
AR = ar rcs
RM = rm -f
TESTER = testers/teste.c

SRCS =	src/ft_apply_flag.c				\
		src/ft_apply_precision.c		\
		src/ft_apply_specifiers.c		\
		src/ft_case_c.c					\
		src/ft_case_d.c					\
		src/ft_case_p.c					\
		src/ft_case_s.c					\
		src/ft_case_u.c					\
		src/ft_case_upperx.c			\
		src/ft_case_x.c					\
		src/ft_convert.c				\
		src/ft_hextoa.c					\
		src/ft_uitoa.c					\
		src/ft_isvalid.c				\
		src/ft_utils.c					\
		src/ft_utoa.c					\
		src/ft_sprintf.c				\
		src/ft_printf.c

OBJS = 		${SRCS:%.c=%.o}

all:		${NAME}

${NAME}:	${OBJS}
			make -C ${LIBPATH}
			cp 		./libft/libft.a ./libftprintf.a
			${AR}	${NAME}		${OBJS}

clean:
			${RM}	${OBJS}
			make -C ${LIBPATH} clean

fclean:		clean
			${RM} 	${NAME}
			make -C ${LIBPATH} fclean

libft:
			make -C ${LIBPATH}

re: 		fclean all

bonus:		all

.PHONY: 	all clean fclean re libft
