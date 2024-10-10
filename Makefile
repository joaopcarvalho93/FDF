# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhorta-c <jhorta-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 13:37:54 by jhorta-c          #+#    #+#              #
#    Updated: 2024/10/10 19:29:23 by jhorta-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

#----------------------------LIBFT SOURCE FILES----------------------------------------------------------------------------------------------------
LIBFT_PATH = ./lib/libft/
LIBFT_LIB = $(LIBFT_PATH)/libft.a

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_PATH) --no-print-directory

#----------------------------GNL SOURCE FILES----------------------------------------------------------------------------------------------------
GNL_PATH = ./lib/get_next_line/
GNL_LIB = $(GNL_PATH)/libgnl.a

$(GNL_LIB):
	$(MAKE) -C $(GNL_PATH) --no-print-directory

#----------------------------MINILIBX SOURCE FILES----------------------------------------------------------------------------------------------------
MLX_PATH = ./lib/minilibx_linux/
MLX_LIB = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm

$(MLX_LIB):
	$(MAKE) -C $(MLX_PATH) --no-print-directory

#----------------------------PROJECT----------------------------------------------------------------------------------------------------

SRCS_DIR = srcs/
OBJS_DIR = srcs/objs/

SRCS_LIST = $(SRCS_DIR)/main.c \
			$(SRCS_DIR)/fdf.c \
			$(SRCS_DIR)/read.c \
			$(SRCS_DIR)/drawing.c \
			$(SRCS_DIR)/error.c \
			$(SRCS_DIR)/free.c \
			$(SRCS_DIR)/init.c \
			$(SRCS_DIR)/keys.c \
			

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
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

#----------------------------MAKEFILE RULES----------------------------------------------------------------------------------------------------


all: $(NAME)

$(NAME): $(LIBFT_LIB) $(GNL_LIB) $(MLX_LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(GNL_LIB) $(MLX_LIB) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(RESET)"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(CYAN)Compiling: $<$(RESET)"

clean:
	@$(RM) $(OBJS_DIR)
	@echo "$(ORANGE)$(NAME) objects removed!$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)$(NAME) removed!$(RESET)"


re: fclean all