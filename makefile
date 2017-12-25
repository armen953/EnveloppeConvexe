LIB_PATHS= -L/usr/X11R6/lib -L/usr/lib
HDR_PATHS= -I/usr/X11R6/include
LIBS=-lglut -lGLU -lGL -lm -L/usr/X11/lib -lXext -lXmu -lXi -lX11 -std=c++98


CC=g++
EXEC=convexe # nom de l'executable
SRC= dPoint.cpp ColorPoint.cpp OpenGL.cpp ConvexeHullAlgorithms.cpp Utility.cpp
OBJ= $(SRC:.c=.o)
CXXFLAGS=$(HDR_PATHS) -Wno-deprecated 

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LIB_PATHS) $(LIBS) 

%.o: %.cpp
	$(C) -o $@ -c $< 

clean :
	rm -rf *.o
	touch *.cc #*.h

delete :
	rm -f *.h~
	rm -f *.cc~
