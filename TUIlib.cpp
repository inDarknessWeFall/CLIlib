#include "TUIlib.h"

WINDOW* Window::createNewWindow(const int& height, const int& width, const  int& startY, const int& startX)
{
		WINDOW* local = newwin(height,width,startY,startX);
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

Window::Window(const int& height = 0, const int& width = 0, const int& startY = 0, const int& startX = 0)
{
		currentWindow = createNewWindow(height,width,startY,startX);
}

Window::~Window()
{
		delwin(currentWindow);
}

void Window::setTitle(char title[length])
{
	
}
