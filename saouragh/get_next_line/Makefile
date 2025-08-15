# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/13 00:00:00 by saouragh          #+#    #+#              #
#    Updated: 2025/08/14 17:42:04 by saouragh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libgnl.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -D BUFFER_SIZE=1024

# Sources
SRCS		= get_next_line.c get_next_line_utils.c
OBJS		= $(SRCS:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	@echo "libgnl.a created successfully!"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@echo "Cleaned GNL object files."

fclean: clean
	rm -f $(NAME)
	@echo "Removed libgnl.a"

re: fclean all

.PHONY: all clean fclean re
