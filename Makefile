all:
	g++ main.cpp character.cpp character.hpp -o exec -g -s -lncursesw -pthread

run:
	./exec

valgrind:
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./main 

zip:
	zip projeto.zip main.cpp character.cpp character.hpp Makefile

clean:
	rm *.o exec