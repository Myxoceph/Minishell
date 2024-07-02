# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/02 12:47:40 by abakirca          #+#    #+#              #
#    Updated: 2024/07/02 14:20:46 by abakirca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= minishell
LIBFT				= ./libft/libft.a
SRC_DIR				= srcs/
OBJ_DIR				= obj/
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra
RM					= rm -rf
INC					= -I./inc/ -I./libft/inc/
LDFLAGS				= -lreadline

MINISHELL_DIR		= $(SRC_DIR)main.c

SRCS 				= $(MINISHELL_DIR)

OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

RED					= \033[31m
GREEN				= \033[32m
YELLOW				= \033[33m
BLUE				= \033[34m
MAGENTA				= \033[35m
CYAN				= \033[36m
RESET				= \033[0m

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LDFLAGS) -o $(NAME)
					@echo "$(CYAN)Minishell	$(GREEN)[ready]$(RESET)"

$(LIBFT):
					@make -C ./libft

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
					@mkdir -p $(@D)
					@$(CC) $(INC) -c $< -o $@

clean:
					@$(RM) -rf $(OBJ_DIR)
					@make clean -C ./libft

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re: 				fclean all

.PHONY: 			all clean fclean re
