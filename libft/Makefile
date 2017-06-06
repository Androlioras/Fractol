NAME = libft.a
CC = gcc
INCLUDES = includes
SRC = srcs
LIBFT = libft
FLAGS = -Wall -Wextra -Werror
SRCS = $(SRC)/ft_printf.c\
	   $(SRC)/if_forest.c\
	   $(SRC)/number.c\
	   $(SRC)/unsigned.c\
	   $(SRC)/string.c\
	   $(SRC)/char.c\
	   $(SRC)/params.c\
	   $(SRC)/pointer.c\
	   $(SRC)/long.c\
	   $(SRC)/other.c
OBJ = $(SRCS:.c=.o)
OBJS = $(OBJ:$(SRC)/%=%)

.PHONY: clean fclean all re norme

$(NAME):
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a $(NAME)
	$(CC) $(FLAGS) -I $(INCLUDES) -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	make -C $(LIBFT) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT) fclean
	rm -f $(NAME)

norme:
	make -C $(LIBFT) norme
	norminette $(SRCS) $(INCLUDES)/ft_printf.h

all: $(NAME)

re: fclean all
