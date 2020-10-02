#include "pacanea.h"

    //declaration
    sfRenderWindow *window;
    entity background;
    entity slot;
    entity slotBack;
    entity img[6];
    sfText* textM[2];
    sfFont* fontM;
    sfVector2f positionVCAW[3]={(sfVector2f){397, 365}, (sfVector2f){604, 360}, (sfVector2f){811, 360}};
    sfVector2f positionCS[3]={(sfVector2f){390, 400}, (sfVector2f){600, 400}, (sfVector2f){810, 400}};
    int randomN[3];
    int miza = 1;
    int credit = 1000;
    int win;
    char actualText[2][10];

void randSprite(int localrandom, int column){

    if (localrandom == cherry || localrandom == seven){
        sfSprite_setPosition(img[localrandom].sprite, positionCS[column]);
        sfRenderWindow_drawSprite(window, img[localrandom].sprite, NULL);
    }
    else {
        sfSprite_setPosition(img[localrandom].sprite, positionVCAW[column]);
        sfRenderWindow_drawSprite(window, img[localrandom].sprite, NULL);
    }
}
void drawElements(){

    int i;

    sfRenderWindow_drawSprite(window, background.sprite, NULL);
    sfRenderWindow_drawSprite(window, slotBack.sprite, NULL);
    sfRenderWindow_drawSprite(window, slot.sprite, NULL);
    for(i=0; i<3; i++){
        randomN[i] = rand() % 6;
        randSprite(randomN[i], i);
    }
    drawCredits(credit);
    drawBet(miza);
    sfRenderWindow_display(window);
}
void drawCredits(int c){

    itoa(c, actualText[credits], 10);
    sfText_setString(textM[credits], actualText[credits]);
    sfText_setCharacterSize(textM[credits], 90);
    sfText_setPosition(textM[credits], (sfVector2f){380, 753});
    sfRenderWindow_drawText(window, textM[credits], NULL);
}

void drawBet(int b){

    itoa(b, actualText[bet], 10);
    sfText_setString(textM[bet], actualText[bet]);
    sfText_setCharacterSize(textM[bet], 90);
    sfText_setPosition(textM[bet], (sfVector2f){1150, 753});
    sfRenderWindow_drawText(window, textM[bet], NULL);

}

void pacaneaua()
{
    srand(time(NULL));
    sfVideoMode mode= {1400, 900};
    sfEvent event;
    sfVector2f positionSlot = {365, 200};
    sfVector2f positionSlotBack = {365, 230};
    int i=0;

    //creating the window
    window = sfRenderWindow_create(mode, "My window", sfClose, NULL);
    if (!window)
        exit(1);

    //creating and setting up the background
    background = createSprite("z-background.jpg");
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, background.sprite, NULL);


    //creating the background of the slot
    slotBack = createSprite("z-backslot.jpg");
    sfSprite_setPosition(slotBack.sprite, positionSlotBack);
    sfRenderWindow_drawSprite(window, slotBack.sprite, NULL);


    //creating the slot
    slot = createSprite("z-slot.png");
    sfSprite_setPosition(slot.sprite, positionSlot);
    sfSprite_scale(slot.sprite, (sfVector2f){1, 1});
    sfRenderWindow_drawSprite(window, slot.sprite, NULL);


    //creating the pictures for the first column of the slot machine
    img[cherry] = createSprite("z-cherry.png");
    img[seven] = createSprite("z-seven.png");
    img[Varga] = createSprite("z-Varga.jpg");
    sfSprite_scale(img[Varga].sprite, (sfVector2f){0.33, 0.30});
    img[Cristi] = createSprite("z-Cristi.jpg");
    sfSprite_scale(img[Cristi].sprite, (sfVector2f){0.175, 0.16});
    img[Andrei] = createSprite("z-Andrei.jpg");
    sfSprite_scale(img[Andrei].sprite, (sfVector2f){0.175, 0.16});
    img[wild] = createSprite("z-wild.png");
    sfSprite_scale(img[wild].sprite, (sfVector2f){0.27, 0.30});


    //preparing the text
    fontM = sfFont_createFromFile("arial.ttf");
    if(!fontM)
        exit(1);
    for(i=0; i<2; i++){
        textM[i] = sfText_create();
        sfText_setFont(textM[i], fontM);
    }
    drawCredits(credit);
    drawBet(miza);
    sfRenderWindow_display(window);

    //main loop
    while(sfRenderWindow_isOpen(window))
        {
            //checking for events
        while(sfRenderWindow_pollEvent(window, &event))
        {
            if(event.type == sfEvtKeyPressed)
            {
                if(event.key.code == sfKeySpace)
                {
                    if(credit<miza){
                        if(miza == 1)
                            exit(0);
                        else
                            miza = 1;
                    }
                    drawElements();
                    Delay(0.5);
                    win = winning(randomN[0], randomN[1], randomN[2], miza);
                    credit = credit - miza;
                    credit += win;

                }
                else if(event.key.code == sfKeyAdd){
                    miza = setBet(miza);
                    sfRenderWindow_drawSprite(window, background.sprite, NULL);
                    sfRenderWindow_drawSprite(window, slotBack.sprite, NULL);
                    sfRenderWindow_drawSprite(window, slot.sprite, NULL);
                    drawCredits(credit);
                    drawBet(miza);
                    sfRenderWindow_display(window);
                }
                else if(event.key.code == sfKeyEscape)
                    sfRenderWindow_close(window);
                else if (event.key.code == sfKeyP)
                    credit = 100000;
            }
            else if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);

        }
    }
    exit(1);

}
