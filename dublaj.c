#include "pacanea.h"

sfRenderWindow *dublaj;
entity backgroundD;
entity backCard;
entity cards[4];
entity previousCards[4];
sfFont* arial;
sfText* winText;
char winActualText[10];
int random;
sfSprite* previous[5] = {NULL, NULL, NULL, NULL, NULL};

void drawWin(int w){

    itoa(w, winActualText, 10);
    sfText_setString(winText, winActualText);
    sfText_setCharacterSize(winText, 115);
    sfText_setPosition(winText, (sfVector2f){720, 697});
    sfRenderWindow_drawText(dublaj, winText, NULL);
}

void drawPreviousCard(int d){

    sfVector2f positionCards[5];
    sfVector2f scaleCards = {0.3, 0.3};
    int i;

    for (i=0; i<5; i++){
        positionCards[i].x = 580 + (float)(140*i);
        positionCards[i].y = 100;
    }
    sfSprite_setScale(previousCards[random].sprite, scaleCards);
    sfSprite_setPosition(previousCards[random].sprite, positionCards[0]);

    if(previous[0] == NULL){

        sfRenderWindow_drawSprite(dublaj, backgroundD.sprite, NULL);
        sfRenderWindow_drawSprite(dublaj, cards[random].sprite, NULL);
        sfSprite_setPosition(previousCards[random].sprite, positionCards[0]);
        sfRenderWindow_drawSprite(dublaj, previousCards[random].sprite, NULL);
        drawWin(d);
        sfRenderWindow_display(dublaj);

        Delay(2);

        sfRenderWindow_drawSprite(dublaj, backgroundD.sprite, NULL);
        sfRenderWindow_drawSprite(dublaj, cards[random].sprite, NULL);
        sfSprite_setPosition(previousCards[random].sprite, positionCards[0]);
        sfRenderWindow_drawSprite(dublaj, previousCards[random].sprite, NULL);
        sfRenderWindow_drawSprite(dublaj, backCard.sprite, NULL);
        drawWin(d);
        sfRenderWindow_display(dublaj);
    }
    else if(previous[1] == NULL){

        sfRenderWindow_drawSprite(dublaj, backgroundD.sprite, NULL);
        sfRenderWindow_drawSprite(dublaj, cards[random].sprite, NULL);
        sfSprite_setPosition(previous[0], positionCards[1]);
        sfRenderWindow_drawSprite(dublaj, previous[0], NULL);
        sfSprite_setPosition(previousCards[random].sprite, positionCards[0]);
        sfRenderWindow_drawSprite(dublaj, previousCards[random].sprite, NULL);
        drawWin(d);
        sfRenderWindow_display(dublaj);

        Delay(2);

        sfRenderWindow_drawSprite(dublaj, backgroundD.sprite, NULL);
        sfRenderWindow_drawSprite(dublaj, cards[random].sprite, NULL);
        sfSprite_setPosition(previous[0], positionCards[1]);
        sfRenderWindow_drawSprite(dublaj, previous[0], NULL);
        sfSprite_setPosition(previousCards[random].sprite, positionCards[0]);
        sfRenderWindow_drawSprite(dublaj, previousCards[random].sprite, NULL);
        sfRenderWindow_drawSprite(dublaj, backCard.sprite, NULL);
        drawWin(d);
        sfRenderWindow_display(dublaj);
    }
    else if(previous[2] == NULL){

        sfRenderWindow_drawSprite(dublaj, backgroundD.sprite, NULL);
        sfRenderWindow_drawSprite(dublaj, cards[random].sprite, NULL);
        for(i=0; i<2; i++){
            sfSprite_setPosition(previous[i], positionCards[i+1]);
            sfRenderWindow_drawSprite(dublaj, previous[i], NULL);
        }
        sfSprite_setPosition(previousCards[random].sprite, positionCards[0]);
        sfRenderWindow_drawSprite(dublaj, previousCards[random].sprite, NULL);
        sfRenderWindow_drawSprite(dublaj, previousCards[random].sprite, NULL);
        drawWin(d);
        sfRenderWindow_display(dublaj);

        Delay(2);

        sfRenderWindow_drawSprite(dublaj, backgroundD.sprite, NULL);
        sfRenderWindow_drawSprite(dublaj, cards[random].sprite, NULL);
        for(i=0; i<2; i++){
            sfSprite_setPosition(previous[i], positionCards[i+1]);
            sfRenderWindow_drawSprite(dublaj, previous[i], NULL);
        }
        sfSprite_setPosition(previousCards[random].sprite, positionCards[0]);
        sfRenderWindow_drawSprite(dublaj, previousCards[random].sprite, NULL);
        sfRenderWindow_drawSprite(dublaj, backCard.sprite, NULL);
        drawWin(d);
        sfRenderWindow_display(dublaj);
    }
    else if(previous[3] == NULL){


        sfRenderWindow_drawSprite(dublaj, backgroundD.sprite, NULL);
        sfRenderWindow_drawSprite(dublaj, cards[random].sprite, NULL);
        for(i=0; i<3; i++){
            sfSprite_setPosition(previous[i], positionCards[i+1]);
            sfRenderWindow_drawSprite(dublaj, previous[i], NULL);
        }
        sfSprite_setPosition(previousCards[random].sprite, positionCards[0]);
        sfRenderWindow_drawSprite(dublaj, previousCards[random].sprite, NULL);
        sfRenderWindow_drawSprite(dublaj, previousCards[random].sprite, NULL);
        drawWin(d);
        sfRenderWindow_display(dublaj);

        Delay(2);

        sfRenderWindow_drawSprite(dublaj, backgroundD.sprite, NULL);
        sfRenderWindow_drawSprite(dublaj, cards[random].sprite, NULL);
        for(i=0; i<3; i++){
            sfSprite_setPosition(previous[i], positionCards[i+1]);
            sfRenderWindow_drawSprite(dublaj, previous[i], NULL);
        }
        sfSprite_setPosition(previousCards[random].sprite, positionCards[0]);
        sfRenderWindow_drawSprite(dublaj, previousCards[random].sprite, NULL);
        sfRenderWindow_drawSprite(dublaj, backCard.sprite, NULL);
        drawWin(d);
        sfRenderWindow_display(dublaj);
    }
    else{

        sfRenderWindow_drawSprite(dublaj, backgroundD.sprite, NULL);
        sfRenderWindow_drawSprite(dublaj, cards[random].sprite, NULL);
        for(i=0; i<4; i++){
            sfSprite_setPosition(previous[i], positionCards[i+1]);
            sfRenderWindow_drawSprite(dublaj, previous[i], NULL);
        }
        sfSprite_setPosition(previousCards[random].sprite, positionCards[0]);
        sfRenderWindow_drawSprite(dublaj, previousCards[random].sprite, NULL);
        sfRenderWindow_drawSprite(dublaj, previousCards[random].sprite, NULL);
        drawWin(d);
        sfRenderWindow_display(dublaj);

        Delay(2);

        sfRenderWindow_drawSprite(dublaj, backgroundD.sprite, NULL);
        sfRenderWindow_drawSprite(dublaj, cards[random].sprite, NULL);
        for(i=0; i<4; i++){
            sfSprite_setPosition(previous[i], positionCards[i+1]);
            sfRenderWindow_drawSprite(dublaj, previous[i], NULL);
        }
        sfSprite_setPosition(previousCards[random].sprite, positionCards[0]);
        sfRenderWindow_drawSprite(dublaj, previousCards[random].sprite, NULL);
        sfRenderWindow_drawSprite(dublaj, backCard.sprite, NULL);
        drawWin(d);
        sfRenderWindow_display(dublaj);
    }


    for(i=4; i>0; i--)
        previous[i] = previous[i-1];
    previous[0] = previousCards[random].sprite;
}

