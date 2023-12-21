##
## EPITECH PROJECT, 2022
## Stumper
## File description:
## Makefile
##

SRC =   $(wildcard *.c)

OBJ = $(SRC:.c=.o)

CFLAGS = -W -Wall -Wextra -Iinclude/ -g3

LDFLAGS = -lcsfml-graphics -lcsfml-system -lm

TARGET = my_rpg

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)

re: fclean all
