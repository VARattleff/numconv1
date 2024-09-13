#include <stdio.h>
#include <stdbool.h>
#include "colors.h"

bool is_digit( char c )
{
    return (c >= '0') ? (c <= '9') : false;
}

bool is_bin_digit(char c)
{
    return (c >= '0') ? (c <= '1'): false;
}

int dec_to_int( char str[] )
{
    int value = 0;
    int position = (str[0] == '-') ? 1 : 0;  
    bool negative = (str[0] == '-');  
    bool valid_input = true;

    while (str[position] != '\0')
    {
        if(is_digit(str[position]))
        {
            value *=10;
            int digit = str[position++] - '0';
            value +=digit;    
        } else
        {
            printf(RED "invalid input will default to 0\n" RESET_COLOR);
            valid_input = false;
            break;
        }
        
    }

    negative ? -value : value;

    return valid_input ? value : 0;
}

int bin_to_int( char str[] )
{
    int value = 0;
    int position = (str[0] == '-') ? 1 : 0;  
    bool negative = (str[0] == '-');  
    bool valid_input = true;

    while (str[position] != '\0')
    {
        if(is_bin_digit(str[position]))
        {   
            value *=2;
            int digit = str[position++] - '0';
            value +=digit;
        } else
        {
            printf(RED "invalid input will default to 0\n" RESET_COLOR);
            valid_input = false;
            break;   
        }
    }

    negative ? -value : value;

    return valid_input ? value : 0;
}