#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool luhn_algorithm(const char *card_number); 
bool is_visa(const char *card_number);
bool is_american_express(const char *card_number);
bool is_mastercard(const char *card_number);

int main()
{
    string card_number = get_string("Enter your card number: ");

    if (luhn_algorithm(card_number))
    {
        if (is_visa(card_number))
        {
            printf("VISA\n");
        }
        else if (is_mastercard(card_number))
        {
            printf("MASTERCARD\n");
        }
        else if (is_american_express(card_number))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}

bool luhn_algorithm(const char *card_number)
{
    int sum = 0;
    int length = strlen(card_number);
    bool isSecond = false;

    for (int i = length - 1; i >= 0; i--)
    {
        int digit = card_number[i] - '0';

        if (isSecond)
        {
            digit *= 2;
        }

        sum += digit / 10;
        sum += digit % 10;

        isSecond = !isSecond; 
    }

    return (sum % 10 == 0); //Luhn's algorithm rule last digit must equals to 0
}

//function to verify if card number is VISA
bool is_visa(const char *card_number)
{
    int length = strlen(card_number);
    return (card_number[0] == '4') && (length == 13 || length == 16 || length == 19); //Returns true if it respects these conditions
}

//function to verify if card number is Master Card
bool is_mastercard(const char *card_number)
{
    int length = strlen(card_number);
    int first_two_digits = (card_number[0] - '0') * 10 + (card_number[1] - '0');

    return (length == 16) && ((first_two_digits >= 51 && first_two_digits <= 55)); //Returns true if it respects these conditions
}

//function to verify if card number is AMEX
bool is_american_express(const char *card_number)
{
    int length = strlen(card_number);
    int first_two_digits = (card_number[0] - '0') * 10 + (card_number[1] - '0');

    return (length == 15) && (first_two_digits == 34 || first_two_digits == 37); //Returns true if it respects these conditions
}
