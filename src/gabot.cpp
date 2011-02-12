/********************************************************************
 ********************************************************************/

// QT includes
#include <qstring.h>
#include <qtimer.h>

// App specific includes
#include "gabot.h"
#include "team.h"
#include "teamdata.h"
#include "game.h"

//-----------------------------------------------------------------
GABot::GABot(QObject *parent, const char * name)
	: QObject(parent,name)
{
	// Set our pointers to null
	TeamA = TeamB = 0;
	GAGame = 0;
	
	// initialize mutation rate (fixed at 5% right now)
	GenAlg.mutationRate(0.05);

	// Set up our game ticker
	TickInterval = 500;
	Tick = new QTimer(this);
	connect(Tick, SIGNAL(timeout()), this, SLOT(slotTurn()) );
}
//-----------------------------------------------------------------
GABot::~GABot()
{

}
//-----------------------------------------------------------------
int GABot::loadTeamFromFile( QString Filename, int TeamNumber )
{
	int Err=0;

	TeamData data;
	if (TeamNumber == 0) {
		TeamA = data.readTeamData(Filename);
		if (TeamA) {
			Err = 1;
			insertChild(TeamA);
			connect( TeamA, SIGNAL(botMove(Coordinate,Coordinate)),
			         this,  SLOT(slotBotMoveA(Coordinate,Coordinate)));
			connect( TeamA, SIGNAL(botDirection(Coordinate,Direction)),
			         this,  SLOT(slotBotDirectionA(Coordinate,Direction)));
		}
	} else if (TeamNumber == 1) {
		TeamB = data.readTeamData(Filename);
		if (TeamB) {
			Err = 1;
			insertChild(TeamB);
			connect( TeamB, SIGNAL(botMove(Coordinate,Coordinate)),
			         this,  SLOT(slotBotMoveB(Coordinate,Coordinate)));
			connect( TeamB, SIGNAL(botDirection(Coordinate,Direction)),
			         this,  SLOT(slotBotDirectionB(Coordinate,Direction)));
		}
	}

	if (TeamA && TeamB) {
		prepareGame();
		emit(gameReady(TRUE));
	}

	return Err;

}
//-----------------------------------------------------------------
int GABot::saveTeamToFile( QString Filename, int TeamNumber)
{
	TeamData data;
	bool flag;
	if (TeamNumber == 0) {
		flag = data.writeTeamData(Filename, TeamA);
	} else {
		flag = data.writeTeamData(Filename, TeamB);
	}
	if (flag) return (1);
	else      return (0);
}
//-----------------------------------------------------------------
void GABot::randomTeam(int TeamNumber)
{
   if (TeamNumber == 0){
      if (TeamA) delete TeamA;
      TeamA = new Team(this);
      TeamA->randomTeam(5);
      connect( TeamA, SIGNAL(botMove(Coordinate,Coordinate)),
         this,  SLOT(slotBotMoveA(Coordinate,Coordinate)));
      connect( TeamA, SIGNAL(botDirection(Coordinate,Direction)),
         this,  SLOT(slotBotDirectionA(Coordinate,Direction)));
      
   }else if (TeamNumber == 1){
      if (TeamB) delete TeamB;
      TeamB = new Team(this);
      TeamB->randomTeam(5);
      connect( TeamB, SIGNAL(botMove(Coordinate,Coordinate)),
         this,  SLOT(slotBotMoveB(Coordinate,Coordinate)));
      connect( TeamB, SIGNAL(botDirection(Coordinate,Direction)),
         this,  SLOT(slotBotDirectionB(Coordinate,Direction)));
   }


   if (TeamA && TeamB){
      prepareGame();
      emit(gameReady(TRUE));
   }
}
//-----------------------------------------------------------------
void GABot::slotTurn(void)
{
	// Execute a tick generated turn here
	GAGame->turn();
}
//-----------------------------------------------------------------
void GABot::slotTickInterval(int A)
{
	if (Tick->isActive()) {
		TickInterval = A;
		Tick->changeInterval(A);
	} else {
		TickInterval = A;
	}
}
//-----------------------------------------------------------------
void GABot::slotStartTimer(void)
{
	Tick->start(TickInterval);
}
//-----------------------------------------------------------------
void GABot::slotStopTimer(void)
{
	Tick->stop();
}
//-----------------------------------------------------------------
void GABot::slotBallMoved(Coordinate Old, Coordinate New) 
{
	emit(moveBall(Old, New));
}
//-----------------------------------------------------------------
void GABot::prepareGame(void) 
{
	GAGame = new Game(this, TeamA, TeamB, 1000, 80, 40);
	TeamA->goals(0);
	TeamB->goals(0);
	GAGame->reset();
	connect(GAGame, SIGNAL(ballMoved(Coordinate,Coordinate)), 
		this, SLOT(slotBallMoved(Coordinate,Coordinate)));
	connect(GAGame, SIGNAL(teamAScores()), this,SLOT(slotTeamAScores()) );
	connect(GAGame, SIGNAL(teamBScores()), this,SLOT(slotTeamBScores()) );
	connect(GAGame, SIGNAL(clearField()), this, SLOT(slotClearField()) );
	connect(GAGame, SIGNAL(gameOver()), this, SLOT(slotGameOver()) );
}
//-----------------------------------------------------------------
void GABot::slotBotMoveA(Coordinate P1, Coordinate P2)
{
	emit(moveTeamA(P1,P2));
}
//-----------------------------------------------------------------
void GABot::slotBotMoveB(Coordinate P1, Coordinate P2)
{
	emit(moveTeamB(P1,P2));
}
//-----------------------------------------------------------------
void GABot::slotBotDirectionA(Coordinate P, Direction B)
{
	emit(turnTeamA(P,B));
}
//-----------------------------------------------------------------
void GABot::slotBotDirectionB(Coordinate P, Direction B)
{
	emit(turnTeamB(P,B));
}
//-----------------------------------------------------------------
void GABot::slotTeamAScores(void)
{
	emit(teamAScores());
}
//-----------------------------------------------------------------
void GABot::slotTeamBScores(void)
{
	emit(teamBScores());
}
//-----------------------------------------------------------------
void GABot::slotClearField(void)
{
	emit(clearField());
}
//-----------------------------------------------------------------
void GABot::slotGameOver(void)
{
	Tick->stop();
	emit(gameOver());
	GenAlg.evolve(TeamA);
	GenAlg.evolve(TeamB);
	if (TeamA->goals() > TeamB->goals()) {
		TeamA->wins(TeamA->wins() + 1);
		TeamB->losses(TeamB->losses() + 1);
	} else if (TeamA->goals() < TeamB->goals()) {
		TeamA->losses(TeamA->losses() + 1);
		TeamB->wins(TeamB->wins() + 1);
	} else {
		TeamA->ties(TeamA->ties() + 1);
		TeamB->ties(TeamB->ties() + 1);
	}
	delete GAGame;
	prepareGame();
	Tick->start(TickInterval);
}
//-----------------------------------------------------------------
