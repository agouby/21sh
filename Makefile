# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agouby <agouby@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 23:13:52 by agouby            #+#    #+#              #
#    Updated: 2017/12/15 07:46:08 by agouby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CMP_LIB		= n

NAME		= 21sh
CC		= gcc
DEBUG		= -g -fsanitize=address
FLA		= -Wno-unused -Wno-empty-body -Wall -Werror -Wextra

LIB_NAME	= libft
LIB_PATH	= -L./libft -lftprintf
LIB_INC		= -I./libft/includes
INC		= -I./includes

SRC_PATH	= ./srcs/

SRC_FILES	= configure.c \
		  env.c \
		  lenv.c \
		  main.c \
		  restore.c \
		  routine.c \
		  print.c \
		  sgt.c \
		  read.c \
		  read_utils.c \
		  key.c \
		  key_pressed_np.c \
		  key_pressed_p.c \
		  signal.c \
		  line.c \
		  window.c \
		  insert.c \
		  delete.c \
		  line_utils.c \
		  histo_list.c

SRCS		= $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
ifeq ($(CMP_LIB), y)
	@/usr/bin/make -C $(LIB_NAME)
endif
	@$(CC) $(FLA) -o $(NAME) $(OBJS) $(LIB_PATH) -l termcap

%.o: %.c
	@$(CC) $(FLA) $(INC) $(LIB_INC) -c $< -o $@

clean:
ifeq ($(CMP_LIB), y)
	@/usr/bin/make clean -C $(LIB_NAME)
endif
	@/bin/rm -f $(OBJS)

fclean: clean
ifeq ($(CMP_LIB), y)
	@/usr/bin/make fclean -C $(LIB_NAME)
endif
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
