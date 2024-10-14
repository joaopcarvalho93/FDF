# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpcarvalho <jpcarvalho@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 13:37:54 by jhorta-c          #+#    #+#              #
#    Updated: 2024/10/14 15:32:04 by jpcarvalho       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

#----------------------------LIBFT SOURCE FILES----------------------------------------------------------------------------------------------------
LIBFT_PATH = ./lib/libft/
LIBFT_LIB = $(LIBFT_PATH)/libft.a


#----------------------------MINILIBX SOURCE FILES----------------------------------------------------------------------------------------------------
MLX_PATH = ./lib/mlx_linux/
MLX_LIB = $(MLX_PATH)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_PATH) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

#----------------------------PROJECT----------------------------------------------------------------------------------------------------

SRCS_DIR = src/
OBJS_DIR = src/objs/

SRCS_LIST = main.c \
			fdf.c \
			read.c \
			drawing1.c \
			drawing2.c \
			error.c \
			free.c \
			init.c \
			keys.c \
			
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))
OBJS = $(addprefix $(OBJS_DIR), $(SRCS_LIST:.c=.o))


#----------------------------COLOURS----------------------------------------------------------------------------------------------------

GREEN = \033[1;32m
ORANGE = \033[1;33m
RED = \033[1;31m
CYAN = \033[1;36mF
RESET = \033[0m


#----------------------------COMPILATION----------------------------------------------------------------------------------------------------

CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror -I $(INCLUDE)
RM = rm -rf
INCLUDE = ./includes/

#----------------------------MAKEFILE RULES----------------------------------------------------------------------------------------------------


all: $(NAME)

$(LIBFT_LIB):
	@make -s -C $(LIBFT_PATH) --no-print-directory

$(NAME): $(OBJS) $(LIBFT_LIB) $(MLX_LIB) 
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft $(MLX_FLAGS)  -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(RESET)"

$(MLX_LIB):
	@chmod 777 $(MLX_PATH)configure
	@make -s -C $(MLX_PATH) all
	
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(CYAN)Compiling: $<$(RESET)"

clean:
	@$(RM) $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_PATH) clean --no-print-directory
	@echo "$(ORANGE)$(NAME) objects removed!$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_PATH) fclean --no-print-directory
	@echo "$(RED)$(NAME) removed!$(RESET)"


re: fclean all