NAME = so_long

SRC_DIR = src
INC_DIR = includes
LIBFT_DIR = libft
MLX_DIR = $(HOME)/mlx
GNL_DIR = gnl

SRC = $(SRC_DIR)/so_long.c $(SRC_DIR)/utils/validator.c $(SRC_DIR)/utils/free_utils.c
OBJ = $(SRC:.c=.o)
LIBFT_A = $(LIBFT_DIR)/libft.a
MLX_A = $(MLX_DIR)/libmlx_Linux.a
GNL_A = $(GNL_DIR)/gnl.a
HOME = ..

CC = cc
COPY = cp
AR = ar rcs
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LIBX_FLAGS	= -lXext -lX11
INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(GNL_DIR)

all: $(LIBFT_A) $(GNL_A) $(MLX_LIB) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

#make libft.a
$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

#make gnl.a
$(GNL_A):
	$(MAKE) -C $(GNL_DIR)

#make libmlx_linux.a
$(MLX_A):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ) $(MLX_A) $(LIBFT_A) $(GNL_A)
	$(CC) $(OBJ) $(MLX_A) $(LIBFT_A) $(GNL_A) $(LIBX_FLAGS) $(INCLUDES) -o $(NAME)

clean: 
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	@$(RM) $(OBJ)

fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean
	@$(RM) $(OBJ) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus