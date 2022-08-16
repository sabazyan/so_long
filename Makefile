NAME = so_long
SRC = $(wildcard ./*.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

FLAGS = -Wall -Wextra -Werror
LINKS = -lmlx -framework OpenGL -framework AppKit
CC = gcc

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LINKS)
exe: all
	./$(NAME)
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all 

.PHONY: all clean fclean re exe
