#ifndef PACANEA_H
#define PACANEA_H

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "pacanea2.h"

#define VERIFICA(x) if (!x) return (NULL);

typedef struct
{
	char **text;
	int n;
} words;

typedef struct
{
	int selected;
	sfText *t[4];
} menu;

void	intro(sfRenderWindow *w);
menu	meniu(sfRenderWindow *w);
int		moveUp(menu m, sfRenderWindow *w);
int		moveDown(menu m, sfRenderWindow *w);


#endif // PACANEA_H
