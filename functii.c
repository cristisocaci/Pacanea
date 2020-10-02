#include "pacanea.h"


void Delay(float seconds){
    int miliseconds = seconds  * 1000;
    clock_t startTime = clock();
    while(clock() < startTime+miliseconds)
        ;
    }

sfVector2f vectorSum(sfVector2f v1, sfVector2f v2){
    sfVector2f vSum;

    vSum.x = v1.x + v2.x;
    vSum.y = v1.y + v2.y;

    return vSum;
}


entity createSprite(char *photo){
    entity a;

    a.texture = sfTexture_createFromFile(photo, NULL);
    if(!a.texture)
        exit(1);
    a.sprite = sfSprite_create();
    sfSprite_setTexture(a.sprite, a.texture, sfTrue);
    return a;
}

void winningDisplay(int localwin){
    sfRenderWindow* winWindow;
    entity winback;
    sfText* localwintext;
    sfFont* localarial;
    sfVideoMode localmode= {800, 500};
    char localtext[10];

   //creating the window
    winWindow = sfRenderWindow_create(localmode, "WinningWindow", sfClose, NULL);
    if (!winWindow)
        exit(1);

    //creating the background
    winback = createSprite("z-winback.jpg");

    //creating the font
    localarial = sfFont_createFromFile("arial.ttf");
    if(!localarial)
        exit(1);

    //creating the text
    localwintext = sfText_create();
    sfText_setFont(localwintext, localarial);
    itoa(localwin, localtext, 10);
    sfText_setString(localwintext, localtext);
    sfText_setCharacterSize(localwintext, 200);

    if(localwin<10)
        sfText_setPosition(localwintext, (sfVector2f){335, 220});
    else if(localwin<100)
        sfText_setPosition(localwintext, (sfVector2f){280, 220});
    else if(localwin<1000)
        sfText_setPosition(localwintext, (sfVector2f){240, 220});
    else if(localwin<10000)
        sfText_setPosition(localwintext, (sfVector2f){190, 220});
    else if(localwin<100000)
        sfText_setPosition(localwintext, (sfVector2f){140, 220});

    sfRenderWindow_drawSprite(winWindow, winback.sprite, NULL);
    sfRenderWindow_drawText(winWindow, localwintext, NULL);

    sfRenderWindow_display(winWindow);
    Delay(2);
    sfRenderWindow_close(winWindow);
}

int doYouWantToDouble(int castig){

    sfRenderWindow *doyou;
    sfVideoMode moded = {600, 300};
    sfEvent evt;
    sfFont *font;
    sfText *text;

     //creating the window
    doyou = sfRenderWindow_create(moded, "My window", sfClose, NULL);
    if (!doyou)
        return 1;

    //creating the font
    font = sfFont_createFromFile("arial.ttf");
    if(!font)
        exit(1);

    //creating the text
    text = sfText_create();
    sfText_setFont(text, font);
    sfText_setString(text, "Double? Y/N");
    sfText_setCharacterSize(text, 100);
    sfText_setPosition(text, (sfVector2f){20, 70});
    sfRenderWindow_drawText(doyou, text, NULL);
    sfRenderWindow_display(doyou);
     //main loop
    while(sfRenderWindow_isOpen(doyou)){

            //checking for events
        while(sfRenderWindow_pollEvent(doyou, &evt))
        {
            if(evt.type == sfEvtKeyPressed)
            {
               if(evt.key.code == sfKeyY){
                    castig = Dublaj(castig);
                    sfRenderWindow_close(doyou);
                    Delay(1);
                    return castig;
               }
               else if(evt.key.code == sfKeyN){
                    sfRenderWindow_close(doyou);
                    Delay(1);
                    return castig;
               }
            }
            else if (evt.type == sfEvtClosed)
                sfRenderWindow_close(doyou);
        }
    }
}

