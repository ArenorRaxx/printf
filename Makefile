# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/25 12:06:45 by mcorso            #+#    #+#              #
#    Updated: 2021/12/28 16:49:05 by mcorso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = ./srcs
OBJ_DIR = ./obj


SRC_FILES = ft_printf.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_putnbr_base.c\
		ft_putpointer_addr.c

SRCS = ${addprefix ${SRC_DIR}/, ${SRC_FILES}}

OBJ_FILES = ${SRC_FILES:.c=.o}
OBJS = ${addprefix ${OBJ_DIR}/, ${OBJ_FILES}}
HEAD = ./
NAME = libftprintf.a
CC = gcc -Wall -Werror -Wextra
RM = rm -f
${OBJ_DIR}/%.o:${SRC_DIR}/%.c
		${CC} -I ${HEAD} -c $< -o $@
${NAME}:{OBJS}
		ar rc ${NAME} ${OBJS}
clean:
		${RM} ${OBJ_DIR}/*
fclean: clean
		${RM} ${NAME}
all: ${NAME}

re:	fclean all