#ifndef BOTVIEW_H
#define BOTVIEW_H

#include <qwidget.h>
#include "coordinate.h" // req by moc
#include "direction.h"

class Arena;
class QLCDNumber;
class Coordinate;

///  This is not the actual "playing field" widget.  It is simply the main
///  widget that will own all the others 
class BotView : public QWidget
{

Q_OBJECT

public:
	/// Constructor
	BotView(QWidget *parent,const char*name=0,int w=800,int h=400);
	/// Destructor
	~BotView();
	/// Return the playing field's width
	int fieldWidth(void);
	/// Return the playing field's width
	int fieldHeight(void);
	/// Set the arena Width, return true on success
	int fieldWidth(int);
	/// Set the arena Height, return true on success
	int fieldHeight(int);

public slots:

	/// Increases Team A's score by one
	void slotScoreA(void);
	/// Increases Team B's score by one
	void slotScoreB(void);
	/// Resets the LCD scores
	void slotClearScores(void);
	/// Resets the Field
	void slotClearField(void);
	/// Moves a bot
	void slotMoveTeamA(Coordinate, Coordinate);
	/// Moves a bot
	void slotMoveTeamB(Coordinate, Coordinate);
	/// Turns a bot
	void slotTurnTeamA(Coordinate, Direction);
	/// Turns a bot
	void slotTurnTeamB(Coordinate, Direction);
	/// Moves the ball, spawns a ball if needed
	void slotMoveBall(Coordinate,Coordinate);

protected slots:

	/// Relay slot for changing game speed
	void slotValueChanged(int);

signals:
	/// Relay signal for changing game speed
	void valueChanged(int);

protected:

	/// Pointer to the widget that is the "playing field"
	Arena *Field;
	/// LCD widget for Team A's score
	QLCDNumber *LCDScoreA;
	/// LCD widget for Team B's score
	QLCDNumber *LCDScoreB;
	/// Width of field
	int FieldWidth;
	/// Height of field
	int FieldHeight;
	/// Team A's score
	int ScoreA;
	/// Team B's score
	int ScoreB;

};

#endif
