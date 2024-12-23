# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 20:39:41 by ttsubo            #+#    #+#              #
#    Updated: 2024/12/23 21:16:03 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC 			= cc -Wall -Wextra -Werror
SRCS		= src/push_swap.c

LIB			= $(NAME).a
INC			= include
BLD			= build
OBJS		= $(patsubst src/%.c, build/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(LIB)
	$(CC) src/main.c $^ -I$(INC) -o $@

$(LIB): $(OBJS)
	ar rcs $@ $^

$(BLD)/%.o: %.c
	$(CC) -c $< -I$(INC) -o $(BLD)/$@ 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug