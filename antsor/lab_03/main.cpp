#include "window.h"
#include <QApplication>

#include "controller.h"
#include "cabine.h"
#include "doors.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	Cabine cabine;
	Doors doors;
	ElevatorController controller(cabine, doors);
	
	Window w(controller);
	w.show();
	
	return a.exec();
}
