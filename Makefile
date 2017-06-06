NAME = fractol
CC = gcc
FLAGS = -Wall -Wextra -Werror
FLAGS2 = -framework OpenGL -framework AppKit -lpthread
MLX = mlx
INCLUDES = includes
LIB = libft
SRCS = srcs/main.c\
	   srcs/initialize.c\
	   srcs/draw.c\
	   srcs/hooks.c\
	   srcs/tools.c\
	   srcs/menu.c\
	   srcs/multithread.c\
	   srcs/fractals.c\
	   srcs/hooks2.c
OBJS = main.o\
	   initialize.o\
	   draw.o\
	   hooks.o\
	   tools.o\
	   menu.o\
	   multithread.o\
	   fractals.o\
	   hooks2.o

.PHONY: clean norme re all

all: $(NAME)

$(NAME):
	make -C $(LIB)
	make -C $(MLX)
	$(CC) $(FLAGS) -c $(SRCS) -I $(INCLUDES) -I $(LIB)/includes
	$(CC) $(FLAGS) $(FLAGS2) -o $(NAME) -I $(INCLUDES) -I $(LIB)/includes $(OBJS) $(MLX)/libmlx.a $(LIB)/libft.a


clean:
	make -C $(LIB) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIB) fclean
	rm -f $(NAME)

norme:
	make -C $(LIB) norme
	norminette $(SRCS) $(INCLUDES)/fractol.h

re: fclean $(NAME)
