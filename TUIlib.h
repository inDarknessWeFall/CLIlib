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

#define length 24

using namespace std;

class CWidget
{
/////////////////
// Main class  //
/////////////////
		private:
				struct Point
				{
						unsigned int Y;
						unsigned int X;
				};

};

class Window : public CWidget
{
	private:
			WINDOW* currentWindow;
			WINDOW* createNewWindow(const int& height = 0, const int& width = 0, const int& startY = 0, const int& startX = 0);
			inline void update();
			char title[length];

	public:
			Window(const int& height, const int& width, const int& startY, const int& startX);
			~Window();
			void setTitle(char title[length]);			
			void createFrame();
			WINDOW* returnWINDOW();
};
