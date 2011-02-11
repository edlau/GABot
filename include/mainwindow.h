#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define VERSION "0.99"

// include files for QT
#include <qmainwindow.h>

// Class prototypes
class QString;
class QPopupMenu;
class QAction;
class BotView;
class GABot;
class QTimer;

/// Main widget for the GABots app
class MainWindow : public QMainWindow
{

Q_OBJECT
  
public:
	/// Constructor
	MainWindow();
	/// Destructor
	~MainWindow();

protected:

	/// Create the QT Actions
	void initActions();
	/// Create the menu bar
	void initMenuBar();
	/// Create the tool bar
	void initToolBar();
	/// Create the status bar
	void initStatusBar();
	/// Create the GA Bot object
	void initGABotDoc();
	/// Create the GA Bot view object
	void initView();
	/// Query the user if they wish to quit without saving
	bool queryExit();
	/// Open a team ruleset file
	void teamFileOpen(int);
	/// Save a team ruleset to file
	void teamFileSave(int);
	/// Generate new team randomly
	void teamGenerateRandom(int);

protected slots:

	/// This should be changed
	void slotFileClose();
	/// Runs on quiting the application
	void slotFileQuit();
	/// Toggles the Toolbar
	void slotViewToolBar(bool toggle);
	/// Toggles the Statusbar
	void slotViewStatusBar(bool toggle);
	/// Toggles the Game Display
	void slotViewGame(bool toggle);
	/// Launches the About box
	void slotHelpAbout();
	/// Runs on loading a file
	void loading(QString);
	/// Load a file for team A
	void slotLoadTeamA();
	/// Load a file for team B
	void slotLoadTeamB();
	/// Save a file for team A
	void slotSaveTeamA();
	/// Save a file for team B
	void slotSaveTeamB();
	/// Generate a new team for team A
	void slotGenerateTeamA();
	/// Generate a new team for team B
	void slotGenerateTeamB();
	/// Start QTimer, begin a game
	void slotGoGame(void);
	/// Stops an active game
	void slotStopGame(void);
	/// Toggles game ready status
	void slotGameReady(bool);
	/// Changed the game speed
	void slotTickInterval(int);
	/// Handle game over 
	void slotGameOver(void);

private:

	/// Pointer to the View
	BotView	*View;
	/// Pointer to the GABot document
	GABot	*GABotDoc;
	/// Pointer to the file menu pop up
	QPopupMenu *FileMenu;
	/// Pointer to the view menu pop up
	QPopupMenu *ViewMenu;
	/// Pointer to the help menu pop up
	QPopupMenu *HelpMenu;
	/// Pointer to the tool bar pop up
	QToolBar *Toolbar;
	/// Action for opening team A file
	QAction *TeamAFileOpen;
	/// Action for opening team B file
	QAction *TeamBFileOpen;
	/// Action for saving team A file
	QAction *TeamAFileSave;
	/// Action for saving team B file
	QAction *TeamBFileSave;
	/// Action for quitting the application
	QAction *FileQuit;
	/// Action for toggling the toolbar
	QAction *ViewToolBar;
	/// Action for toggoling the status bar
	QAction *ViewStatusBar;
	/// Action for toggling the view game
	QAction *ViewGame;
	/// Action for launching the About box
	QAction *HelpAbout;
	/// Action for starting a game
	QAction *GoGame;
	/// Action for stopping a game
	QAction *StopGame;
	/// Action for generate a random team A
	QAction *TeamAGenerate;
	/// Action for generate a random team B
	QAction *TeamBGenerate;
	/// Action for reset display
	QAction *ResetScreen;

};
#endif 
