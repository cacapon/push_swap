# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 20:39:41 by ttsubo            #+#    #+#              #
#    Updated: 2025/01/17 15:36:29 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC 			= cc -Wall -Wextra -Werror
ifeq ($(MAKECMDGOALS), debug)
	CC := gcc -Wall -Wextra -Werror -g
endif

SRC_PATH		= src/
SRC_DLL_PATH	= src/dll/
SRC_CMD_PATH	= src/cmd/
SRC_LOGIC_PATH	= src/logic/
OBJ_PATH		= build/
LIBFT_PATH		= lib/libft/

SRC_MAIN	= main.c push_swap_util.c
SRC_DLL		= add_dll.c append_dll.c free_dll.c init_dll.c \
			  is_in_dll.c pop_dll.c rotate_dll.c swap_dll.c \
			  len_dll.c min_dll.c
SRC_LOGIC	= bubble_sort.c select_sort.c
SRC_CMD		= push.c rotate.c rv_rotate.c swap.c
SRCS		= 	$(addprefix $(SRC_PATH), $(SRC_MAIN)) \
				$(addprefix $(SRC_DLL_PATH), $(SRC_DLL)) \
				$(addprefix $(SRC_LOGIC_PATH), $(SRC_LOGIC)) \
				$(addprefix $(SRC_CMD_PATH), $(SRC_CMD))

$(info $(SRCS))

OBJS		= $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

INCS		= -I ./include
T_INCS		= -I ./tests/include
LIBFT		= libft.a

all:  $(NAME)
debug: $(NAME)

$(NAME): $(OBJS) $(LIBFT_PATH)$(LIBFT)
	$(CC) $^ -o $@

$(OBJ_PATH)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) -c $< -o $@ $(INCS)

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
	$(CC) -g tests/dll/*.c tests/test_result/*.c \
		$(addprefix $(SRC_DLL_PATH), $(SRC_DLL)) \
		$(LIBFT_PATH)$(LIBFT) $(INCS) $(T_INCS) -o $@.out

.PHONY: all clean fclean re debug test
