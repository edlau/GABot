/********************************************************************
 * -= C++ =-
 *
 ********************************************************************/

#include <qlayout.h>
#include <qlcdnumber.h>
#include <qvbox.h>
#include <qslider.h>

#include "botview.h"
#include "arena.h"
#include "coordinate.h"
#include "direction.h"

//-----------------------------------------------------------------
BotView::BotView(QWidget *parent,const char *name, int w, int h) 
	: QWidget(parent,name)
{
	FieldWidth  = w;
	FieldHeight = h;
	ScoreA = ScoreB = 0;

	QVBox *Box = new QVBox( this, 0 );
	Box->setFrameStyle( QFrame::WinPanel | QFrame::Sunken );
	Field = new Arena( Box, "Field" );

	LCDScoreA  = new QLCDNumber( this, 0 );
	LCDScoreA->setMaximumSize(LCDScoreA->size());
	LCDScoreA->setMinimumSize(LCDScoreA->size());
	LCDScoreB  = new QLCDNumber( this, 0 );
	LCDScoreB->setMaximumSize(LCDScoreB->size());
	LCDScoreB->setMinimumSize(LCDScoreB->size());

	QSlider *TimerSlider = new QSlider( 25, 1000, 25, 250, QSlider::Horizontal, this);
	TimerSlider->setTracking(TRUE);
	TimerSlider->setMinimumSize(250,TimerSlider->height());
	TimerSlider->setMaximumSize(250,TimerSlider->height());

	QGridLayout *Grid = new QGridLayout( this, 1, 1, 10 );
	Grid->addWidget( LCDScoreA, 0, 0, Qt::AlignLeft);
	Grid->addWidget( TimerSlider, 0, 0, Qt::AlignCenter);
	Grid->addWidget( LCDScoreB, 0, 0, Qt::AlignRight);
	Grid->addWidget( Box, 1, 0 );

	Field->setMaximumSize(FieldWidth,FieldHeight);
	Field->setMinimumSize(FieldWidth,FieldHeight);
	Box->setMaximumSize(Field->size());
	Box->setMinimumSize(Field->size());

	connect(TimerSlider, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged(int)));
}
//-----------------------------------------------------------------
BotView::~BotView()
{
}
//-----------------------------------------------------------------
int BotView::fieldWidth(void)
{
	return FieldWidth;
}
//-----------------------------------------------------------------
int BotView::fieldHeight(void)
{
	return FieldHeight;
}
//-----------------------------------------------------------------
int BotView::fieldWidth(int A)
{
	if (A > 0) {
		FieldWidth = A;
		repaint();
		return A;
	} else {
		return 0;
	}
}
//-----------------------------------------------------------------
int BotView::fieldHeight(int A)
{
	if (A > 0) {
		FieldHeight = A;
		repaint();
		return A;
	} else {
		return 0;
	}
}
//-----------------------------------------------------------------
void BotView::slotScoreA(void)
{
	ScoreA++;
	LCDScoreA->display(ScoreA);
}
//-----------------------------------------------------------------
void BotView::slotScoreB(void)
{
	ScoreB++;
	LCDScoreB->display(ScoreB);
}
//-----------------------------------------------------------------
void BotView::slotClearScores(void)
{
	ScoreA = ScoreB = 0;
	LCDScoreA->display(0);
	LCDScoreB->display(0);
}
//-----------------------------------------------------------------
void BotView::slotClearField(void)
{
	Field->clearAll();
}
//-----------------------------------------------------------------
void BotView::slotMoveBall(Coordinate Old, Coordinate New)
{
	if (!(Old.x == New.x && Old.y == New.y)) Field->clearAt(Old.x*10,Old.y*10);
	Field->putBall(New.x*10,New.y*10);
}
//-----------------------------------------------------------------
void BotView::slotMoveTeamA(Coordinate P1, Coordinate P2)
{
	if (P1.x == P2.x && P1.y == P2.y) {
		return;
	} 
	int Dir;
	if (P1.x == P2.x && P1.y > P2.y)      Dir = 0;
	else if (P1.x < P2.x && P1.y > P2.y)  Dir = 45;
	else if (P1.x < P2.x && P1.y == P2.y) Dir = 90;
	else if (P1.x < P2.x && P1.y < P2.y)  Dir = 135;
	else if (P1.x == P2.x && P1.y < P2.y) Dir = 180;
	else if (P1.x > P2.x && P1.y < P2.y)  Dir = 225;
	else if (P1.x > P2.x && P1.y == P2.y) Dir = 270;
	else Dir = 315;
	Field->clearAt(10*P1.x,10*P1.y);
	Field->putBotA(10*P2.x,10*P2.y,Dir);
}
//-----------------------------------------------------------------
void BotView::slotMoveTeamB(Coordinate P1, Coordinate P2)
{
	if (P1.x == P2.x && P1.y == P2.y) {
		return;
	}
	int Dir;
	if (P1.x == P2.x && P1.y > P2.y)      Dir = 0;
	else if (P1.x < P2.x && P1.y > P2.y)  Dir = 45;
	else if (P1.x < P2.x && P1.y == P2.y) Dir = 90;
	else if (P1.x < P2.x && P1.y < P2.y)  Dir = 135;
	else if (P1.x == P2.x && P1.y < P2.y) Dir = 180;
	else if (P1.x > P2.x && P1.y < P2.y)  Dir = 225;
	else if (P1.x > P2.x && P1.y == P2.y) Dir = 270;
	else Dir = 315;
	Field->clearAt(10*P1.x,10*P1.y);
	Field->putBotB(10*P2.x,10*P2.y,Dir);
}
//-----------------------------------------------------------------
void BotView::slotValueChanged(int V)
{
	emit(valueChanged(V));
}
//-----------------------------------------------------------------
void BotView::slotTurnTeamA(Coordinate P1, Direction B)
{
	int Dir = 45 * B;
	Field->putBotA(10*P1.x,10*P1.y,Dir);
}
//-----------------------------------------------------------------
void BotView::slotTurnTeamB(Coordinate P1, Direction B)
{
	int Dir = 45 * B;
	Field->putBotB(10*P1.x,10*P1.y,Dir);
}
//-----------------------------------------------------------------
