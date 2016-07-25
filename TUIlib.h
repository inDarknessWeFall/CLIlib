/*
 * =======================================================
 * =                  CLIlib based NCurses               =
 * =======================================================
 * @param author D.Kozin
 * @param year   2016 
 * @param 
 * @param
 */

#include <ncurses.h>
#include <vector>

using namespace std;


class ConsoleWidget 
{
	// code it after, abstract class used just for polymorphism 
};

// TODO: controller //
class ConsoleController
{
	private:
			WINDOW* screen;
			vector<ConsoleWidget> allWidgets;
			void update();
						
	public:
			void deleteWidget();
			void addWidget();

};


class Split : public ConsoleWidget
{
	// need for split stdscr
};

class Panel : public ConsoleWidget
{
	// TODO: vector of Horisontal Split
};

class Window: public ConsoleWidget // TODO: modalWindow
{
	private:
			WINDOW* currentWindow;
			unsigned int maxY;
			unsigned int maxX;
		
			inline void createBorder();		
			inline void GetWindowProperties();
		
	public:
			Window();

};

class ModalWindow : public Window
{
	private:
		char[] title;
		void setTitle;	
};

// Description:
// Further will be items (buttons, labels, menu, scrollbar maybe)

class Button : public ConsoleWidget
{
// TODO:
};

class Label : public ConsoleWidget
{
		
};

class Radiobutton : public ConsoleWidget
{
		
};

class Checkbox : public ConsoleWidget
{

};
