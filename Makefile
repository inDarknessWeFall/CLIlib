CC=g++
GRAPHICLIB=-lncurses
OUTPUT=-o
CFLAGS=-c

CCONTROLLER=CController.o
CWINDOW=CWindow.o

all: project

$(CCONTROLLER): src/CController.cpp
	$(CC) $(CFLAGS) src/CController.cpp $(GRAPHICLIB) 

$(CWINDOW): src/CWindow.cpp
	$(CC) $(CFLAGS) src/CWindow.cpp $(GRAPHICLIB)

project: $(CCONTROLLER) $(CWINDOW)
	$(CC) main.cpp $(CCONTROLLER) $(CWINDOW) $(OUTPUT) main $(GRAPHICLIB)

clean:
	rm -rf *.o project main
