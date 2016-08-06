#ifndef CLILIB
#define CLILIB

/*
 * =======================================================
 * =                  CLIlib based NCurses               =
 * =======================================================
 * @param author D.Kozin
 * @param year   2016 
 * @param 
 * @param
 */

#define BlocksPerColumn 20
#define BlocksPerRow 20

#include <ncurses.h>
#include <cstring>
#include <vector>

class CWidget
{
	protected:
			struct Point
				{
					unsigned int Y;
					unsigned int X;
				};
			Point startPoint;
};

class CController;

class CWindow : public CWidget
{
	private:
			WINDOW* currentWindow;
			const char* title;
			unsigned int height;
			unsigned int width;


			CWindow(const unsigned int& height, const unsigned int& width, const unsigned int& startY, const unsigned int& startX);
			~CWindow();
			inline WINDOW* createNewWindow(const unsigned int& height, const unsigned int& width, const unsigned int& startY = 0, const unsigned int& startX = 0);
			inline void update();
			inline void printTitle(const unsigned int& point, const char* title);
	public:
			friend class CController;
			void setTitle(const char* title);			
			void createFrame();
			void setCursor();
};


class CController // Mayer's singleton
{
	private:			
			CController(const unsigned int& screenHeight,const unsigned int& screenWidth, const unsigned int& blockHeight, const unsigned int& blockWidth);
			unsigned int screenHeight;
			unsigned int screenWidth;
			unsigned int blockHeight;
		  	unsigned int blockWidth;	
			std::vector<CWindow*> keeper;	

			inline static void initializeSession();
			inline static void setNoCursor();

	public:
			friend class CWindow;
			static CController& startSession();
			~CController();
			CWindow* createWindow(const unsigned int& sizeBlockY, const unsigned int& sizeBlockX, const unsigned int& startBlockY, const unsigned int& startBlockX);
};

#endif
