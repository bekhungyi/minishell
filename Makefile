# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 16:32:57 by bhung-yi          #+#    #+#              #
#    Updated: 2023/11/14 19:24:36 by bhung-yi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell
AR_NAME		= shell.a

SRCS_DIR	= ./srcs
SRCS		=	main.c \
				minishell.c \
				builtins.c \
				handler.c \

# OBJS		= $(SRCS:%.c=%.o)
OBJS		= $(addprefix $(SRCS_DIR)/, $(SRCS:.c=.o))

CC			= gcc

AR			= ar rc

FLAGS		= -Wall -Werror -Wextra 
LFLAGS		= -fsanitize=thread -lpthread -g3 -pthread -lreadline

CPPFLAGS	= -I/opt/homebrew/opt/readline/include
LDFLAGS		= -L/opt/homebrew/opt/readline/lib

LIBFTPATH	= ./libft
LIBFTNAME	= libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFTPATH)
	mv $(LIBFTPATH)/$(LIBFTNAME) $(LIBFTNAME)
	$(CC) $(FLAGS) $(CPPFLAGS) $(LDFLAGS) $(LFLAGS) $(OBJS) $(LIBFTNAME) -o $(NAME)
	$(AR) $(AR_NAME) $(OBJS)
	rm -f $(OBJS)
 
clean:
	rm -f $(AR_NAME)
	rm -f $(LIBFTPATH)/*.o

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFTNAME)

re: fclean all

.PONY: all clean fclean re