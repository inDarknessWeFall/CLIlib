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
		startPoint.Y = startY;
		startPoint.X = startX;
		currentWindow = createNewWindow(height,width,startY,startX);
		getmaxyx(currentWindow, maxY,maxX);
}

Window::~Window()
{
		delwin(currentWindow);
}

void Window::printTitle(unsigned int point, const char* title)
{
		mvwaddch(currentWindow, 0, point, ACS_RTEE);
		waddch(currentWindow, ' ');
		waddstr(currentWindow, title);
		waddch(currentWindow, ' ');
		waddch(currentWindow, ACS_LTEE);
		touchwin(currentWindow);
		wrefresh(currentWindow);
}

void Window::setTitle(const char* title)
{
		this->title = title;
		unsigned int stringSize = 4 + strlen(title);		
		unsigned int temp = (maxX - stringSize)/2;
		printTitle(temp,title);
}
