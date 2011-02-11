#ifndef ARENA_H
#define ARENA_H

#include <qwidget.h>

class QPixmap;

/// A graphical representation of the arena
/// This class does not currently store locations of the bots, that task
/// must be looked after by the data classes
class Arena : public QWidget
{

Q_OBJECT

public:
	/// Constructor
	Arena( QWidget *parent=0, const char *name=0 );
	/// Destructor
	~Arena();

	/// Places a team A pixmap at (X,Y), with Rotation R
	void putBotA (int X,int Y,int R);
	/// Places a team B pixmap at (X,Y), with Rotation R
	void putBotB (int X,int Y,int R);
	/// Places the ball at (X,Y)
	void putBall (int X,int Y);
	/// Clears a grid square with UL Corner (X,y)
	void clearAt (int X,int Y);
	/// Clears the entire arena
	void clearAll(void);

protected:

	/// QT Repaint event
	void paintEvent( QPaintEvent * );
	/// Pixmap image for Team A
	QPixmap *BotImageA;
	/// Pixmap image for Team B
	QPixmap *BotImageB;

};


#endif

