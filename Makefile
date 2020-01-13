# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 16:29:02 by srouhe            #+#    #+#              #
#    Updated: 2020/01/13 12:28:57 by srouhe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	ft_select
C		= 	gcc
FLAGS 	= 	-Wall -Werror -Wextra

FILES 	=	action.c \
			args.c \
			config.c \
			input.c \
			main.c \
			print.c \
			signal.c \
			utils.c

SRCS 	=	$(addprefix srcs/, $(FILES))
OBJS 	=	$(FILES:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft
	@$(C) $(FLAGS) -o $(NAME) $(SRCS) -I includes/ -I libft/includes -Llibft -lft -ltermcap

clean:
	@make clean -C libft
	@/bin/rm -f $(OBJS)

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all

norm:
	norminette srcs/*.c
	norminette includes/*.h
	make norm -C libft

.PHONY: all clean fclean re norm
