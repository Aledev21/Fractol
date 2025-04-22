CC = cc
CFLAGS = -Wall -Wextra -Werror -O3 -flto -march=native
INCLUDES = -Iincludes -Iincludes/minilibx-linux -Iincludes/Libft
LIBS = -Lincludes/Libft -lft -Lincludes/minilibx-linux -lmlx -lX11 -lXext -lm

MLX_DIR = includes/minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

LIBFT_DIR = includes/Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = \
    src/main.c \
    src/render/color.c \
    src/render/draws.c \
    src/events/keyboard.c \
    src/events/mouse.c \
    src/events/close.c \
    src/fractals/mandelbrot.c \
    src/fractals/julia.c \
    src/fractals/burningship.c \
    src/utils/errors.c \
    src/utils/init.c \
    src/utils/math_utils.c\
    

OBJ = $(SRC:%.c=%.o)
NAME = fractol

all: $(NAME)

$(NAME): $(OBJ) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

$(MLX):
	make -C $(MLX_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ)
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@if [ -d "$(LIBFT_DIR)" ]; then make -C $(LIBFT_DIR) fclean; fi
	@if [ -d "$(MLX_DIR)" ]; then make -C $(MLX_DIR) clean; fi  # Alterado para clean

re: fclean all

.PHONY: all clean fclean re