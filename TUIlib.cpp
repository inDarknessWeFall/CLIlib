#include "TUIlib.h"

WINDOW* CWindow::createNewWindow(const unsigned int& height, const unsigned int& width, const unsigned int& startY, const unsigned int& startX)
{
		return newwin(height,width,startY,startX);
}

void CWindow::update()
{
		wrefresh(currentWindow);
}

void CWindow::createFrame()
{
		box(currentWindow,0,0);
		touchwin(currentWindow);
		update();
}

CWindow::CWindow(const unsigned int& height, const unsigned int& width, const unsigned int& startY = 0, const unsigned int& startX = 0)
{
		startPoint.Y = startY;
		startPoint.X = startX;
		currentWindow = createNewWindow(height,width,startY,startX);
		getmaxyx(currentWindow,this->height, this->width);
}

CWindow::~CWindow()
{
		delwin(currentWindow);
}

void CWindow::printTitle(const unsigned int& point, const char* title)
{
		mvwaddch(currentWindow, 0, point, ACS_RTEE);
		waddch(currentWindow, ' ');
		waddstr(currentWindow, title);
		waddch(currentWindow, ' ');
		waddch(currentWindow, ACS_LTEE);
		touchwin(currentWindow);
		wrefresh(currentWindow);
}

void CWindow::setTitle(const char* title)
{
		this->title = title;
		unsigned int stringSize = 4 + strlen(title);		
		unsigned int temp = (width - stringSize)/2;
		printTitle(temp,title);
}

CController::CController(const unsigned int& screenHeight,const unsigned int& screenWidth, const unsigned int& blockHeight, const unsigned int& blockWidth)
{
		this->screenHeight = screenHeight;
		this->screenWidth = screenWidth;
		this->blockHeight = blockWidth;
		this->blockWidth = blockWidth;
}

CController& CController::startSession()
{
		printf("Session was started\n");
		initscr();	
		int screenSizeY, screenSizeX;
		getmaxyx(stdscr, screenSizeY, screenSizeX);
		static CController instance(screenSizeY, screenSizeX, screenSizeY/BlocksPerColumn, screenSizeX/BlocksPerRow);
		return instance;
}

CController::~CController()
{
		endwin();
		printf("Session was stopped\n");
}

CWindow* CController::createWindow(const unsigned int& sizeBlockY, const unsigned int& sizeBlockX, const unsigned int& startBlockY, const unsigned int& startBlockX)
{
	return new CWindow(sizeBlockY*blockHeight, sizeBlockX*blockWidth, startBlockY*blockHeight, startBlockX*blockWidth);	
}
