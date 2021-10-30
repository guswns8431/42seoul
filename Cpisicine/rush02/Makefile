CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = rush-02
OBJECT = $(SRC:.c=.o)
HEADER = header
SRC = $(wildcard src/*.c)

all : $(TARGET)

%.o : %.c
	CC $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(TARGET) : $(OBJECT)
	CC $(CFLAGS) -o $@ $^

clean :
	rm ./src/*.o

fclean : clean
	rm rush-02

