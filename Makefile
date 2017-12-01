# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agouby <agouby@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 23:13:52 by agouby            #+#    #+#              #
#    Updated: 2017/12/01 03:26:40 by agouby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 21sh
CC			= gcc
FLA			= -Wall -Werror -Wextra

LIB_NAME	= libft
LIB_PATH	= -L./libft -lftprintf
LIB_INC		= -I./libft/includes
INC			= -I./includes

SRC_PATH	= ./srcs/

SRC_FILES	= main.c
SRCS		= $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJ			= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@/usr/bin/make -C $(LIB_NAME)
	@$(CC) $(FLA) -o $(NAME) $(OBJ) $(LIB_PATH)

%.o: %.c
	@$(CC) $(FLA) $(INC) $(LIB_INC) -c $< -o $@

clean:
	@/usr/bin/make clean -C $(LIB_NAME)
	@/bin/rm -f $(OBJ)

fclean: clean
	@/usr/bin/make fclean -C $(LIB_NAME)
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
