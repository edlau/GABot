#ifndef THING_H
#define THING_H

/// Thing type - enumerated to store various things we find in the game
typedef enum { Nothing,                // ABSOLUTELY NOTHING!!!
               MyBot,                  // another bot on the same team
               OtherBot,               // a bot on another team
               TheBall,
               Net,                    // the other team's net
               Wall,
             } Thing;

#endif
