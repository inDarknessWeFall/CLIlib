#include "src/CLIlib.h"

int main(int argc, char *argv[])
{
	CController contr = CController::startSession();

	CWindow* s = contr.createWindow(3,3,0,0);
	s->createFrame();
	s->setTitle("Fuck this system");
	s->setCursor();


	getchar();
	return 0;
}
