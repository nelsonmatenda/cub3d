# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 14:54:55 by gudos-sa          #+#    #+#              #
#    Updated: 2025/04/16 12:40:24 by nfigueir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
LIBFTDIR = ./libft
MINILIBXDIR = ./minilibx-linux
HEADCUB3DIR = ./includes
INCLUDES = -I $(HEADCUB3DIR) -I $(MINILIBXDIR) -I $(LIBFTDIR)
ADDLIBFT = -L $(LIBFTDIR) -lft
ADDMINILIBX = -L $(MINILIBXDIR) -lmlx -lXext -lX11 -lm
CC  = cc
CFLAGS = -Wextra -Werror -Wall -g

SRCS	= $(addprefix src/, $(addsuffix .c, \
			cub3D \
			get_next_line \
			get_next_line2 \
			read_map \
			error_hendling \
			ft_exit \
			init ))

SRCS	+= $(addprefix src/draw/, $(addsuffix .c, \
			map))

SRCS	+= $(addprefix src/utils/, $(addsuffix .c, \
			put_pixel))

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
		@echo "ALL CLEANED!"
re: fclean all

run: all
	./cub3d maps/default.cub
