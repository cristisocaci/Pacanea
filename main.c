#include "pacanea.h"

int main()
{
	sfRenderWindow *w;
	sfEvent e;
	sfVideoMode mod = {1400, 900, 32};
	menu m;

	w = sfRenderWindow_create(mod, "Pacaneaua", sfResize | sfClose, NULL);
	intro(w);
	sfRenderWindow_display(w);
	while (sfRenderWindow_isOpen(w))
	{
		while (sfRenderWindow_pollEvent(w, &e))
		{
			if (e.type == sfEvtClosed)
				sfRenderWindow_close(w);
			if (e.type == sfEvtKeyPressed)
			{
				if (e.key.code == sfKeySpace)
				{
					sfRenderWindow_clear(w, sfBlack);
 					m = meniu(w);
 					sfRenderWindow_display(w);
				}
				if (e.key.code == sfKeyUp)
				{
					printf("move up\n");
					m.selected = moveUp(m, w);
					printf("selected: %d\n", m.selected);
					//sfRenderWindow_clear(w, sfBlack);
					sfRenderWindow_display(w);
				}
				if(e.key.code == sfKeyDown)
				{
					printf("move down\n");
					m.selected = moveDown(m, w);
					printf("selected: %d\n", m.selected);
					//sfRenderWindow_clear(w, sfBlack);
					sfRenderWindow_display(w);
				}
				if (e.key.code == sfKeyReturn)
				{
					switch (m.selected)
					{
					case 1:
						printf("unu!");
						pacaneaua();
						break;
					case 2:
						printf("doi!");
						break;
					case 3:
						printf("trei!");
						sfRenderWindow_close(w);
						break;
					}
				}
			}
			printf("%d\n", e.key.code);
		}
	}
	sfRenderWindow_destroy(w);
	return (0);
}
