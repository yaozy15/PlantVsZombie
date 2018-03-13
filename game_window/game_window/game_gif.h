#ifndef GAME_GIF_H
#define GAME_GIF_H
#include<qlabel.h>
#include<qmovie.h>
class gameGif :public QObject
{
	Q_OBJECT;
private:
//	QLabel Label;
	QMovie Pic;
public:
	gameGif(QWidget* parent = 0);
	gameGif(const QString &filename, QWidget* parent = 0);
	~gameGif();
public:
	void setGif(const QString &filename);
	
};

#endif
