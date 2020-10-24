# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/02 15:35:50 by pjoseth           #+#    #+#              #
#    Updated: 2020/10/24 13:32:13 by pjoseth          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
OBJS = main.o hook.o check.o check_utils.o
LIBFT = ./libft
MiniLibX = ./minilibx_macos
MiniLibX_args = -lmlx -framework OpenGL -framework AppKit
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