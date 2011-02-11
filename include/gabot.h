#ifndef GABOT_H
#define GABOT_H

#include <qobject.h>

#include "coordinate.h" // need full def for moc
#include "direction.h"
#include "simplega.h"

// object prototypes
class QString;
class Team;
class Coordinate;
class Game;
class QTimer;

/// GA Bot data object
class GABot : public QObject
{

Q_OBJECT

public:
	/// Constructor
	GABot(QObject *parent=0, const char * name = 0);
	/// Destructor
	~GABot();

	/// Load a rule set from Filename into TeamNumber
	int loadTeamFromFile(QString Filename, int TeamNumber);

	/// Save a team to file
	int saveTeamToFile(QString Filename, int TeamNumber);
	/// Generate Random team
	void randomTeam(int TeamNumber);

protected:

	/// Pointer to Team A object
	Team *TeamA;
	/// Pointer to Team B object
	Team *TeamB;
	/// Timer for interval between moves
	QTimer *Tick;
	/// Tick interval in milliseconds
	int TickInterval;
	/// Game instance
	Game *GAGame;
	
	/// Genetic Algorithm instance
	SimpleGA GenAlg;

	/// Prepares the game object
	void prepareGame(void);

protected slots:

	/// Executed every tick interval, if Timer isActive()
	void slotTurn(void);

	/// Game class has indicated the ball has moved
	void slotBallMoved(Coordinate,Coordinate);
	/// Team class has indicated a Bot from Team A has moved
	void slotBotMoveA(Coordinate,Coordinate);
	/// Team class has indicated a Bot from Team B has moved
	void slotBotMoveB(Coordinate,Coordinate);
	/// Team class has indicated a Bot from Team A has changed Direction
	void slotBotDirectionA(Coordinate,Direction);
	/// Team class has indicated a Bot from Team B has changed Direction
	void slotBotDirectionB(Coordinate,Direction);

	/// Execute when Team A scores
	void slotTeamAScores(void);
	/// Execute when Team B scores
	void slotTeamBScores(void);
	/// Clear the field in the Arena
	void slotClearField(void);

public slots:

	/// Change the tickInterval
	void slotTickInterval(int);
	/// Activate the timer (Go!)
	void slotStartTimer(void);
	/// Stop the timer (Pause)
	void slotStopTimer(void);
	/// End the game
	void slotGameOver(void);

signals:
	
	/// Signal that Team A has Scored 
	void teamAScores(void);
	/// Signal that Team B has Scored
	void teamBScores(void);
	/// Signal that the scores should be cleared
	void clearScores(void);
	/// Signal that ball should be spawned at Coord
	void putBall(Coordinate);
	/// Signal that ball has moved
	void moveBall(Coordinate,Coordinate);
	/// Signal that a team A bot has moved
	void moveTeamA(Coordinate, Coordinate);
	/// Signal that a team B bot has moved
	void moveTeamB(Coordinate, Coordinate);
	/// Signal that a team A bot has turned Direction
	void turnTeamA(Coordinate, Direction);
	/// Signal that a team B bot has turned Direction
	void turnTeamB(Coordinate, Direction);
	/// Signal that the field should be cleared
	void clearField(void);
	/// Signal that it is safe to start a game
	void gameReady(bool);
	/// Signal that the current game is over
	void gameOver(void);

};

#endif
