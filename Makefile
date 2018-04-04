# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/03 10:55:55 by vbaudron          #+#    #+#              #
#    Updated: 2017/10/19 16:20:05 by vbaudron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in
LIB = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror

PATH_SRCS = ./srcs/
PATH_HEADER = ./includes/
PATH_LIB = $(PATH_SRCS)libft/
PATH_LEM_IN = $(PATH_SRCS)
PATH_GNL = $(PATH_SRCS)get_next_line/

HEADERS = lem_in.h get_next_line.h

SRC_GNL = get_next_line.c

SRC_LEM_IN = main.c crea_data.c crea_anthill.c is_a_room.c is_a_link.c \
			 crea_rooms.c crea_links.c link_it.c find_path.c handle_path.c \
			 is_already_in_path.c free_t_ant_path.c free_hill.c \
			 count_data_no_error.c new_data.c room_name.c new_path.c \
			 is_link_to_a_room.c



OBJ_GNL = $(SRC_GNL:.c=.o)
OBJ_LEM_IN = $(SRC_LEM_IN:.c=.o)

$(NAME):
	cd $(PATH_LIB) && $(MAKE)
	$(CC) $(FLAGS) -o $(NAME) -g $(addprefix $(PATH_GNL), $(SRC_GNL)) \
	$(addprefix $(PATH_LEM_IN), $(SRC_LEM_IN)) \
	-I$(PATH_HEADER) -L$(PATH_LIB) -lft

all: $(NAME)

clean:
	rm -rf $(OBJ_GNL) $(OBJ_LEM_IN) $(OBJ_PRINT)

fclean: clean
	rm -rf $(NAME)

re: fclean all
