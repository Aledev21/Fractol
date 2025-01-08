CC = gcc
CCFLAGS = -Wall -Wextra -Werror -O3
INCLUDES = -Iincludes -Iincludes/minilibx-linux  
LIBS = -Lincludes/minilibx-linux -lmlx -lX11 -lGL -lXext

SRC = $(addprefix src/, main.c) 
OBJ = $(SRC:%.c=%.o)  
NAME = fractol 

all: $(NAME)

$(NAME): $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ) 
	$(CC) $(CCFLAGS) $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)

fclean: clean
	make clean -C includes/minilibx-linux/
	rm -f $(NAME)

re: fclean all
