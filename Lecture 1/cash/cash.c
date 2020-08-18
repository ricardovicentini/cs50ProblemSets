#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int quarter = 25;
    int dime = 10;
    int nickles = 5;
    int penny = 1;

    int number_coins = 0;
    int owed_value = 0;
    do
    {
        owed_value = round(get_float("Change owed: ") * 100);
    }
    while (owed_value <= 0);


    number_coins += (owed_value / quarter);
    owed_value = owed_value % quarter;

    number_coins += (owed_value / dime);
    owed_value = owed_value % dime ;

    number_coins += (owed_value / nickles);
    owed_value = owed_value % nickles ;

    number_coins += (owed_value / penny);
    owed_value = owed_value % penny ;

    printf("coins: %i\n", number_coins);


}
