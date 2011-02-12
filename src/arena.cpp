#include <qpainter.h>
#include <qpixmap.h>

#include "arena.h"
#include "bot_a.xpm"
#include "bot_b.xpm"

//-----------------------------------------------------------------

Arena::Arena( QWidget *parent, const char *name )
        : QWidget( parent, name )
{
	QPixmap Image;
	Image.load("rink.png",0);
	setBackgroundPixmap(Image);
	BotImageA = new QPixmap(BotA_XPM);
	BotImageB = new QPixmap(BotB_XPM);
}

//-----------------------------------------------------------------

Arena::~Arena()
{
	delete BotImageA;
	delete BotImageB;
}

//-----------------------------------------------------------------

void Arena::paintEvent( QPaintEvent *e )
{

}

//-----------------------------------------------------------------

void Arena::putBotA(int X, int Y, int A)
{
	if (X == -1 || Y == -1) return;
	QRect Area(X,Y,10,10);
	QPixmap Pix( Area.size() );
	Pix.fill( this, Area.topLeft() );
	QPainter p( &Pix );
	p.translate( Pix.width()/2.0, Pix.height()/2.0);
	p.rotate( A );
	p.translate( -Pix.width()/2.0, -Pix.height()/2.0);
	p.drawPixmap(0,0,*BotImageA);
	p.end();
	p.begin( this );
	p.drawPixmap( Area.topLeft(), Pix );
}

//-----------------------------------------------------------------

void Arena::putBotB(int X, int Y, int A)
{
	if (X == -1 || Y == -1) return;
	QRect Area(X,Y,10,10);
	QPixmap Pix( Area.size() );
	Pix.fill( this, Area.topLeft() );
	QPainter p( &Pix );
	p.translate( Pix.width()/2.0, Pix.height()/2.0);
	p.rotate( A );
	p.translate( -Pix.width()/2.0, -Pix.height()/2.0);
	p.drawPixmap(0,0,*BotImageB);
	p.end();
	p.begin( this );
	p.drawPixmap( Area.topLeft(), Pix );
}

//-----------------------------------------------------------------

void Arena::clearAt(int X, int Y)
{
	QRect Area(X,Y,10,10);
	QPixmap Pix( Area.size() );
	Pix.fill( this, Area.topLeft() );
	QPainter p( this );
	p.drawPixmap ( Area.topLeft(), Pix );
	p.end();
}

//-----------------------------------------------------------------
void Arena::putBall(int X, int Y)
{
	QPainter p ( this );
	p.setBrush( blue );
	p.setPen( NoPen );
	p.drawEllipse ( X+5.5, Y+5.5, 5.5, 5.5 );
	p.end();
}
//-----------------------------------------------------------------
void Arena::clearAll(void)
{
	repaint();
}
//-----------------------------------------------------------------
