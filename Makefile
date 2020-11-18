# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oem <oem@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/02 15:35:50 by pjoseth           #+#    #+#              #
#    Updated: 2020/11/16 12:37:31 by oem              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
OBJS = main.o hook.o check.o check_utils.o raycasting.o draw.o move.o
LIBFT = ./libft
MiniLibX = ./minilibx_macos
MiniLibX_args = -lmlx -lXext -lX11 -lm
Compiler_flags = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	make -s -C $(LIBFT)
	make -s -C $(MiniLibX)
	gcc $(Compiler_flags) $^ -o $@ -L $(LIBFT) -lft -L $(MiniLibX) $(MiniLibX_args)

%.o : %.c
	gcc $(Compiler_flags) -o $@ -c $<

clean:
	make -s -C $(LIBFT) clean
	rm -f $(OBJS)
	rm -f $(MiniLibX)/*.o

fclean:clean
	make -s -C $(LIBFT) fclean
	make -s -C $(MiniLibX) clean
	rm  -f $(NAME)

re: fclean all