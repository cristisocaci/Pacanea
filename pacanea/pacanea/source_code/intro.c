#include "pacanea.h"

sfText *init_titlu(sfFont *f, unsigned int size, sfColor c, const char *t, sfRenderWindow *w)
{
	sfText *titlu;
	sfVector2f p;

	VERIFICA((titlu = sfText_create()))
	p.x = sfRenderWindow_getSize(w).x / 2 - 100;
	p.y = 30;
	sfText_setFont(titlu, f);
	sfText_setCharacterSize(titlu, size);
	sfText_setString(titlu, t);
	sfText_setFillColor(titlu, c);
	sfText_setPosition(titlu, p);
	return (titlu);
}

words init_words(void)
{
	words t;

	t.text = (char **)malloc(sizeof(char *) * 4);
	t.n = 4;
	t.text[0] = (char *)malloc(sizeof(char) * 65);
	t.text[0] = strcpy(t.text[0], "We are NOT recomanding using this app for a long period of time.");
	t.text[1] = (char *)malloc(sizeof(char) * 72);
	t.text[1] = strcpy(t.text[1], "It can generate addictions and your parents will not be proud of you...");
	t.text[2] = (char *)malloc(sizeof(char) * 13);
	t.text[2] = strcpy(t.text[2], "Chose smart!");
	t.text[3] = (char *)malloc(sizeof(char) * 24);
	t.text[3] = strcpy(t.text[3], "Just kidding, ENJOY! :)");
	return (t);
}

sfText **init_text(sfFont *f, sfColor c, words t, unsigned int size, sfRenderWindow *w)
{
	sfText **text;
	int i;
	sfVector2f p;

	VERIFICA((text = (sfText **)malloc(sizeof(sfText *) * t.n)))
	p.x = 70;
	p.y = 300;
	for (i = 0; i < t.n; i++)
	{
		VERIFICA((text[i] = sfText_create()))
		sfText_setFont(text[i], f);
		sfText_setString(text[i], t.text[i]);
		sfText_setCharacterSize(text[i], size);
		sfText_setColor(text[i], c);
		if (i == 3)
		{
			p.x = sfWindow_getSize(w).x / 2 - 80;
			p.y = 5 * sfWindow_getSize(w).y / 6;
		}
		sfText_setPosition(text[i], p);
		p.y += 50;
	}
	return (text);
}

void draw_intro(sfRenderWindow *w, sfText *t, sfText **p, int n)
{
	int i;

	sfRenderWindow_drawText(w, t, NULL);
	for (i = 0; i < n; i++)
		sfRenderWindow_drawText(w, p[i], NULL);
}

void intro(sfRenderWindow *w)
{
	sfFont *font;
	sfText *titlu;
	sfColor culoare;
	sfText **propozitii;
	words text;
	int i;

	if (!(font = sfFont_createFromFile("font\\Consolas.ttf")))
	{
		printf("error in file intro.c: loading font fails!\n");
		return;
	}
	culoare = sfColor_fromRGB(255, 255, 255);
	if (!(titlu = init_titlu(font, 70, culoare, "Warning!", w)))
	{
		printf("error in file intro.c: title initialization fails!\n");
		return;
	}
	text = init_words();
	if (!(propozitii = init_text(font, culoare, text, 30, w)))
	{
		printf("error in intro.c: text initialization fails!\n");
		return;
	}
	draw_intro(w, titlu, propozitii, text.n);
	sfFont_destroy(font);
	sfText_destroy(titlu);
	for (i = 0; i < text.n; i++)
	{
		sfText_destroy(propozitii[i]);
		free(text.text[i]);
	}
	return (1);
}
