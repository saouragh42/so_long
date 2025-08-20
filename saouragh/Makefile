NAME			=	so_long

# Directories
LIBFT			=	./libft/libft.a
FT_PRINTF		=	./ft_printf/libftprintf.a
GET_NEXT_LINE	=	./get_next_line/libgnl.a
INC				=	include/
SRC_DIR			=	srcs/
OBJ_DIR			=	obj/

# Compiler and CFlags
CC 				=	cc
CFLAGS			=	-Wall -Werror -Wextra -g

# Sources
SO_LONG_FILES	=	main.c \
					map.c \
					init.c \
					map_loader.c

SRCS			= $(addprefix $(SRC_DIR), $(SO_LONG_FILES))
OBJ				= $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# Build rules 
all:			$(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE) $(NAME)

$(LIBFT):
				@echo "Building libft..."
				@make -C ./libft

$(FT_PRINTF):
				@echo "Building ft_printf..."
				@make -C ./ft_printf

$(GET_NEXT_LINE):
				@echo "Building get_next_line..."
				@make -C ./get_next_line

$(NAME):		$(OBJ) $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE)
				$(CC) $(CFLAGS) -I $(INC) $(OBJ) $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE) -o $(NAME)
				@echo "so_long built successfully!"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) -I $(INC) -I ./ft_printf -I ./get_next_line -c $< -o $@
				@echo "Compiled $< to $@"

clean:
				@echo "Cleaning object files..."
				@rm -f -r $(OBJ_DIR)
				@make clean -C ./libft
				@make clean -C ./ft_printf
				@make clean -C ./get_next_line
				@echo "Cleaned successfully!"

fclean: 		clean
				@echo "Removing executable..."
				@rm -f $(NAME)
				@rm -f $(LIBFT)
				@rm -f $(FT_PRINTF)
				@rm -f $(GET_NEXT_LINE)
				@echo "Executable removed successfully!"


re:				fclean all

.PHONY: 		all clean fclean re