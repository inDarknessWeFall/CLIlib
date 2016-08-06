#include "CLIlib.h"

CController::CController(const unsigned int& screenHeight,const unsigned int& screenWidth, const unsigned int& blockHeight, const unsigned int& blockWidth)
{
		this->screenHeight = screenHeight;
		this->screenWidth = screenWidth;
		this->blockHeight = blockWidth;
		this->blockWidth = blockWidth;
}

void CController::initializeSession()
{
	initscr();
}

void CController::setNoCursor()
{
	curs_set(0);
}

CController& CController::startSession()
{
		printf("Session was started\n");
		initializeSession();
		setNoCursor();
		int screenSizeY, screenSizeX;
		getmaxyx(stdscr, screenSizeY, screenSizeX);
		static CController instance(screenSizeY, screenSizeX, screenSizeY/BlocksPerColumn, screenSizeX/BlocksPerRow);
		return instance;
}

CWindow* CController::createWindow(const unsigned int& sizeBlockY, const unsigned int& sizeBlockX, const unsigned int& startBlockY, const unsigned int& startBlockX)
{
	CWindow* win = new CWindow(sizeBlockY*blockHeight, sizeBlockX*blockWidth, startBlockY*blockHeight, startBlockX*blockWidth);	
	keeper.push_back(win);
	return win;	
}

CController::~CController()
{
		for(std::vector<CWindow*>::iterator it  = keeper.begin(); it != keeper.end(); it++)
					delete *(it);
		keeper.clear();

		endwin();
		printf("Session was stopped\n");
}
