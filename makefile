NAME=test

CC=g++
FLAGS= -std=c++11
INCLUDES= /usr/include/SDL2
LIBS= SDL2

CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))

$(NAME): $(OBJ_FILES)
	$(CC) -o $@ $^ -l$(LIBS)

obj/%.o: src/%.cpp
	$(CC) -c -I $(INCLUDES) -o $@ $<

.PHONY : clean
clean:
	rm test $(OBJ_FILES)

run: $(NAME)
	./$(NAME)
