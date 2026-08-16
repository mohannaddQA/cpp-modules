NAME=megaphone
cc=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
SRC=megaphone.cpp
OBJ=$(patsubst %.cpp,%.o,$(SRC))

# This disables the implicit rules of Makefile
# MAKEFLAGS += -r

all: $(NAME)

# After we have the OBJ we link
$(NAME): $(OBJ)
	$(COMPILER) $(FLAGS) $(OBJ) -o $(NAME)

# Objects are automatically generated throuh the implicit rules

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
	


