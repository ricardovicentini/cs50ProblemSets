#include <cs50.h>
#include <stdio.h>
#include <math.h>

void PrintCreditCardName(int digit_number, int luhnAlg);
long AskCreditCardNumber();
int CalculateLuhnAlgorithm(long card_num);

int card_min_lenght = 13;
int card_max_lenght = 16;
int amex_starting_value1 = 34;
int amex_starting_value2 = 37;
int master_starting_range = 51;
int master_ending_range = 55;
int visa_starting_digit = 4;
int digits_counter = 0;
int startingDigits = 0;

int main(void)
{
    long card_num = AskCreditCardNumber();

    int luhnAlg = CalculateLuhnAlgorithm(card_num);

    PrintCreditCardName(digits_counter, luhnAlg);

}

int CalculateLuhnAlgorithm(long card_num)
{
    int digit = 0;
    int outherSum = 0;
    int multipliedSum = 0;
    do
    {
        digit = card_num % 10;

        if (digits_counter % 2 == 0)
        {
            outherSum += digit;
        }
        else
        {
            int calculatedPart = 0;
            calculatedPart = (digit * 2);
            do
            {
                multipliedSum += (calculatedPart % 10);
                calculatedPart = calculatedPart / 10;
            }
            while (calculatedPart > 0);
        }

        card_num = round(card_num / 10);
        if (card_num > 9)
        {
            startingDigits = card_num;
        }
        digits_counter ++;
    }
    while (card_num > 0);

    return (outherSum + multipliedSum);
}

long AskCreditCardNumber()
{
    long card_num = 0;

    do
    {
        card_num = get_long("Credit card number: ");
    }
    while (card_num <= 0);

    return card_num;

}

void PrintCreditCardName(int digit_number, int luhnAlg)
{
    if (digit_number < card_min_lenght || digit_number > card_max_lenght || luhnAlg % 10 != 0)
    {
        printf("INVALID\n");

    }
    else
    {
        if (startingDigits == amex_starting_value1 || startingDigits == amex_starting_value2)
        {
            printf("AMEX\n");
        }
        else if (startingDigits >= master_starting_range && startingDigits <= master_ending_range)
        {
            printf("MASTERCARD\n");
        }
        else if (startingDigits / 10 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}