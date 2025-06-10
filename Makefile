# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 14:54:55 by gudos-sa          #+#    #+#              #
#    Updated: 2025/06/10 13:23:24 by nfigueir         ###   ########.fr        #
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
			cub3D ))

SRCS	+= $(addprefix src/raycasting/, $(addsuffix .c, \
			raycasting_1 \
			raycasting_2 \
			raycasting_3))

SRCS	+= $(addprefix src/init/, $(addsuffix .c, \
			init))

SRCS	+= $(addprefix src/map/, $(addsuffix .c, \
			get_next_line_1 \
			get_next_line_2 \
			read_file \
			config_validation_1 \
			config_validation_2 \
			config_validation_3_rest \
			map_validation_1 \
			map_validation_2))

SRCS	+= $(addprefix src/utils/, $(addsuffix .c, \
			put_pixel \
			get_time_in_milliseconds ))

SRCS	+= $(addprefix src/utils/vector/, $(addsuffix .c, \
			ft_add_vector \
			ft_mult_vector \
			ft_rotate_vector \
			ft_set_vector \
			ft_mult_two_vector \
			ft_mag_vector ))

SRCS	+= $(addprefix src/hooks/, $(addsuffix .c, \
			player \
			game))

SRCS	+= $(addprefix src/exit/, $(addsuffix .c, \
			free_game \
			ft_exit))

SRCS	+= $(addprefix src/move/, $(addsuffix .c, \
			ft_move_player ))

SRCS	+= $(addprefix src/move/colision/, $(addsuffix .c, \
			ft_check_colision ))


OBJS = $(SRCS:.c=.o)


all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(SRCS) $(OBJS)
	make -C $(LIBFTDIR)
	make -C $(MINILIBXDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(ADDLIBFT) $(ADDMINILIBX)
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
