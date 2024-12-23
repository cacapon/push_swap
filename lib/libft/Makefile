# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 10:03:51 by ttsubo            #+#    #+#              #
#    Updated: 2024/12/23 20:19:35 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET	= libft.a
CC 		= cc -Wall -Wextra -Werror
SRCS	= 	ft_atoi.c     ft_isdigit.c  ft_memmove.c     ft_split.c     ft_strlcpy.c  ft_strtrim.c	\
			ft_bzero.c    ft_isprint.c  ft_memset.c      ft_strchr.c    ft_strlen.c   ft_substr.c	\
			ft_calloc.c   ft_itoa.c     ft_putchar_fd.c  ft_strdup.c    ft_strmapi.c  ft_tolower.c	\
			ft_isalnum.c  ft_memchr.c   ft_putendl_fd.c  ft_striteri.c  ft_strncmp.c  ft_toupper.c	\
			ft_isalpha.c  ft_memcmp.c   ft_putnbr_fd.c   ft_strjoin.c   ft_strnstr.c				\
			ft_isascii.c  ft_memcpy.c   ft_putstr_fd.c   ft_strlcat.c   ft_strrchr.c				\
			get_next_line.c	get_next_line_utils.c 													\
			ft_printf.c	ft_printf_utils1.c ft_printf_utils2.c format_handler.c format_handler2.c

BONUS_S = 	ft_lstnew.c	ft_lstadd_front.c	ft_lstsize.c	ft_lstlst.c	ft_lstadd_back.c		\
			ft_lstdelone.c	ft_lstclear.c	ft_lstiter.c	ft_lstmap.c

ifeq ($(MAKECMDGOALS), debug)
	CC := gcc -Wall -Wextra -Werror -g
    SRCS := $(SRCS)$(BONUS_S)
endif
ifeq ($(MAKECMDGOALS), bonus)
    SRCS := $(SRCS)$(BONUS_S)
endif

OBJS	= $(SRCS:.c=.o)
B_OBJS	= $(BONUS_S:.c=.o)

all		: $(TARGET)
debug	: $(TARGET)
bonus	: $(TARGET)

$(TARGET): $(OBJS)
	ar rc $@ $^

%.o: %.c
	$(CC) -c $< -o $@ 

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all


.PHONY: all clean fclean re bonus debug
