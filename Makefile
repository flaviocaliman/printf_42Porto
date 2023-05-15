# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 18:42:55 by fgomes-c          #+#    #+#              #
#    Updated: 2023/05/15 17:58:22 by fgomes-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_print_std.c ft_print_unsig.c ft_print_pointer.c ft_print_hex.c

OBJS = ${SRC:.c=.o}

INCLUDE = -I .
CC = cc
RM = rm -f
MAKE = make -C
LIBFT_PATH = libft
LIBFT = ${LIBFT_PATH}/libft.a
CFLAGS = -Wall -Wextra -Werror

%.o:%.c
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		${MAKE} ${LIBFT_PATH} all
		cp ${LIBFT} ${NAME}
		ar rcs ${NAME} ${OBJS}

all:    ${NAME}

clean:
		${MAKE} ${LIBFT_PATH} clean
		${RM} ${OBJS}

fclean: clean
		${MAKE} ${LIBFT_PATH} fclean
		${RM} ${NAME}

re: fclean all

test: main.c ${NAME}
		${CC} ${CFLAGS} ${INCLUDE} main.c ${NAME} -o test

.PHONY: all clean fclean re