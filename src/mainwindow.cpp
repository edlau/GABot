// QT Includes
#include <qapp.h>
#include <qaccel.h>
#include <qdir.h>
#include <qcombobox.h>
#include <qtimer.h>
#include <qmainwindow.h>
#include <qaction.h>
#include <qmenubar.h>
#include <qpopupmenu.h>
#include <qtoolbar.h>
#include <qtoolbutton.h>
#include <qstatusbar.h>
#include <qwhatsthis.h>
#include <qstring.h>
#include <qpixmap.h>
#include <qmsgbox.h>
#include <qfiledialog.h>
#include <qprinter.h>
#include <qpainter.h>
#include <qslider.h>

// Application specific includes
#include "mainwindow.h"
#include "botview.h"
#include "gabot.h"
#include "go.xpm"
#include "stop.xpm"
#include "lab.xpm"

//-----------------------------------------------------------------------------------

MainWindow::MainWindow()
{
	setCaption(tr("GA Bots " VERSION));

	initActions();
	initMenuBar();
	initToolBar();
	initStatusBar();

	initGABotDoc();
	initView();

	ViewToolBar->setOn(true);
	ViewStatusBar->setOn(true);
	//ViewGame->setOn(true);

	connect(GABotDoc, SIGNAL(gameReady(bool)), this, SLOT(slotGameReady(bool)));
	connect(GABotDoc, SIGNAL(teamAScores()), View, SLOT(slotScoreA()));
	connect(GABotDoc, SIGNAL(teamBScores()), View, SLOT(slotScoreB()));
	connect(GABotDoc, SIGNAL(clearScores()), View, SLOT(slotClearScores()));

	connect(GABotDoc, SIGNAL(moveTeamA(Coordinate, Coordinate)), View,
		SLOT(slotMoveTeamA(Coordinate, Coordinate)));
	connect(GABotDoc, SIGNAL(moveTeamB(Coordinate, Coordinate)), View,
		SLOT(slotMoveTeamB(Coordinate, Coordinate)));
	connect(GABotDoc, SIGNAL(turnTeamA(Coordinate, Direction)), View,
		SLOT(slotTurnTeamA(Coordinate, Direction)));
	connect(GABotDoc, SIGNAL(turnTeamB(Coordinate, Direction)), View,
		SLOT(slotTurnTeamB(Coordinate, Direction)));

	connect(GABotDoc, SIGNAL(moveBall(Coordinate,Coordinate)), View,
		SLOT(slotMoveBall(Coordinate,Coordinate)));

	connect(GoGame, SIGNAL(activated()), this, SLOT(slotGoGame()));
	connect(GoGame, SIGNAL(activated()), GABotDoc, SLOT(slotStartTimer()));
	connect(StopGame, SIGNAL(activated()), GABotDoc, SLOT(slotStopTimer()));
	connect(StopGame, SIGNAL(activated()), this, SLOT(slotStopGame()));

	connect(View, SIGNAL(valueChanged(int)), this, SLOT(slotTickInterval(int)));
	connect(GABotDoc, SIGNAL(clearField()), View, SLOT(slotClearField()));

	connect(ResetScreen, SIGNAL(activated()), View, SLOT(slotClearField()));
//not sure if we should clear the field whenever regenerating the team
//	connect(TeamAGenerate,SIGNAL(activated()), View, SLOT(slotClearField()));
//	connect(TeamBGenerate,SIGNAL(activated()), View, SLOT(slotClearField()));

	connect(GABotDoc, SIGNAL(gameOver()), View, SLOT(slotClearField()));
	connect(GABotDoc, SIGNAL(gameOver()), View, SLOT(slotClearScores()));
	connect(GABotDoc, SIGNAL(gameOver()), this, SLOT(slotGameOver()));
	
}

//-----------------------------------------------------------------------------------

MainWindow::~MainWindow()
{

}

//-----------------------------------------------------------------------------------

