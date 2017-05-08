NAME=test

ifeq ($(OS), Windows_NT)
	OS_Detected := Windows
else
	OS_Detected := Linux
endif

CC=g++
FLAGS= -std=c++0x

ifeq ($(OS_Detected), Windows)
	OUTPUT=$(NAME).exe
	INCLUDES= H:\SDL2-2.0.5\include
else
	OUTPUT=$(NAME)
	INCLUDES= /usr/include/SDL2
endif

ifeq ($(OS_Detected), Windows)
	LIBDIRS= H:\SDL2-2.0.5\lib\x86
	LIBS= SDL2
	LIB= -L $(LIBDIRS) -l$(LIBS)
else
	LIB= -lSDL2
endif

CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))

ifeq ($(OS_Detected), Windows)
	OS_Build := $(NAME)_win.exe
	COPY := copy /Y $(OUTPUT) build\$(OS_Build)
else
	OS_Build := $(NAME)_linux
	COPY := cp -rf $(OUTPUT) build/$(OS_Build)
endif

$(OS_Build): $(NAME)
	$(COPY)

$(NAME): $(OBJ_FILES)
	$(CC) $(FLAGS) -o $@ $^ $(LIB)

obj/%.o: src/%.cpp
	$(CC) $(FLAGS) -c -I $(INCLUDES) -o $@ $<

.PHONY : clean
clean:
	rm $(OUTPUT) $(OBJ_FILES)

run: $(NAME)
	./$(NAME)
