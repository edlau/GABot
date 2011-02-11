GABot a.k.a. Generic Algorithm Bot
==================================

GABot was originally a school project from 2002 by Edmond Lau, Chris 
Odorjan and Richard Voino.  The goal was to create a game playing prototype 
based on Genetic Algorithms for our Artificial Intelligence class at 
Wilfrid Laurier University.

Since the completion of the school project, the gang had many discussions
(over beer and wine) on how to revive the project, enhance the code and 
publish the project somewhere on SourceForge.  But after 8 years and much
alcohol consumed, we have decided to push the original code.  Hopefully,
someone out there will find this code useful.

Disclaimer
----------

If you find any comment funny, drop us a line!  If you find anything
offensive, probably because we spent so much time working on this at night.

Code Base
---------

The code is **based on C/C++ and older Qt (probably 2.x or 3.x**, whichever one
from 2002).

Naming Conventions
------------------

All filenames are lowercase, regardless of their contents. The directives at
the start of each header file check for and define the name of the file, in
uppercase, with the period replaced by an underscore.

Classes have their first letter capitalized, and if there are multiple words
in their name, then they are concatenated (without a separator), and the
first letter of each word is capitalized.

Variables in classes are named in the same way as classes.

Methods have their first letter in lowercase, but if they are made of
multiple words, then the first letter of each successive word is
capitalized. The words are also concatenated without a separator. Methods
that read or alter a particular variable will generally have the same name
as the variable, but the first letter will be in lowercase instead of
capitalized. Overloading should be used to avoid using
getVariable/setVariable pairs of methods.

Makefile
--------

ex:
	tmake gabot.pro > Makefile

Qt Linking
----------

If you experience linker errors when linking to qt, and you
compiled qt with thread support (or can't remember if you did),
you may have to create a symbolic link from `libqt-mt.so` to `libqt.so`.

ex: 
	ln -s $QTDIR/lib/libqt-mt.so $QTDIR/lib/libqt.so
	ldconfig

GARule
------

The following is one of my proposal of how GARule using integers.

From GALib documentation on GAs, rules are not necessarily in bits or boolean,
if we have integer or real fields within each rule, we just have to make sure
when we apply "crossover" operations, we do not crossover real and integer fields.
We only do int-to-int and/or real-to-real, but not real-to-int.

By using integers and real numbers, then we can describe the distance of friend(s)
and opponent(s) in our rules.  I listed some thoughts about the rule below.


1. Each GARule consists of:
   TeamBall, Opponent, Friend, Wall, Net, Ball, Actions

   TeamBall - the flag of which team has the ball ==> offense or defense
   Opponent - information about where Opponent is, we can figure out what if
              there are multiple opponent within range.
   Friend   - information about where teammate is
   Wall     - information about where the wall is
   Net      - information about where the net is (guessing more likely)
   Ball     - information about where the ball is
   Actions  - what action to take place.


2. GARule Class Example:

   // to describe objects other than itself
   struct obstacle{
      uint distance;
      direction dir;
      // possible with known mass
   };


   class GARule{
      public:
         GARule();
	 ~GARule();
      //private:
         bool TeamBall;
         obstacle Opponent;
	 obstacle Friend;
	 obstacle Wall;
	 obstacle Net;
	 obstacle Ball;
	 bool Actions[6];
	 
   };

   Note: the direction object may not be well suitable here since
   it only has 8 different values.  We may (or should) change the direction
   to integers with range from 0 to 359.  In all operations, we can use only
   every 45, however to describe obstacle, we need to use all degrees.

   Another thing is, I take out the "private:" since our actual algorithm
   needs to copy and modify these rules during crossover and mutation.


3. Rule Example:
   When {Opponent, Friend, Wall}.distance = 0, it means the object does
   not exist within range.  When Ball.distance = 0, it means the bot has
   it.  (As we agreed before, Ball.distance and Net.distance are not limited
   to SensorRange.)
 
   Diagram:
                        =net=

        =fri=

	          =opp=
        
             =me=


   GARule r1;
   r1.TeamBall = true;
   r1.Friend.distance = 20;
   r1.Friend.dir = NW;
   r1.Opponent.distance = 10;
   r1.Opponent.dir = NE;
   r1.Wall.distance = 0;
   r1.Wall.dir = N;
   r1.Net.distance = 50;
   r1.Net.dir = NE;
   r1.Ball.distance = 0;
   r1.Ball.dir = N;
   Actions = {0,1,0,1,0,0}; // {shoot, pass, carry, change dir, intercept, charge}


4. Since we are using integer, mutation operations requires random integer function.
   Also each mutation should have range limits.  (i.e. if Sensor Range of each bot
   is 50, then the Opponent.distance is an element of [1, 50] because the sensor
   cannot find obstacles further than 50.)


Please tell me what you think ASAP.  I need to get this over my head and start
making the evolving, mutation, and crossover functions.