void MainWindow::initActions(){

	TeamAFileOpen = new QAction(tr("Load Team A"), tr("Load Team &A..."), 0, this);
	TeamAFileOpen->setStatusTip(tr("Load a rule set for team A"));
	connect(TeamAFileOpen, SIGNAL(activated()), this, SLOT(slotLoadTeamA()));

	TeamBFileOpen = new QAction(tr("Load Team B"), tr("Load Team &B..."), 0, this);
	TeamBFileOpen->setStatusTip(tr("Load a rule set for team B"));
	connect(TeamBFileOpen, SIGNAL(activated()), this, SLOT(slotLoadTeamB()));

	TeamAFileSave = new QAction(tr("Save Team A"), tr("Save Team A..."), 0, this);
	TeamAFileSave->setStatusTip(tr("Save team A data"));
	connect(TeamAFileSave, SIGNAL(activated()), this, SLOT(slotSaveTeamA()));

	TeamBFileSave = new QAction(tr("Save Team B"), tr("Save Team B..."), 0, this);
	TeamBFileSave->setStatusTip(tr("Save team B data"));
	connect(TeamBFileSave, SIGNAL(activated()), this, SLOT(slotSaveTeamB()));

	TeamAGenerate = new QAction(tr("Generate Team A"), tr("Generate Team A"), 0, this);
	TeamAGenerate->setStatusTip(tr("Generate Team A"));
	connect(TeamAGenerate, SIGNAL(activated()), this, SLOT(slotGenerateTeamA()));

	TeamBGenerate = new QAction(tr("Generate Team B"), tr("Generate Team B"), 0, this);
	TeamBGenerate->setStatusTip(tr("Generate Team B"));
	connect(TeamBGenerate, SIGNAL(activated()), this, SLOT(slotGenerateTeamB()));
	
	FileQuit = new QAction(tr("Exit"), tr("E&xit"), 0, this);
	FileQuit->setStatusTip(tr("Quits the application"));
	FileQuit->setWhatsThis(tr("Exit\n\nQuits the application"));
	connect(FileQuit, SIGNAL(activated()), this, SLOT(slotFileQuit()));

	ViewToolBar = new QAction(tr("Toolbar"), tr("Tool&bar"), 0, this, 0, true);
	ViewToolBar->setStatusTip(tr("Enables/disables the toolbar"));
	ViewToolBar->setWhatsThis(tr("Toolbar\n\nEnables/disables the toolbar"));
	connect(ViewToolBar, SIGNAL(toggled(bool)), this, SLOT(slotViewToolBar(bool)));

	ViewStatusBar = new QAction(tr("Statusbar"), tr("&Statusbar"), 0, this, 0, true);
	ViewStatusBar->setStatusTip(tr("Enables/disables the statusbar"));
	ViewStatusBar->setWhatsThis(tr("Statusbar\n\nEnables/disables the statusbar"));
	connect(ViewStatusBar, SIGNAL(toggled(bool)), this, SLOT(slotViewStatusBar(bool)));

	/*
	ViewGame = new QAction(tr("Game Display"), tr("&Game Display"), 0, this, 0, true);
	ViewGame->setStatusTip(tr("Enables/disables the game play on screen"));
	ViewGame->setWhatsThis(tr("Game Display\n\nEnables/disables the game play on screen"));
	connect(ViewGame, SIGNAL(toggled(bool)), this, SLOT(slotViewGame(bool)));
	*/

	HelpAbout = new QAction(tr("About"), tr("&About..."), 0, this);
	HelpAbout->setStatusTip(tr("About the application"));
	HelpAbout->setWhatsThis(tr("About\n\nAbout the application"));
	connect(HelpAbout, SIGNAL(activated()), this, SLOT(slotHelpAbout()));

	ResetScreen = new QAction(tr("Reset Screen"), tr("Reset Screen"), 0, this);
	ResetScreen->setStatusTip(tr("Reset Screen"));
	ResetScreen->setWhatsThis(tr("Reset Screen\n\nReset Arena Display"));
	//connect(ResetScreen, SIGNAL(activated()), View, SLOT(slotClearField())); 

}

//-----------------------------------------------------------------------------------

void MainWindow::initMenuBar()
{

	//----
	FileMenu=new QPopupMenu();
	TeamAFileOpen->addTo(FileMenu);
	TeamBFileOpen->addTo(FileMenu);
	FileMenu->insertSeparator();
	TeamAFileSave->addTo(FileMenu);
	TeamBFileSave->addTo(FileMenu);
	FileMenu->insertSeparator();
	TeamAGenerate->addTo(FileMenu);
	TeamBGenerate->addTo(FileMenu);
	FileMenu->insertSeparator();
	ResetScreen->addTo(FileMenu);
	FileMenu->insertSeparator();
	FileQuit->addTo(FileMenu);

	//---- menuBar entry viewMenu
	ViewMenu=new QPopupMenu();
	ViewMenu->setCheckable(true);
	ViewToolBar->addTo(ViewMenu);
	ViewStatusBar->addTo(ViewMenu);
	//ViewGame->addTo(ViewMenu);

	//---- menuBar entry helpMenu
	HelpMenu=new QPopupMenu();
	HelpAbout->addTo(HelpMenu);

	//----
	menuBar()->insertItem(tr("&File"), FileMenu);
	menuBar()->insertItem(tr("&View"), ViewMenu);
	menuBar()->insertSeparator();
	menuBar()->insertItem(tr("&Help"), HelpMenu);

	TeamAFileSave->setEnabled(FALSE);
	TeamBFileSave->setEnabled(FALSE);

}

