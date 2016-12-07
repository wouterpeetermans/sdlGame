#OBJS specifies wicht files to compile
OBJS = src/main.cpp src/Scene.cpp src/Drawable.cpp

#CC spesifies compiler
CC = g++

#COMPILER_FLAGS aditional options to use
#-w suppress all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS linked libraries
LINKER_FLAGS = -lSDL2 -lSDL2_image

#OBJ_NAME name of the compiled file
OBJ_NAME = game/sdlGame

#compile to executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
