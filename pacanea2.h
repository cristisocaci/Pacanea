#ifndef PACANEA2_H
#define PACANEA2_H

#include <time.h>

typedef struct {

    sfTexture *texture;
    sfSprite *sprite;

}entity;

enum {cherry, seven, Varga, Cristi, Andrei, wild};
enum {pica, trefla, inima, romb};
enum {credits, bet};

//main functions
void pacaneaua();
void Delay(float);
sfVector2f vectorSum(sfVector2f, sfVector2f);
entity createSprite(char *);
void randSprite(int, int);
void winningDisplay(int);

//dublaj functions
int Dublaj(int);
int doYouWantToDouble(int);

//money functions
int setBet(int);
int winning(int, int, int, int);


#endif
