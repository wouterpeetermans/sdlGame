#OBJS specifies wicht files to compile
OBJS = src/main.cpp src/Scene.cpp src/Gvector.cpp src/Sprite.cpp src/Background.cpp src/Hero.cpp src/Brick.cpp src/Level.cpp src/Level1.cpp src/Enemy.cpp src/SpikesUp.cpp src/Level2.cpp

#CC spesifies compiler
CC = g++
#CW is compiler for windows
CW = i586-mingw32msvc-g++
#COMPILER_FLAGS aditional options to use
#-w suppress all warnings
COMPILER_FLAGS = -Wall -std=c++11

#LINKER_FLAGS linked libraries
LINKER_FLAGS = -lSDL2 -lSDL2_image
LINKER_FLAGS_WIN = -L SDL

#OBJ_NAME name of the compiled file
OBJ_NAME = game/sdlGame
OBJ_NAME_WIN = game/sdlGame.exe

#compile to executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

windows : $(OBJS)
	$(CW) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS_WIN) $(LINKER_FLAGS) -o $(OBJ_NAME_WIN)
