#include "meniu.h"

int moveUp(menu m, sfRenderWindow *w)
{
	if (m.selected >= 2)
	{
		sfText_setColor(m.t[m.selected], sfColor_fromRGB(255, 255, 255));
		sfRenderWindow_drawText(w, m.t[m.selected], NULL);
		sfRenderWindow_display(w);
		m.selected--;
		sfText_setColor(m.t[m.selected], sfColor_fromRGB(255, 51, 0));
	/*	sfRenderWindow_drawText(w, m.t[m.selected], NULL);
		sfRenderWindow_display(w);*/
	}
	return (m.selected);
}

int moveDown(menu m, sfRenderWindow *w)
{
	if (m.selected < 3)
	{
		sfText_setColor(m.t[m.selected], sfColor_fromRGB(255, 255, 255));
		sfRenderWindow_drawText(w, m.t[m.selected], NULL);
		sfRenderWindow_display(w);
		m.selected++;
		sfText_setColor(m.t[m.selected], sfColor_fromRGB(255, 51, 0));
		/*sfRenderWindow_drawText(w, m.t[m.selected], NULL);
		sfRenderWindow_display(w);*/
	}
	return (m.selected);
}

menu meniu(sfRenderWindow *w)
{
	sfFont *f;
	sfColor rosu;
	sfColor alb;
	sfVector2f p;
	menu m;

	if (!(f = sfFont_createFromFile("font\\OCRAEXT.TTF")))
	{
		printf("error in meniu.c: loading font fails!");
		return;
	}
	rosu = sfColor_fromRGB(255, 51, 0);
	alb = sfColor_fromRGB(255, 255, 255);
	p.x = sfWindow_getSize(w).x / 3;
	p.y = sfWindow_getSize(w).y / 9;
	m.t[0] = sfText_create();
	sfText_setFont(m.t[0], f);
	sfText_setCharacterSize(m.t[0], 100);
	sfText_setString(m.t[0], "Eigenmeniu!");
	sfText_setColor(m.t[0], alb);
	sfText_setPosition(m.t[0], p);
	sfRenderWindow_drawText(w, m.t[0], NULL);

	p.y = sfWindow_getSize(w).y / 8 * 3;
	m.t[1] = sfText_create();
	sfText_setFont(m.t[1], f);
	sfText_setCharacterSize(m.t[1], 50);
	sfText_setString(m.t[1], "New Game");
	sfText_setColor(m.t[1], rosu);
	sfText_setPosition(m.t[1], p);
	sfRenderWindow_drawText(w, m.t[1], NULL);

	p.y = sfWindow_getSize(w).y / 2;
	m.t[2] = sfText_create();
	sfText_setFont(m.t[2], f);
	sfText_setCharacterSize(m.t[2], 50);
	sfText_setString(m.t[2], "How To Play");
	sfText_setColor(m.t[2], alb);
	sfText_setPosition(m.t[2], p);
	sfRenderWindow_drawText(w, m.t[2], NULL);

	p.y = sfWindow_getSize(w).y / 8 * 5;
	m.t[3] = sfText_create();
	sfText_setFont(m.t[3], f);
	sfText_setCharacterSize(m.t[3], 50);
	sfText_setString(m.t[3], "Exit!");
	sfText_setColor(m.t[3], alb);
	sfText_setPosition(m.t[3], p);
	sfRenderWindow_drawText(w, m.t[3], NULL);

	m.selected = 1;

	sfFont_destroy(f);
	return (m);
}
