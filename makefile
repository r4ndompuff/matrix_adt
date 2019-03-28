PROG = matrix
CC = c++
C_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(C_FILES:.cpp=.o)))
CC_FLAGS := -Wall -Wextra -g -std=c++11

$(PROG): $(OBJ_FILES)
	$(CC) -o $@ $^
	$(CC) -g ./tests/tests.cpp ./obj/matrix.o -o testing
	echo "type: make help"

obj/%.o: src/%.cpp
	$(CC) $(CC_FLAGS) -c -o $@ $<

test:
	./testing	

clean:
	rm -rf shell ./obj/*.o *.dSYM $(PROG) testing

run:
	./$(PROG)

valgrind:
	valgrind --track-origins=yes --leak-check=full ./$(PROG)

help:
	echo "You can use make with test/clean/run/valgrind/help"