int Dublaj(int castig){

    srand(time(NULL));

    sfEvent event;
    sfVector2f positionCards = {580, 320};
    sfVector2f scaleCards = {0.3, 0.3};
    char localcastig[10];

    //creating the window
    dublaj = sfRenderWindow_create((sfVideoMode){1400, 900}, "Dublaj", sfClose, NULL);
    if(!dublaj)
        exit (1);

    //creating the background
    backgroundD = createSprite("z-backgroundD.jpg");

    //creating the cards
    backCard = createSprite("z-carte.jpg");
    sfSprite_setScale(backCard.sprite, scaleCards);
    sfSprite_setPosition(backCard.sprite, positionCards);

    cards[pica] = createSprite("z-pica.png");
    sfSprite_setScale(cards[pica].sprite, scaleCards);
    sfSprite_setPosition(cards[pica].sprite, positionCards);

    cards[trefla] = createSprite("z-trefla.png");
    sfSprite_setScale(cards[trefla].sprite, scaleCards);
    sfSprite_setPosition(cards[trefla].sprite, positionCards);

    cards[inima] = createSprite("z-inima.png");
    sfSprite_setScale(cards[inima].sprite, scaleCards);
    sfSprite_setPosition(cards[inima].sprite, positionCards);

    cards[romb] = createSprite("z-romb.png");
    sfSprite_setScale(cards[romb].sprite, scaleCards);
    sfSprite_setPosition(cards[romb].sprite, positionCards);

    previousCards[pica] = createSprite("z-picaP.png");
    previousCards[trefla] = createSprite("z-treflaP.png");
    previousCards[inima] = createSprite("z-inimaP.png");
    previousCards[romb] = createSprite("z-rombP.png");

    //creating the win text
    arial = sfFont_createFromFile("arial.ttf");
    if(!arial)
        return 1;
    winText = sfText_create();
    sfText_setFont(winText, arial);

    sfRenderWindow_drawSprite(dublaj, backgroundD.sprite, NULL);
    sfRenderWindow_drawSprite(dublaj, backCard.sprite, NULL);
    sfRenderWindow_display(dublaj);

    //main loop
    while(sfRenderWindow_isOpen(dublaj))
        {

        //checking for events
        while(sfRenderWindow_pollEvent(dublaj, &event))
        {
            if(event.type == sfEvtKeyPressed)
            {
                switch(event.key.code) {
                    case sfKeyR:

                        random = rand() % 4;

                        if(random == pica || random == trefla){
                            castig = 0;
                            sfRenderWindow_drawSprite(dublaj, cards[random].sprite, NULL);
                            drawPreviousCard(castig);
                            Delay(1);
                            sfRenderWindow_close(dublaj);
                            return 0;
                        }
                        else{
                            castig *= 2;
                            sfRenderWindow_drawSprite(dublaj, cards[random].sprite, NULL);
                            drawPreviousCard(castig);
                        }


                        break;
                    case sfKeyB:

                        random = rand() % 4;

                        if(random == inima || random == romb){
                            castig = 0;
                            sfRenderWindow_drawSprite(dublaj, cards[random].sprite, NULL);
                            drawPreviousCard(castig);
                            Delay(1);
                            sfRenderWindow_close(dublaj);
                            return 0;
                        }
                        else{
                            castig *= 2;
                            sfRenderWindow_drawSprite(dublaj, cards[random].sprite, NULL);
                            drawPreviousCard(castig);
                        }

                        break;
                    case sfKeyT:

                        winningDisplay(castig);
                        sfRenderWindow_close(dublaj);
                        return castig;

                        break;
						/*
                    case sfKeyV:

                        random = rand() % 2;

                        if(random == inima || random == romb){
                            castig = 0;
                            sfRenderWindow_drawSprite(dublaj, cards[random].sprite, NULL);
                            drawPreviousCard(castig);
                            Delay(1);
                            sfRenderWindow_close(dublaj);
                            return 0;
                        }
                        else{
                            castig *= 2;
                            sfRenderWindow_drawSprite(dublaj, cards[random].sprite, NULL);
                            drawPreviousCard(castig);
                        }
                        break;

                    case sfKeyE:

                        random = rand() % 2 + 2;

                        if(random == pica || random == trefla){
                            castig = 0;
                            sfRenderWindow_drawSprite(dublaj, cards[random].sprite, NULL);
                            drawPreviousCard(castig);
                            Delay(1);
                            sfRenderWindow_close(dublaj);
                            return 0;
                        }
                        else{
                            castig *= 2;
                            sfRenderWindow_drawSprite(dublaj, cards[random].sprite, NULL);
                            drawPreviousCard(castig);
                        }
                        break;
				*/
                }
            }
            else if (event.type == sfEvtClosed)
                sfRenderWindow_close(dublaj);

        }
    }
}
