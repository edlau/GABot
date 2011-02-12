/********************************************************************
 * -= C++ =-
 *
 * Simple Genetic Algorithm - Perform GA on the given team
 *
 ********************************************************************/

// predirectives
#include "simplega.h"
#include "team.h"
#include "bot.h"
#include "garule.h"
#include "random.h"
#include <qarray.h>

SimpleGA::SimpleGA() {
   MutationRate = 0;
}

SimpleGA::SimpleGA(double mRate) {
   MutationRate = mRate;
}

SimpleGA::~SimpleGA() {
}

double SimpleGA::mutationRate() {
   return(MutationRate);
}

double SimpleGA::mutationRate(double rate) {
   MutationRate = rate;
   return(MutationRate);
}

void SimpleGA::crossover(Bot *aIn, Bot *bIn, Bot *aOut, Bot *bOut) {
   unsigned int aRules, bRules, i;
   unsigned int aMass, bMass;
   double aProp, bProp;
   GARule *r;
   
   aRules = Random::randint(1, aIn->ruleSetSize()); aRules--;
   bRules = Random::randint(1, bIn->ruleSetSize()); bRules--;
   
   for (i=0; i<aIn->ruleSetSize(); i++) {
      r = new GARule;
      *r = *(aIn->rule(i));  // I hope this makes a deep copy
      if (i <= aRules) {
         // add to first child bot
         aOut->insertRule(r);
      } else {
         // add to second child bot
         bOut->insertRule(r);
      }
   }
   for (i=0; i<bIn->ruleSetSize(); i++) {
      r = new GARule;
      *r = *(bIn->rule(i));
      if (i <= bRules) {
         aOut->insertRule(r);
      } else {
         bOut->insertRule(r);
      }
   }
   
   // new bot masses are determined by the amount of each ruleset they took
   aProp = (double)aRules / (double)(aIn->ruleSetSize());
   bProp = (double)bRules / (double)(bIn->ruleSetSize());
   aMass = (unsigned int) ( aProp * aIn->mass() + bProp * bIn->mass() + 0.5);
   bMass = (unsigned int) ( (1.0 - aProp) * aIn->mass() + (1.0 - bProp) * bIn->mass() + 0.5);
   if (aMass < 1) aMass = 1;   if (bMass < 1) bMass = 1;
   if (aMass > 10) aMass = 10; if (bMass > 10) bMass = 10;
   aOut->mass(aMass);
   bOut->mass(bMass);

}

void SimpleGA::evolve(Team *T) {
   Team *oldTeam, *newTeam, *delTeam;
   QArray<floatbot> botFitness;
   unsigned int teamSize, breed;
   int i;
   Bot *curbot;
   Bot *newbot1, *newbot2;

   oldTeam = T;
   newTeam = new Team;
   delTeam = new Team;

   teamSize = oldTeam->size();
   botFitness.resize(teamSize);
   for (i=0; i< (int)teamSize; i++) {
      curbot = oldTeam->bot(i);
      botFitness[i].fit = curbot->fitnessFunction();
      botFitness[i].bot = i;
   }
   botFitness.sort();

   // reverse fitness array
   for (i=0; i<(int)(teamSize/2); i++) {
      floatbot temp;
      temp.fit = botFitness[i].fit;
      temp.bot = botFitness[i].bot;
      botFitness.at(i).fit = botFitness.at(teamSize-i-1).fit;
      botFitness.at(i).bot = botFitness.at(teamSize-i-1).bot;
      botFitness.at(teamSize-i-1).fit = temp.fit;
      botFitness.at(teamSize-i-1).bot = temp.bot;
   }
   
   // add the good bots to the new team
   breed = teamSize / 2;                 // number of bots to breed
   if ( (breed/2)*2 != breed ) breed--;  // make sure its even
   for (i=0; i<(int)(teamSize - breed); i++) {
      // number of bots to throw out is the number bred, so keep the number not thrown out
      curbot = oldTeam->bot(botFitness[i].bot);
      newTeam->insertBot(curbot);
   }
   for (i=(teamSize - breed); i<(int)teamSize; i++) {
      // put bots to be deleted on a separate team
      curbot = oldTeam->bot(botFitness[i].bot);
      delTeam->insertBot(curbot);
   }
   while (oldTeam->size() > 0) {
      // remove bots from oldTeam
      curbot = oldTeam->removeBot(0);
   }
   while (delTeam->size() > 0) {
      // actually delete bots
      curbot = delTeam->removeBot(0);
      delete curbot;
   }
   
   // do the crossover of the best bots
   for (i=0; i<(int)breed; i+=2) {
      newbot1 = new Bot(oldTeam);
      newbot2 = new Bot(oldTeam);
      crossover(newTeam->bot(i), newTeam->bot(i+1), newbot1, newbot2);
      newTeam->insertBot(newbot1);
      newTeam->insertBot(newbot2);
   }
   
   // mutate a bot given the mutation rate
   for (i=0; i<(int)teamSize; i++) {
      double rnd = Random::randd(0,1);
      if (rnd < MutationRate) {
         curbot = newTeam->bot(i);
         curbot->mutateBot();
      }
   }
   
   // copy bots back into old team
   while (newTeam->size() > 0) {
      curbot = newTeam->removeBot(0);
      oldTeam->insertBot(curbot);
   }
   oldTeam->generations(oldTeam->generations() + 1);
   delete delTeam;
   delete newTeam;
}
