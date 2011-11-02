#include "sjgfitness.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SJGFitness w;
	w.show();
	return (a.exec());
}
