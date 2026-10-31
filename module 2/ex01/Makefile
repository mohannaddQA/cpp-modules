NAME=fixed
CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98 -MMD -MP
SRC=main.cpp Fixed.cpp
OBJ=$(patsubst %.cpp,%.o,$(SRC))
DEP=$(patsubst %.cpp,%.d,$(SRC))

# This disables the implicit rules of Makefile
# MAKEFLAGS += -r

all: $(NAME)

# After we have the OBJ we link
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c -o $@ $<

-include $(DEP)

clean:
	rm -f $(OBJ) $(DEP)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
