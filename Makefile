CC = cc
CCFLAGS = -Wall -Wextra -Werror -O3
INCLUDES = -Iincludes -Iincludes/minilibx-linux  
LIBS = -Lincludes/minilibx-linux -lmlx -lX11 -lGL -lXext -lm

MLX_DIR = includes/minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

SRC = $(addprefix src/, main.c) 
OBJ = $(SRC:%.c=%.o)  
NAME = fractol 

all: $(NAME)

$(NAME): $(OBJ) $(MLX)
	$(CC) $(CCFLAGS) $(OBJ) $(LIBS) -o $(NAME)

$(MLX):
	make -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)

re: fclean all
