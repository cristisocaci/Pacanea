#include "pacanea.h"

//CUM SE FACE CASTIGUL
int winning(int img_a, int img_b, int img_c, int bet)
{
    int money=0;

        if((img_a==img_b)&&(img_b==img_c) || ((img_a==img_b)&&img_c==wild) || (img_a==img_c)&&img_b==wild || (img_b==wild)&&(img_c==wild))
        {
            if(img_a==cherry)
                money=2*bet;
            else if(img_a==seven)
                money=7*bet;
            else if(img_a==Varga)
                money=3*bet;
            else if(img_a==Cristi)
                money=3*bet;
            else if(img_a==Andrei)
                money=3*bet;
            else if(img_a==wild)
                money=30*bet;
            winningDisplay(money);
            money = doYouWantToDouble(money);
        }
        else if((img_b==img_c)&&img_a==wild || (img_a==wild)&&(img_c==wild))
            {
            if(img_b==cherry)
               money=2*bet;
            else if(img_b==seven)
               money=7*bet;
            else if(img_b==Varga)
                money=3*bet;
            else if(img_b==Cristi)
                money=3*bet;
            else if(img_b==Andrei)
                money=3*bet;
            winningDisplay(money);
            money = doYouWantToDouble(money);
        }
         else if((img_a==wild)&&(img_b==wild))
            {
            if(img_c==cherry)
                money=2*bet;
            else if(img_c==seven)
                money=7*bet;
            else if(img_c==Varga)
                money=3*bet;
            else if(img_c==Cristi)
                money=3*bet;
            else if(img_c==Andrei)
                money=3*bet;
            winningDisplay(money);
            money = doYouWantToDouble(money);
        }

    return money;

}
//FUNCTIE DE MIZA
int setBet(int miza)
{
    int mize[]= {1,5,10,25,50,100,200,500,1000};
    for(int i=0; i<9; i++)
    {
        if (miza==mize[i])
        {
            if(i==8)
            {
                miza=1;
            }
            else
            {
                miza=mize[i+1];
            }
            break;
        }
    }
    return miza;
}



