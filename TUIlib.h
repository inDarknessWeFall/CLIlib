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
	private:
			struct Poit{
					unsigned int Y;
					unsigned int X;
			};
			
			struct startPoint;
	// code it after, abstract class used just for polymorphism 
};

class Split : public ConsoleWidget
{
	// need for split stdscr
};

// TODO: controller //
// Controller will create splits
// 

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


class Panel : public ConsoleWidget
{
	// TODO: vector of Splits
};

class Window: public ConsoleWidget // TODO: modalWindow
{
	private:
			WINDOW* currentWindow;
	
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
