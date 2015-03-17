# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/17 11:20:07 by tvallee           #+#    #+#              #
#    Updated: 2015/03/17 11:21:29 by tvallee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= parsing.c main.c
NAME	= wolf3d
CC		= gcc
CFLAGS	= -Wall -Wextra -g -Wshadow -Wno-missing-noreturn\
		  -Wno-padded -Wno-unreachable-code -Wredundant-decls\
		  -Wmissing-declarations
SRC_DIR	= srcs
VPATH	= $(SRC_DIR)
INC		= -I./includes -I./libft/includes
LIB		= -L./libft -lft -L./ -lft -lmlx -lXext -lX11
OBJ_DIR	= objs
OBJ		= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@echo ""
	@echo "Building libft..."
	@make -C libft/ re
	@echo "Done !"
	@echo "                \o/"
	@echo "Linkin'          |"
	@$(CC) $(CFLAGS) -o $(NAME) $(INC) $(OBJ) $(LIB)
	@echo "Successful !    / \\"

$(OBJ_DIR)/%.o: %.c
	@echo "Compiling $<."
	@$(CC) -c $< $(INC) -o $@ $(CFLAGS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "Deleting obj files."
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@echo "Deleting executable"
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
