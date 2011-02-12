/********************************************************************
 * -= C++ =-
 * some useful functions for generating random numbers
 ********************************************************************/

#include "random.h"
#include <cstdlib>
#include <ctime>

void Random::initseed() {
   srand(time(NULL));
}

int Random::randint(int start, int end) {
   int r;
   
   r = start + (int) ((end - start + 1.0)*rand()/(RAND_MAX+1.0));
   return r;
}

double Random::randd(double start, double end) {
   double r;
   
   r = start + (end - start + 1.0)*rand()/(RAND_MAX+1.0);
   return r;
}

bool Random::randbool() {
   double rd;
   bool r;
   
   rd = randd(0,1);
   r = (rd < 0.5 ? false : true);
   return r;
}
