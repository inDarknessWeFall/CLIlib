/*
 * =======================================================
 * =                  CLIlib based NCurses               =
 * =======================================================
 * @param author D.Kozin
 * @param year   2016 
 * @param 
 * @param
 */

////////////////
// Using TDD  //
////////////////

#include <ncurses.h>
#include <string.h>

class CWidget
{
/////////////////
// Main class  //
/////////////////
		protected:
				struct Point
				{
						unsigned int Y;
						unsigned int X;
				};
				Point startPoint;
};

class Window : public CWidget
{
	private:
			WINDOW* currentWindow;
			const char* title;
			int maxY;
			int maxX;

			WINDOW* createNewWindow(const int& height = 0, const int& width = 0, const int& startY = 0, const int& startX = 0);
			inline void update();
			inline void printTitle(unsigned int point, const char* title);
	public:
			Window(const int& height, const int& width, const int& startY, const int& startX);
			~Window();
			void setTitle(const char* title);			
			void createFrame();
			WINDOW* returnWINDOW();
};
