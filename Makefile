LIBFT_REPO = https://github.com/Aledev21/Libft.git
MLX_REPO = https://github.com/42Paris/minilibx-linux.git

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
	src/utils/math_utils.c \

OBJ = $(SRC:%.c=%.o)
NAME = fractol

all: prebuild $(NAME)


$(NAME): $(OBJ) $(MLX) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)
	@$(MAKE) ascii_fractal --silent

prebuild:
	@echo "🔧 Compilando Libft..."
	@$(MAKE) -C includes/Libft --silent
	@echo "🎨 Compilando MiniLibX..."
	@$(MAKE) -C includes/minilibx-linux --silent

%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		git clone $(LIBFT_REPO) $(LIBFT_DIR); \
	fi
	@make -C $(LIBFT_DIR) --silent

$(MLX):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		git clone $(MLX_REPO) $(MLX_DIR); \
	fi
	@make -C $(MLX_DIR) --silent

ascii_fractal:
	@echo "\033[1;32m  ▄▀▀▀█▄    ▄▀▀▄▀▀▀▄  ▄▀▀█▄   ▄▀▄▄▄▄   ▄▀▀▀█▀▀▄  ▄▀▀█▄   ▄▀▀▀▀▄     "
	@echo "█  ▄▀  ▀▄ █   █   █ ▐ ▄▀ ▀▄ █ █    ▌ █    █  ▐ ▐ ▄▀ ▀▄ █    █      "
	@echo "▐ █▄▄▄▄   ▐  █▀▀█▀    █▄▄▄█ ▐ █      ▐   █       █▄▄▄█ ▐    █      "
	@echo " █    ▐    ▄▀    █   ▄▀   █   █         █       ▄▀   █     █       "
	@echo " █        █     █   █   ▄▀   ▄▀▄▄▄▄▀  ▄▀       █   ▄▀    ▄▀▄▄▄▄▄▄▀ "
	@echo "█         ▐     ▐   ▐   ▐   █     ▐  █         ▐   ▐     █         "
	@echo "▐                           ▐        ▐                   ▐          "
	@echo 
	@echo "     Fractol compilado com sucesso! 🚀"
	@echo "\033[0m"


clean:
	@rm -rf $(OBJ)
	@make -C $(MLX_DIR) clean --silent
	@make -C $(LIBFT_DIR) clean --silent

fclean: clean
	@rm -f $(NAME)
	@if [ -d "$(LIBFT_DIR)" ]; then make -C $(LIBFT_DIR) fclean --silent; fi
	@if [ -d "$(MLX_DIR)" ]; then make -C $(MLX_DIR) clean --silent; fi

re: fclean all

.PHONY: all clean fclean re prebuild ascii_fractal
