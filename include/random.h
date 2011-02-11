/// some useful functions for generating random numbers

#ifndef RANDOM_H
#define RANDOM_H

class Random {
   public:
      /// initialize the seed with the time
      static void initseed();
      /// random integer from start to end
      static int randint(int start, int end);
      /// random double from start to end
      static double randd(double start, double end);
      /// random boolean value
      static bool randbool();
};

#endif
