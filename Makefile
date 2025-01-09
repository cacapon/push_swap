# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 20:39:41 by ttsubo            #+#    #+#              #
#    Updated: 2025/01/09 21:33:41 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC 			= cc -Wall -Wextra -Werror
ifeq ($(MAKECMDGOALS), debug)
	CC := gcc -Wall -Wextra -Werror -g
endif

SRC_PATH	= src/
OBJ_PATH	= build/
LIBFT_PATH	= lib/libft/

SRC_MAIN	= 	main.c push_swap.c push_swap_util.c
SRC_DLL		= 	doubly_linked_list.c doubly_linked_list_methods.c doubly_linked_list_methods2.c
SRC			=	$(SRC_MAIN) $(SRC_DLL)
SRCS		= $(addprefix $(SRC_PATH, $(SRC))
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))
INCS		= -I ./include
T_INCS		= -I ./tests
LIBFT		= libft.a

all:  $(OBJ_PATH) $(NAME)
debug: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS) $(LIBFT_PATH)$(LIBFT)
	$(CC) $^ -o $@

$(LIBFT_PATH)$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH) bonus

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

test_dll: $(LIBFT_PATH)$(LIBFT)
	$(CC) tests/dll/*.c \
		$(addprefix $(SRC_PATH), $(SRC_DLL)) \
		$(LIBFT_PATH)$(LIBFT) $(INCS) $(T_INCS) -o $@.out

.PHONY: all clean fclean re debug test
