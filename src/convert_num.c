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

bool is_hex_digit(char c)
{
    const char valid_hex[] = "0123456789abcdefABCDEF";

    bool valid_input = false;
    int position = 0;

    while (position < sizeof(valid_hex) - 1)
    {
        if(c == valid_hex[position])
        {
            valid_input = true;
            break;
        }
        position++;
    }
    
    return valid_input;
}

bool is_oct_digit(char c)
{
    return (c >= '0') ? (c <= '7'): false;
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

int hex_to_int(char str[])
{
    int value = 0;
    int position = (str[0] == '-') ? 1 : 0;  
    bool negative = (str[0] == '-');         
    bool valid_input = true;

    while (str[position] != '\0')
    {
        char current_char = str[position++];

        if (is_hex_digit(current_char))
        {
            value *= 16;  
            
            if (current_char >= '0')
            {
                if (current_char <= '9')
                {
                    value += current_char - '0';  
                }
                else if (current_char >= 'A')
                {
                    if (current_char <= 'F')
                    {
                        value += current_char - 'A' + 10;  
                    }
                    else if (current_char >= 'a')
                    {
                        if (current_char <= 'f')
                        {
                            value += current_char - 'a' + 10;  
                        }
                        else
                        {
                            valid_input = false;  
                            break;
                        }
                    }
                    else
                    {
                        valid_input = false;  
                        break;
                    }
                }
                else
                {
                    valid_input = false;  
                    break;
                }
            }
            else
            {
                valid_input = false;  
                break;
            }
        }
        else
        {
            printf("Invalid input, will default to 0\n");
            valid_input = false;
            break;
        }
    }

    negative ? -value : value;

    return valid_input ? value : 0;
}

int oct_to_int( char str[] ) 
{

    int value = 0;
    int position = (str[0] == '-') ? 1 : 0;  
    bool negative = (str[0] == '-');  
    bool valid_input = true;

    while (str[position] != '\0')
    {
        if(is_oct_digit(str[position]))
        {
            value *=8;
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

void int_to_dec( int num, char str[] )
{
    int position = 0;
    bool negative = false;

    if (num < 0)
    {
        negative = true;
        num = -num;
    }

    while (num > 0)
    {
        str[position++] = num % 10 + '0';
        num /= 10;
    }

    if (negative)
    {
        str[position++] = '-';
    }

    str[position] = '\0';

    for (int i = 0; i < position / 2; i++)
    {
        char temp = str[i];
        str[i] = str[position - i - 1];
        str[position - i - 1] = temp;
    }
}