#include "pacanea.h"

void intro(sfRenderWindow *w)
{
	sfText *titlu;
	sfText *propozitii[3];
	sfFont *font;
	sfEvent event;
	sfVector2f p;
	int i;

	font = sfFont_createFromFile("font\\Consolas.ttf");
	titlu = sfText_create();
	sfText_setFont(titlu, font);
	sfText_setString(titlu, "WARNING!");
	sfText_setCharacterSize(titlu, 100);
	sfText_setFillColor(titlu, sfColor_fromRGB(255, 255, 255));

	propozitii[0] = sfText_create();
	sfText_setFont(propozitii[0], font);
	sfText_setString(propozitii[0], "We are NOT recomanding using this app for a long period of time.");
	sfText_setCharacterSize(propozitii[0], 40);
	sfText_setColor(propozitii[0], sfColor_fromRGB(255, 255, 255));

	propozitii[1] = sfText_create();
	sfText_setFont(propozitii[1], font);
	sfText_setString(propozitii[1], "It can generate addictions and your parents will not be proud of you...");
	sfText_setCharacterSize(propozitii[1], 40);
	sfText_setColor(propozitii[1], sfColor_fromRGB(255, 255, 255));

	propozitii[2] = sfText_create();
	sfText_setFont(propozitii[2], font);
	sfText_setString(propozitii[2], "Chose smart!");
	sfText_setCharacterSize(propozitii[2], 40);
	sfText_setColor(propozitii[2], sfColor_fromRGB(255, 255, 255));

	while (sfRenderWindow_isOpen(w))
	{
		while (sfRenderWindow_pollEvent(w, &event))
			if (event.type == sfEvtKeyPressed)
				if (event.key.code == sfKeySpace)
					sfRenderWindow_clear(w, sfColor_fromRGB(0,0,0));
		p.x = sfWindow_getSize(w).x / 2 - 100;
		p.y = 20;
		sfText_setPosition(titlu, p);
		sfRenderWindow_drawText(w, titlu, NULL);
		p.x = 20;
		for (p.y = 20, i = 0; i < 3; i++, p.y += 10)
		{
			sfText_setPosition(propozitii[i], p);
			sfRenderWindow_drawText(w, propozitii[0], NULL);
		}
		sfRenderWindow_display(w);

	}
	sfFont_destroy(font);
	sfText_destroy(text);
}
