// Team class: defines a "team" or population of Bots

#include "team.h"
#include "bot.h"
#include "random.h"
#include <qlist.h>

Team::Team(QObject *parent, const char *name)
	: QObject(parent,name) {
   wins(0);
   losses(0);
   ties(0);
   goals(0);
   generations(0);
   Bots.clear();
}

Team::~Team() {
   // bots get destroyed automagically
   Bots.clear();
}

unsigned int Team::size() {
   return(Bots.count());
}

QList<Bot> Team::bots() {
   return Bots;
}

QList<Bot> Team::bots(QList<Bot> bs) {
   Bots = bs;
   return Bots;
}

Bot* Team::removeBot(unsigned int num) {
   Bot *p = Bots.at(num);
   Bots.remove();
   return p;
}

unsigned int Team::insertBot(Bot *b, unsigned int num) {
   connect( b, SIGNAL(botMove(Coordinate,Coordinate)),
            this, SLOT(slotBotMove(Coordinate,Coordinate)));
   connect( b, SIGNAL(botDirection(Coordinate,Direction)),
            this, SLOT(slotBotDirection(Coordinate,Direction)));
   Bots.insert(num, b);
   return Bots.at();
}

unsigned int Team::insertBot(Bot *b) {
   connect( b, SIGNAL(botMove(Coordinate,Coordinate)),
            this, SLOT(slotBotMove(Coordinate,Coordinate)));
   connect( b, SIGNAL(botDirection(Coordinate,Direction)),
            this, SLOT(slotBotDirection(Coordinate,Direction)));
   Bots.append(b);
   return Bots.at();
}

Bot* Team::bot(unsigned int num) {
   return Bots.at(num);
}

unsigned int Team::wins() {
   return(Wins);
}

unsigned int Team::wins(unsigned int w) {
   Wins = w;
   return(Wins);
}

unsigned int Team::losses() {
   return(Losses);
}

unsigned int Team::losses(unsigned int l) {
   Losses = l;
   return(Losses);
}

unsigned int Team::ties() {
   return(Ties);
}

unsigned int Team::ties(unsigned int t) {
   Ties = t;
   return(Ties);
}

unsigned int Team::generations() {
   return Generations;
}

unsigned int Team::generations(unsigned int g) {
   Generations = g;
   return Generations;
}

QString Team::name(){
   return(Name);
}

QString Team::name(QString n){
   Name = n;
   return(Name);
}

void Team::randomTeam(unsigned int size) {
   unsigned int numrules;
   unsigned int mass;
   
   wins(0);
   losses(0);
   ties(0);
   goals(0);
   name("Team Stochastic");
   
   for (unsigned int i=0; i<size; i++) {
      numrules = Random::randint(100,200);       // pick a random number of rules for each bot
      mass = Random::randint(1,10);            // pick a random number for the bot mass
      Bot *NewBot = new Bot(this);
      NewBot->randomBot(numrules, mass);
      insertBot(NewBot);
   }
}

void Team::slotBotMove(Coordinate P1,Coordinate P2)
{
   emit(botMove(P1,P2));
}

void Team::slotBotDirection(Coordinate P,Direction B)
{
   emit((botDirection(P,B)));
}

int Team::goals() {
   return Goals;
}

int Team::goals(int g) {
   Goals = g;
   return Goals;
}
