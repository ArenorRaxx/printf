# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/25 12:06:45 by mcorso            #+#    #+#              #
#    Updated: 2021/12/25 16:38:27 by mcorso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./srcs/ft_printf.c\
		./utils/ft_putchar.c\
		./utils/ft_putstr.c\
		./utils/ft_putnbr_base.c
OBJ = ${SRCS:.c=.o}
HEAD = libftprintf.h
NAME = libftprintf.a
CC = gcc -Wall -Werror -Wextra
RM = rm -f
.c.o:
		${CC} -I ${HEAD} -c $< -o ${<:.c=.o}
${NAME}: ${OBJ}
		ar rc ${NAME} ${OBJ}
clean:
		${RM} ${OBJ}
fclean: clean
		${RM} ${NAME}