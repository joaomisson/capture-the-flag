objects = main.cpp includes/*.hpp src/*cpp

all: $(objects)
	g++ $(objects) -o exec -g -s -lncursesw -pthread -Wall -Werror

run: all
	./exec

valgrind:
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./main 

zip:
	zip projeto.zip main.cpp game.cpp game.hpp player.cpp player.hpp flag.cpp flag.hpp interface.cpp interface.hpp Makefile

clean:
	rm *.o exec

	