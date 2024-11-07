NAME = libftprint.a

SRC = ft_print.c char_str_handler.c number_handler.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	@echo "Object files cleaned."

fclean: clean
	rm -f $(NAME)
	@echo "Library and object files cleaned."

re: fclean all

.PHONY: clean fclean re