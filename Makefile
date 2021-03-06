# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/10 14:41:44 by tvallee           #+#    #+#              #
#    Updated: 2015/06/13 14:23:28 by tvallee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= calc.c draw.c exit.c load_levels.c main.c move.c set_env.c tools.c
NAME	= wolf3d
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
LDFLAGS	= -Llibft -lft `./SDL2/bin/sdl2-config --libs` -lm
SRC_DIR	= ./src
SDL		= SDL2-2.0.3
INC_DIR = include
INFLAGS	= -I$(INC_DIR) -Ilibft/$(INC_DIR) `./SDL2/bin/sdl2-config --cflags`
OBJ_DIR = obj
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(OBJ_DIR) $(SDL) $(NAME)
	@echo "Done."

$(NAME): $(OBJS)
	@make -C libft
	@echo "Linking binary..."
	@$(CC) $^ $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling $<."
	@$(CC) $(CFLAGS) $(INFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(SDL): $(SDL).tar.gz
	@tar xzf $(SDL).tar.gz
	@echo "Compiling SDL"
	@( cd SDL2-2.0.3 \
		&& CC=clang ./configure --prefix=$(shell pwd)/SDL2/ \
		&& $(MAKE) && $(MAKE) install )

$(SDL).tar.gz:
	@echo "Downloading SDL."
	@curl -o $(SDL).tar.gz http://libsdl.org/release/$(SDL).tar.gz

clean:
	@echo "Deleting obj files."
	@rm -f $(OBJS)

fclean: clean
	@echo "Deleting binary."
	@rm -f $(NAME)

re: fclean all
