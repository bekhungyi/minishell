# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 16:32:57 by bhung-yi          #+#    #+#              #
#    Updated: 2023/11/09 13:00:56 by bhung-yi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= shell

AR_NAME		= shell.a

SRCS		=	main.c \
				# srcs/minishell.c \

OBJS		= $(SRCS:%.c=%.o)

CC			= gcc

AR			= ar rc

FLAGS		= -Wall -Werror -Wextra 
LFLAGS		= -fsanitize=thread -lpthread -g3 -pthread 


$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(LFLAGS) $(OBJS) -o $(NAME)
	$(AR) $(AR_NAME) $(OBJS)
	rm -f $(OBJS)
 
all: $(NAME)

clean:
	rm -f $(AR_NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PONY: all clean fclean re