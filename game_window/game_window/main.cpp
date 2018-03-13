#include "game_window.h"
#include <QtWidgets/QApplication>
#include"game_controller.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	game_window w;

	w.setWindowFlags(Qt::WindowCloseButtonHint);
	w.show();
	return a.exec();
}
