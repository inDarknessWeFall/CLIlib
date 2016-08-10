CC=g++
GRAPHICLIB=-lncurses
OUTPUT=-o
CFLAGS=-c

CCONTROLLER=CController.o
CWINDOW=CWindow.o

PROJECTFILE=main.cpp

all: project

$(CCONTROLLER): src/CController.cpp
	$(CC) $(CFLAGS) src/CController.cpp $(GRAPHICLIB) 

$(CWINDOW): src/CWindow.cpp
	$(CC) $(CFLAGS) src/CWindow.cpp $(GRAPHICLIB)

project: $(CCONTROLLER) $(CWINDOW) $(PROJECTFILE) 
	$(CC) $(PROJECTFILE) $(CCONTROLLER) $(CWINDOW) $(OUTPUT) project $(GRAPHICLIB)

clean:
	rm -rf *.o project 
