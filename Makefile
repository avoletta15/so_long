# CC			= 	cc -fsanitize=leak -g
CC			= 	cc -g
CFLAGS		= 	 -Wall -Wextra -Werror -O3 -fsanitize=address
RM			= 	/bin/rm -f
NAME		= 	so_long
INCLUDES	= 	-I include/
SRCS		=   $(wildcard game/*.c)
OBJS		= 	$(SRCS:.c=.o)

UNAME := $(shell uname)

COLOUR_GREEN=\033[7;1;32m
COLOUR_END=\033[0m
COLOUR_YELLOW=\033[7;1;33m

ifeq ($(UNAME), Darwin)
	MLX_LIB_DIR = minilbx_opengl/
	MLX_INCLUDE = -Iminilbx_opengl
	MLX_FLAGS = -L$(MLX_LIB_DIR) -Lmlx -lmlx -framework OpenGL -framework AppKit -O3
else
	MLX_LIB_DIR = mlx_linux/
	MLX_INCLUDE = -Imlx_linux
	MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -O3
endif

all: $(NAME) 

$(NAME):  $(OBJS)
	make -C ./libft/ --no-print
	$(CC) $(CFLAGS) $(^) libft/libft.a $(MLX_FLAGS) -o $(@)
	echo "$(COLOUR_GREEN)DONE --> $(COLOUR_YELLOW)$(NAME)$(DEFAULT)"
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) $(MLX_INCLUDE) -c $(^) -o $(@)

bonus: all

clean:
	@$(RM) $(OBJS)
	@echo "\033[0;31mREMOVED OBJECT FILES\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[0;31mREMOVED so_long EXECUTABLE\033[0m"

re: fclean all

watch:
	@printf "Watching files..\n"
	@while true; do $(MAKE) -q --no-print-directory || $(MAKE) --no-print-directory; sleep 2; done;

.PHONY: all re clean fclean