#include "TUIlib.h"

WINDOW* Window::createNewWindow(const int& height, const int& width, const  int& startY, const int& startX)
{
		WINDOW* local = newwin(height,width,startY,startX);
		printf("Created new window\n");
		return local;
}

void Window::update()
{
		wrefresh(currentWindow);
}

void Window::createFrame()
{
		box(currentWindow,0,0);
		touchwin(currentWindow);
		update();
}

Window::Window()
{
		currentWindow = createNewWindow(10,20,5,5);
}

Window::~Window()
{
		delwin(currentWindow);
		printf("Window was deleted successfully!\n");
}

void Window::setTitle(char title[length])
{
		
}
