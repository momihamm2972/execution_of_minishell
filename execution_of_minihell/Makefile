# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 03:15:02 by momihamm          #+#    #+#              #
#    Updated: 2023/11/13 16:59:38 by momihamm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minihell
CC = cc
FLAGS = -Wall -Werror -Wextra -g -fsanitize=address
FILES = mini_excu.c\
		pwd_command.c\
		cd_command.c\
		builtins.c\
		tools.c\
		tools0.c\
		echo_command.c\
		env_command.c\
		ft_linked_list.c\
		export_command.c\
		export_command1.c\
		export_command2.c\
		export_command3.c\
		export_command4.c\
		unset.c\
		split.c

OBJ = $(FILES:.c=.o)

all : $(NAME)

%.o : %.c mini_excu.h
		$(CC) $(FLAGS) -c $<

$(NAME) : $(OBJ)
	$(CC) $(FILES) $(FLAGS) -o $(NAME)

clean :
		@rm -f $(OBJ)

fclean : clean
		@rm -f $(NAME)

re : fclean all 