//-----------------------------------------------------------------------------------

void MainWindow::initToolBar()
{
	Toolbar = new QToolBar(this);
	Toolbar->setHorizontalStretchable(TRUE);
	Toolbar->setVerticalStretchable(TRUE);
	StopGame = new QAction(0, QPixmap(Stop_XPM), 0, 0, this);
	GoGame = new QAction(0, QPixmap(Go_XPM), 0, 0, this);

	StopGame->addTo(Toolbar);
	StopGame->setEnabled(FALSE);

	GoGame->addTo(Toolbar);
	GoGame->setEnabled(FALSE);

	QWidget *MT = new QWidget(Toolbar);
	Toolbar->setStretchableWidget(MT);

}

//-----------------------------------------------------------------------------------

void MainWindow::initStatusBar()
{
	statusBar()->message(tr("Ready."), 2000);
}

//-----------------------------------------------------------------------------------

void MainWindow::initGABotDoc()
{
	// Create a new doc 
	GABotDoc = new GABot(this);
}

//-----------------------------------------------------------------------------------

void MainWindow::initView()
{
	// set the main widget here
	View = new BotView(this);
	setCentralWidget(View);
}

//-----------------------------------------------------------------------------------

bool MainWindow::queryExit()
{
	int exit=QMessageBox::information(this, tr("Quit..."),
		tr("Do your really want to quit?"),
		QMessageBox::Ok, QMessageBox::Cancel);

	if (exit==1) {
		// do something
	} else {
		// do something else
	};
	return (exit==1);
}

//-----------------------------------------------------------------------------------

void MainWindow::teamFileOpen(int TeamNumber)
{
	statusBar()->message(tr("Opening file..."));
	QFileDialog *TempFileDialog;
	TempFileDialog = new QFileDialog;
	TempFileDialog->setMode(QFileDialog::Directory);
	QString FileName = TempFileDialog->getOpenFileName(0,0,this,0,0);
	if (!FileName.isEmpty()) {
		if (GABotDoc->loadTeamFromFile(FileName,TeamNumber)) {
			if (TeamNumber) {
				statusBar()->message(tr("Loaded file "+FileName+" into Team B."), 5000);
				TeamBFileSave->setEnabled(TRUE);
			} else {
				statusBar()->message(tr("Loaded file "+FileName+" into Team A."), 5000);
				TeamAFileSave->setEnabled(TRUE);
			}
		} else {
			QMessageBox::warning(this,tr("Invalid file format"),
				tr("\nThe selected file is not a GA Bot XML file, you idiot."));
			statusBar()->message(tr("Opening aborted"), 1000);
		}
	} else {
		statusBar()->message(tr("Opening aborted"), 1000);
	}
	delete TempFileDialog;
}

//-----------------------------------------------------------------------------------

void MainWindow::teamFileSave(int TeamNumber)
{
	statusBar()->message(tr("Saving team data file..."));
	QFileDialog *TempFileDialog = new QFileDialog;
	TempFileDialog->setMode(QFileDialog::Directory);
	QString FileName = TempFileDialog->getSaveFileName(0,0,this,0,0);
	if(!FileName.isEmpty()){
		if(GABotDoc->saveTeamToFile(FileName,TeamNumber)){
			if (TeamNumber) {
				statusBar()->message(tr("Saving team B to "+FileName+"."), 5000);
			}else {
				statusBar()->message(tr("Saving team A to "+FileName+"."), 5000);
			}
		}else{
			QMessageBox::warning(this,tr("File saving error"),tr("You probably don't have enough space on disk or something."));
			statusBar()->message(tr("Saving aborted"), 1000);
		}
	}else{
		statusBar()->message(tr("Saving aborted"), 1000);
	}
	delete TempFileDialog;

}

