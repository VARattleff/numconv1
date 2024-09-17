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

int dec_to_int(char str[]) 
{
    int value = 0;
    int position = 0;
    bool negative = false;
    bool valid_input = true;

    if (str[0] == '-') 
    {
        negative = true;
        position = 1;
    }

    while (valid_input) 
    {
        char current_char = str[position];

        if (current_char == '\0') 
        {
            break;
        }
        
        if (current_char == '\n') 
        {
            break;
        }

        if (is_digit(current_char)) 
        {
            value *= 10;
            int digit = current_char - '0';
            value += digit;
            position++;
        } else 
        {
            printf(RED "Invalid input, will default to 0\n" RESET_COLOR);
            valid_input = false;
        }
    }

    if (negative) 
    {
        value = -value;
    }
    
    return valid_input ? value : 0;
}

int bin_to_int(char str[]) 
{
    int value = 0;
    int position = 0;  
    bool negative = false;
    bool valid_input = true;

    if (str[0] == '-') 
    {
        negative = true;
        position = 1;
    }

    while (valid_input) 
    {
        char current_char = str[position];

        if (current_char == '\0') 
        {
            break;
        }


        if (current_char == '\n') 
        {
            break;
        }

        if (is_bin_digit(current_char)) 
        {   
            value = value * 2;  
            value = value + (current_char - '0');  
            position++;
        } 
        else 
        {
            printf(RED "Invalid input, will default to 0\n" RESET_COLOR);
            valid_input = false;
        }
    }

    if (negative) 
    {
        value = -value;
    }

    return valid_input ? value : 0;
}

int hex_to_int(char str[]) 
{
    int value = 0;
    int position = 0;
    bool negative = false;
    bool valid_input = true;

    if (str[0] == '-') 
    {
        negative = true;
        position = 1;
    }

    while (valid_input) 
    {
        char current_char = str[position];

        if (current_char == '\0') 
        {
            break;
        }

        if (current_char == '\n') 
        {
            break;
        }

        if (is_hex_digit(current_char)) 
        {
            value = value * 16;

            if (current_char >= '0') 
            {
                if (current_char <= '9') 
                {
                    value = value + (current_char - '0');
                } 
                else 
                {
                    if (current_char >= 'A') 
                    {
                        if (current_char <= 'F') 
                        {
                            value = value + (current_char - 'A' + 10);
                        } 
                        else 
                        {
                            if (current_char >= 'a') 
                            {
                                if (current_char <= 'f') 
                                {
                                    value = value + (current_char - 'a' + 10);
                                }
                            }
                        }
                    }
                }
            }

            position++;
        } 
        else 
        {
            printf(RED "Invalid input, will default to 0\n" RESET_COLOR);
            valid_input = false;
        }
    }

    if (negative) 
    {
        value = -value;
    }

    return valid_input ? value : 0;
}

int oct_to_int(char str[]) 
{
    int value = 0;
    int position = 0;  
    bool negative = false;
    bool valid_input = true;

    if (str[0] == '-') 
    {
        negative = true;
        position = 1;
    }

    while (valid_input) 
    {
        char current_char = str[position];

        if (current_char == '\0') 
        {
            break;
        }

        if (current_char == '\n') 
        {
            break;
        }

        if (is_oct_digit(current_char)) 
        {
            value = value * 8;
            value = value + (current_char - '0');
            position++;
        } 
        else 
        {
            printf(RED "Invalid input, will default to 0\n" RESET_COLOR);
            valid_input = false;
        }
    }

    if (negative) 
    {
        value = -value;
    }

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

void int_to_bin(int num, char str[])
{
    //TODO: find ud af hvorfor minus ikke virker
    int i;
    unsigned int u_num = (unsigned int)num;  

    for (i = 31; i >= 0; i--) 
    {
        str[i] = (u_num % 2) + '0';  
        u_num = u_num / 2;  
    }

    str[32] = '\0';  
}

void int_to_hex( int num, char str[] )
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
        int remainder = num % 16;

        if (remainder < 10)
        {
            str[position++] = remainder + '0';
        }
        else
        {
            str[position++] = remainder - 10 + 'A';
        }

        num /= 16;
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

void int_to_oct( int num, char str[] )
{
    //TODO: find ud af hvorfor minus ikke virker
    int position = 0;
    bool negative = false;

    if (num < 0)
    {
        negative = true;
        num = -num;
    }

    while (num > 0)
    {
        str[position++] = num % 8 + '0';
        num /= 8;
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