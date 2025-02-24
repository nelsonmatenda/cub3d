# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudos-sa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 14:54:55 by gudos-sa          #+#    #+#              #
#    Updated: 2025/02/10 14:54:59 by gudos-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
LIBFTDIR = ./libft
MINILIBXDIR = ./minilibx-linux
HEADCUB3DIR = ./includes
INCLUDES = -I $(HEADCUB3DIR) -I $(MINILIBXDIR)
ADDLIBFT = -L $(LIBFTDIR) -lft
ADDMINILIBX = -L $(MINILIBXDIR) -lmlx -lXext -lX11 -lm
CC  = cc
CFLAGS = -Wextra -Werror -Wall

SRCS = ./src/cub3D.c
OBJS = $(SRCS:.c=.o)


all: $(NAME)
  
%.o:%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	make -C $(MINILIBXDIR)
	$(CC) $(CFLAGS) $(INCLUDES)  -o $(NAME) $(OBJS) $(ADDLIBFT) $(ADDMINILIBX)
	clear
	@echo "MANDATORY PART COMPILED!"
clean:
	make clean -C $(LIBFTDIR)
	make clean -C $(MINILIBXDIR)
	rm -f $(OBJS)
	clear
	@echo "OBJECTS CLEANED!"
fclean: clean
		make fclean -C $(LIBFTDIR)
		rm -f $(NAME)
		clear
		@echo "ALL FILES CLEANED!"
re: fclean all
