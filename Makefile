# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 12:44:25 by iarbaiza          #+#    #+#              #
#    Updated: 2024/06/21 13:59:07 by iarbaiza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

INCLUDES = ./src/includes/cub3d.h

SRCS =	GNL/get_next_line.c \
		GNL/get_next_line_utils.c \
		src/cub3d.c \
		src/read_map.c \
		src/check_map.c \
		src/utils_parse.c \
		src/utils.c \
		src/move.c \
		src/ray_cast.c \
		src/2D.c \
		src/3D.c \
		src/hooks.c \
		src/dda.c \
		src/wall_direction.c \
		src/init_texturer.c \
		src/texturer.c \
		src/check_colition.c \
		src/initialize.c \
			

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address,leak
LIBFT = Libft/libft.a
OBJS = $(SRCS:.c=.o)

# Colors
DEF_COLOR	=	\033[0;39m
GRAY 		=	\033[0;90m
RED 		=	\033[0;91m
GREEN 		=	\033[0;92m
YELLOW 		=	\033[0;93m
BLUE 		=	\033[0;94m
MAGENTA 	=	\033[0;95m
CYAN 		=	\033[0;96m
WHITE 		=	\033[0;97m

LIBS = minilib
MLXFLAGS = -L $(LIBS) -lmlx -lXext -lX11 -lm
MLXLIB = $(LIBS)/libmlx.a

all: $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)  $(MLXLIB) $(LIBFT) 
	$(CC) $(CFLAGS) $(MLXFLAGS) $^ -o $@ 
	@echo "$(GREEN)$(NAME) Compiled! 🚀$(WHITE)\n"

$(MLXLIB):
	@make -C $(LIBS) 2> /dev/null

$(LIBFT):
	@make -C ./Libft

clean:
	@rm -rf $(OBJS)
	@rm -rf ./Libft/libft.a
	@make clean -C $(LIBS)
	@make clean -C ./Libft
	@echo "$(GRAY)$(NAME) Cleaned $(WHITE)\n"

fclean: clean
	@rm -f $(NAME) $(MLXLIB) $(LIBFT)
	@echo "$(RED)$(NAME) Removed $(WHITE)\n"

re:	fclean all

bonus:
	@make all
	@echo "🚀 $(GREEN)Bonus $(NAME) Compiled! 🚀$(WHITE)\n"

.PHONY: all clean fclean re bonus
