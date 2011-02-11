/********************************************************************
 * -= C++ =-
 *
 * Simple Genetic Algorithm - Perform GA on a given team
 *
 ********************************************************************/

#ifndef SIMPLEGA_H
#define SIMPLEGA_H

#include "team.h"

/// Main class for Simple Genetic Algorithm used in the program
class SimpleGA {
   public:
      /// Constructor
      SimpleGA();
      /// Constructor
      SimpleGA(double);
      /// Destructor
      ~SimpleGA();
      /// Member function for returning mutation rate
      double mutationRate();
      /// Member function for setting mutation rate
      double mutationRate(double rate);
      /// Crossover two bots and produce two new bots
      void crossover(Bot*, Bot*, Bot*, Bot*);
      /// Evolve a team
      void evolve(Team*);
      
   private:
      /// Mutation Rate
      double MutationRate;
};

/// Use for sorting bots in order of fitness
struct floatbot {
   /// Value of fitness
   float fit;
   /// Bot number
   unsigned int bot;
};

#endif
