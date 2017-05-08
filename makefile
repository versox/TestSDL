NAME=test

CC=g++
FLAGS= -std=c++0x
INCLUDES= H:\SDL2-2.0.5\include
LIBDIRS= H:\SDL2-2.0.5\lib\x86
LIBS= SDL2
	
CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))

$(NAME): $(OBJ_FILES)
	$(CC) $(FLAGS) -o $@ $^ -L $(LIBDIRS) -l$(LIBS)

obj/%.o: src/%.cpp
	$(CC) $(FLAGS) -c -I $(INCLUDES) -o $@ $<

.PHONY : clean
clean:
	rm test.exe $(OBJ_FILES)

run: $(NAME)
	./$(NAME)
