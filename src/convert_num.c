#include <stdio.h>
#include <stdbool.h>


int dec_to_int( char str[] )
{
    int value = 0;
    int position = (str[0] == '-') ? 1 : 0;  
    bool negative = (str[0] == '-');  

    while (str[position] != '\0')
    {
        value *=10;
        int digit = str[position++] - '0';
        value +=digit;
    }

    return negative ? -value : value;
}

int bin_to_int( char str[] )
{
    int value = 0;
    int position = (str[0] == '-') ? 1 : 0;  
    bool negative = (str[0] == '-');  

    while (str[position] != '\0')
    {
        value *=2;
        int digit = str[position++] - '0';
        value +=digit;
    }

    return negative ? -value : value;
}