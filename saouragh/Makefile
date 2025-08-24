NAME			=	so_long

# Directories
LIBFT			=	./libft/libft.a
FT_PRINTF		=	./ft_printf/libftprintf.a
GET_NEXT_LINE	=	./get_next_line/libgnl.a
MLX				=	./mlx_linux/libmlx.a
INC				=	include/
SRC_DIR			=	srcs/
OBJ_DIR			=	obj/

# Compiler and CFlags
CC 				=	cc
CFLAGS			=	-Wall -Werror -Wextra -g
MLX_FLAGS		=	-Imlx_linux -Lmlx_linux -lmlx -lXext -lX11 -lm

# Sources
SO_LONG_FILES	=	main.c \
					map.c \
					init.c \
					init_structures.c \
					map_loader.c \
					error.c \
					path_validity.c \
					parsing.c \
					graphics.c \
					render.c \
					keypress.c \
					cleanup.c \
					draw.c \
					update_position.c

SRCS			= $(addprefix $(SRC_DIR), $(SO_LONG_FILES))
OBJ				= $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# Build rules 
all:			$(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE) $(MLX) $(NAME)

$(LIBFT):
				@echo "Building libft..."
				@make -s -C ./libft

$(FT_PRINTF):
				@echo "Building ft_printf..."
				@make -s -C ./ft_printf

$(GET_NEXT_LINE):
				@echo "Building get_next_line..."
				@make -s -C ./get_next_line

$(NAME):		$(OBJ) $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE) $(MLX)
				@$(CC) $(CFLAGS) -I $(INC) -I ./mlx_linux $(OBJ) $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE) $(MLX_FLAGS) -o $(NAME)

$(MLX):
				@echo "Configuring and building mlx_linux..."
				@cd ./mlx_linux && ./configure > /dev/null
				@make -s -C ./mlx_linux > /dev/null
				@echo "so_long built successfully!"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) -I $(INC) -I ./ft_printf -I ./get_next_line -c $< -o $@
#				@echo "Compiled $< to $@"

clean:
				@echo "Cleaning object files..."
				@rm -f -r $(OBJ_DIR)
				@make -s clean -C ./libft
				@make -s clean -C ./ft_printf
				@make -s clean -C ./get_next_line
				@make -s clean -C ./mlx_linux
				@echo "Cleaned successfully!"

fclean: 		clean
				@echo "Removing executable..."
				@rm -f $(NAME)
				@rm -f $(LIBFT)
				@rm -f $(FT_PRINTF)
				@rm -f $(GET_NEXT_LINE)
				@rm -f $(MLX)
				@echo "Executable removed successfully!"


re:				fclean all

.PHONY: 		all clean fclean re