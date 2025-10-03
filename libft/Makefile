# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvassall <mvassall@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 11:05:02 by user1             #+#    #+#              #
#    Updated: 2025/09/15 16:06:40 by mvassall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = 
#CFLAGS = -Wall -Werror -Wextra -O2
#CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address
RM = /bin/rm -f
SRCS = $(shell find . -name '*.c')
OBJS = $(SRCS:.c=.o)

NAME = libft.a

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	$(RM) $(OBJS)

$(OBJS): libft.h

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
