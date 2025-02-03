#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggasset- <ggasset-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 12:49:28 by ggasset-          #+#    #+#              #
#    Updated: 2025/01/17 12:50:39 by ggasset-         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=push_swap

libft_NAME=./libft/libft.a
ARCHIVES= ${libft_NAME}

O_FILES= main.o sort_utils.o k_path.o args.o init.o utils.o p.o r.o rr.o s.o

CC_SECURITY_FLAGS= -Wall -Wextra -Werror
CC_FLAGS= -g #-fanalyzer

LOGO=\n ▗▄▄▄▄▖    ▗▄▄▄▄▖\n▐▌        ▐▌ \n▐▌ ▝▝▜▌   ▐▌ ▝▝▜▌\n▝▚▄▄▄▞▘   ▝▚▄▄▄▞▘     \n

all: libft ${NAME} logo

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
