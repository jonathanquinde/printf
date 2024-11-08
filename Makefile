NAME = libftprintf.a

SRC = ft_printf.c char_str_handler.c number_handler.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJ) ft_printf.h
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@echo "Object files cleaned."

fclean: clean
	rm -f $(NAME)
	@echo "Library and object files cleaned."

re: fclean all

.PHONY: clean fclean re