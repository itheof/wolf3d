# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/10 14:41:44 by tvallee           #+#    #+#              #
#    Updated: 2015/06/04 14:01:57 by tvallee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= main.c set_env.c load_levels.c
NAME	= wolf3d
CC		= gcc
CFLAGS	= -Wall -Wextra -g -Wshadow -Wno-missing-noreturn\
		  -Wno-padded -Wno-unreachable-code -Wredundant-decls\
		  -Wmissing-declarations
SRC_DIR	= src
VPATH	= $(SRC_DIR)
INC		= -I./include -I./libft/include
LIB		= -L./libft -lft -lmlx -framework OpenGL -framework AppKit
OBJ_DIR	= obj
OBJ		= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@echo ""
	@echo "Building libft..."
	@echo "Done !"
	@echo ""
	@echo "Linkin'"
	@$(CC) $(CFLAGS) -o $(NAME) $(INC) $(OBJ) $(LIB)
	@echo "Successful !"

linux: $(OBJ_DIR) $(OBJ)
	@echo "Building libft..."
	@echo "Done !"
	@echo ""
	@echo "Linkin'"
	@$(CC) $(CFLAGS) -o $(NAME) -I./ -I./libft/include -I./include $(OBJ) -L/usr/X11/lib -lmlx -lXext -lX11
	@echo "Successful !"


$(OBJ_DIR)/%.o: %.c
	@echo "Compiling $<."
	@$(CC) -c $< $(INC) -o $@ $(CFLAGS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/parsing $(OBJ_DIR)/interpreter $(OBJ_DIR)/libftmod
	@mkdir -p $(OBJ_DIR)/builtins

clean:
	@echo "Deleting obj files."
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@echo "Deleting executable"
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re $(OBJ_DIR)
