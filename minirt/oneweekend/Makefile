NAME = minirt

all :
	gcc ./scene/*.c ./src/*.c ./src/*/*.c ./src/*/*/*.c -o $(NAME) -I./include
clean :
	rm -rf $(NAME)
	rm -rf result.ppm
re : clean all

run : $(NAME)
	./$(NAME)
ppm : all
	./$(NAME) > result.ppm
.PHONY : all clean re
##
