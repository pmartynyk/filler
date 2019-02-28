# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/24 09:38:43 by pmartyny          #+#    #+#              #
#    Updated: 2018/11/12 16:30:51 by pmartyny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pmartyny.filler

CC = gcc

FLAGS = -Wall -Wextra -Werror

SOURCE = ./src/filler.c\
	./src/fill_struct.c\
	./src/additional_function.c\
	./src/additional_function_2.c\
	./src/additional_function_3.c\
	./src/find_coordinates.c\


OB = $(SOURCE:%.c=%.o)

all: $(NAME)

%.o:%.c
	@$(CC) -c $(FLAGS) $< -o $@

$(NAME): $(OB)
	@make -C libft_printf
	@$(CC) $(OB) libft_printf/libftprintf.a -g -o $(NAME)

clean: 
	@make clean -C libft_printf
	@/bin/rm -f $(OB)

fclean: clean
	@make fclean -C libft_printf
	@/bin/rm -f $(NAME)

re:	fclean all

