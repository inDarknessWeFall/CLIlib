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

class Window
{
	private:
			WINDOW* currentWindow;
			WINDOW* createNewWindow(const int& height, const int& width, const int& startY, const int& startX);
			inline void update();
			char title[length];

	public:
			Window();
			~Window();
			void setTitle(char title[length]);			
			void createFrame();
			WINDOW* returnWINDOW();
};
