# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 12:49:28 by ggasset-          #+#    #+#              #
#    Updated: 2024/12/17 15:46:45 by ggasset-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fractol

libft_NAME=./libft/libft.a
ARCHIVES= ${libft_NAME}

C_FILES= init.c s.c utils.c
O_FILES= init.o s.o utils.o

CC_SECURITY_FLAGS= -Wall -Wextra -Werror
CC_FLAGS= -g #-fanalyzer

LOGO=\n ▗▄▄▄▄▖    ▗▄▄▄▄▖\n▐▌        ▐▌ \n▐▌ ▝▝▜▌   ▐▌ ▝▝▜▌\n▝▚▄▄▄▞▘   ▝▚▄▄▄▞▘     \n

all: libs-all ${NAME} logo

${NAME}: ${O_FILES} ${ARCHIVES}
	cc ${minilibx_LINKING_FLAGS} -o ${NAME} ${O_FILES} ${ARCHIVES}

%.o: %.c
	cc ${CC_FLAGS} ${CC_SECURITY_FLAGS} -c $?

re: fclean all

fclean: clean
	rm -f ${NAME}

clean: libft-fclean
	rm -f ${O_FILES}

# LIBFT

libft:
	make --directory=./libft/ all

libft-re: libft-fclean libft

libft-clean:
	make --directory=./libft/ clean

libft-fclean:
	make --directory=./libft/ fclean

logo:
	@echo "${LOGO}"
	@sleep .25

.PHONY: all re fclean clean libft libft-re libft-clean libft-fclean logo