# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 20:39:41 by ttsubo            #+#    #+#              #
#    Updated: 2025/01/08 10:12:42 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC 			= cc -Wall -Wextra -Werror
SRC			= push_swap.c

DOT_A		= $(NAME).a
INC			= include
BLD_DIR		= build
SRC_DIR		= src
LIBFT		= lib/libft
OBJS		= $(patsubst $(SRC_DIR)/%.c, $(BLD_DIR)/%.o, $(SRC_DIR)/$(SRC))

all: $(NAME)
test: $(LIBFT)/libft.a
	$(CC) tests/dll/*.c \
		src/doubly_linked_list.c src/doubly_linked_list_methods.c \
		$(LIBFT)/libft.a -I$(INC) -Itests \
		-o test.out

$(NAME): $(BLD_DIR)/$(DOT_A) $(LIBFT)/libft.a
	$(CC) src/main.c $^ -I$(INC) -o $@

$(BLD_DIR)/$(DOT_A): $(OBJS)
	ar rcs $@ $^

$(BLD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -I$(INC) -o $@ 

$(LIBFT)/libft.a:
	$(MAKE) -C $(LIBFT) bonus

clean:
	rm -f $(OBJS)
	rm -f $(BLD_DIR)/$(DOT_A) 
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re debug test