//-----------------------------------------------------------------------------------

void MainWindow::teamGenerateRandom(int TeamNumber)
{
	GABotDoc->randomTeam(TeamNumber);
}

//-----------------------------------------------------------------------------------

void MainWindow::slotFileClose()
{
	statusBar()->message(tr("Closing file..."));
	// Close the file, I suppose -- may not need this for this app.  Dunno. 
	// Presumably it would be a GABotDoc->function() thing
	statusBar()->message(tr("Ready."), 2000);
}

//-----------------------------------------------------------------------------------

void MainWindow::slotFileQuit()
{
	statusBar()->message(tr("Exiting application..."));

	// exits the Application
/*  Comment this out until we have a doc.  In fact, I'm not even sure
 *  if this applies to our project or not.  Probably not. I'm hungry.
	if(Doc->isModified()) {
		if(queryExit()) {
			// Prompt luser to save
			qApp->quit();
		} 
  	} else {
		qApp->quit();
	}
*/
	qApp->quit();
}

//-----------------------------------------------------------------------------------

void MainWindow::slotViewToolBar(bool toggle)
{
	statusBar()->message(tr("Toggle toolbar..."));

	// Toggle your Toolbar (get your head out of the gutter)

	if (toggle) {
		Toolbar->show();
	} else {
		Toolbar->hide();
	}

	statusBar()->message(tr("Ready."), 2000);
}

//-----------------------------------------------------------------------------------

void MainWindow::slotViewStatusBar(bool toggle)
{
	statusBar()->message(tr("Toggle statusbar..."));

	if (toggle) {
		statusBar()->show();
	} else {
		statusBar()->hide();
	}

	statusBar()->message(tr("Ready."), 2000);
}

//-----------------------------------------------------------------------------------
void MainWindow::slotViewGame(bool toggle)
{
	//currently doing nothing
}
//-----------------------------------------------------------------------------------

void MainWindow::slotHelpAbout()
{
	QMessageBox About(this,0);
	About.setIconPixmap(QPixmap(Lab_XPM));
	About.setCaption(tr("About..."));
	About.setText(tr("GA Bots\nVersion " VERSION "\n                \n(c) 2002 by Edmond Lau, Chris Odorjan and Richard Voino") );
	About.exec();
}

//-----------------------------------------------------------------------------------

void MainWindow::loading(QString FileName)
{
	QString Message;
	if (FileName) {
		QString Message=tr("Loading ")+FileName+tr("...");
		statusBar()->message(Message);
	} else {
		Message=tr("Done.");
		statusBar()->message(Message, 2000);
	}
}

//-----------------------------------------------------------------------------------

void MainWindow::slotLoadTeamA (void)
{
	teamFileOpen(0);
}

//-----------------------------------------------------------------------------------

void MainWindow::slotLoadTeamB (void)
{
	teamFileOpen(1);
}

//-----------------------------------------------------------------------------------

void MainWindow::slotSaveTeamA (void)
{
   teamFileSave(0);
}

//-----------------------------------------------------------------------------------

void MainWindow::slotSaveTeamB (void)
{
   teamFileSave(1);
}

//-----------------------------------------------------------------------------------

void MainWindow::slotGenerateTeamA(void)
{
	teamGenerateRandom(0);
	TeamAFileSave->setEnabled(TRUE);
}

//-----------------------------------------------------------------------------------

void MainWindow::slotGenerateTeamB(void)
{
	teamGenerateRandom(1);
	TeamBFileSave->setEnabled(TRUE);
}

//-----------------------------------------------------------------------------------

void MainWindow::slotGoGame(void)
{
	GoGame->setEnabled(FALSE);
	StopGame->setEnabled(TRUE);
}

//-----------------------------------------------------------------------------------

void MainWindow::slotStopGame(void)
{
	StopGame->setEnabled(FALSE);
	GoGame->setEnabled(TRUE);
}

//-----------------------------------------------------------------------------------

void MainWindow::slotGameReady(bool GameReady)
{
	GoGame->setEnabled(GameReady);
}

//-----------------------------------------------------------------------------------

void MainWindow::slotTickInterval(int Inter)
{
	GABotDoc->slotTickInterval(1025 - Inter);
}

//-----------------------------------------------------------------------------------

void MainWindow::slotGameOver(void)
{
	statusBar()->message(tr("Game ended. Evolving teams, and preparing new game."), 5000);
}

//-----------------------------------------------------------------------------------
