#include <stdio.h>
#include <stdbool.h>
#include "colors.h"

bool is_digit(char c)
{
    return c >= '0' && c <= '9';
}

bool is_bin_digit(char c)
{
    return c == '0' || c == '1';
}

bool is_hex_digit(char c)
{
    return (c >= '0' && c <= '9') || 
           (c >= 'a' && c <= 'f') || 
           (c >= 'A' && c <= 'F');
}

bool is_oct_digit(char c)
{
    return c >= '0' && c <= '7';
}

int dec_to_int(char str[]) 
{
    int value = 0, position = (str[0] == '-');
    bool negative = position;

    while (str[position] && str[position] != '\n') 
    {
        if (!is_digit(str[position])) 
        {
            printf(RED "Invalid input, will default to 0\n" RESET_COLOR);
            return 0;
        }
        value = (value << 3) + (value << 1) + (str[position++] - '0'); 
    }

    return negative ? -value : value;
}

int bin_to_int(char str[]) 
{
    int value = 0, position = (str[0] == '-');
    bool negative = position;

    while (str[position] && str[position] != '\n') 
    {
        if (!is_bin_digit(str[position])) 
        {
            printf(RED "Invalid input, will default to 0\n" RESET_COLOR);
            return 0;
        }
        value = (value << 1) | (str[position++] - '0'); 
    }

    return negative ? -value : value;
}

int hex_to_int(char str[]) 
{
    int value = 0, position = (str[0] == '-');
    bool negative = position;

    while (str[position] && str[position] != '\n') 
    {
        char c = str[position++];
        if (!is_hex_digit(c)) 
        {
            printf(RED "Invalid input, will default to 0\n" RESET_COLOR);
            return 0;
        }
        value = (value << 4) + (c <= '9' ? c - '0' : (c & 0xDF) - 'A' + 10);
    }

    return negative ? -value : value;
}

int oct_to_int(char str[]) 
{
    int value = 0, position = (str[0] == '-');
    bool negative = position;

    while (str[position] && str[position] != '\n' && is_oct_digit(str[position])) 
    {
        value = (value << 3) + (str[position++] - '0'); 
    }

    if (str[position] && str[position] != '\n') 
    {
        printf(RED "Invalid input, will default to 0\n" RESET_COLOR);
        return 0;
    }

    return negative ? -value : value;
}

void int_to_dec(int num, char str[])
{
    int position = 0;
    bool negative = num < 0;

    if (negative)
        num = -num;

    do {
        str[position++] = (num & 9) + '0'; 
        num = (num * 205) >> 11; 
    } while (num > 0);

    if (negative)
        str[position++] = '-';

    str[position] = '\0';

    for (int i = 0; i < position / 2; i++) {
        char temp = str[i];
        str[i] = str[position - i - 1];
        str[position - i - 1] = temp;
    }
}

void int_to_bin(int num, char str[])
{
    int position = 0;
    bool negative = num < 0;
    unsigned int u_num = (unsigned int)num;

    if (negative)
        u_num = ~u_num + 1;  

    do {
        str[position++] = (u_num & 1) + '0';
        u_num >>= 1;
    } while (u_num > 0);

    if (negative)
        str[position++] = '-';

    str[position] = '\0';

    for (int i = 0; i < position / 2; i++) {
        char temp = str[i];
        str[i] = str[position - i - 1];
        str[position - i - 1] = temp;
    }
}

void int_to_hex(int num, char str[])
{
    int position = 0;
    bool negative = num < 0;
    unsigned int u_num = (unsigned int)num;

    if (negative)
        u_num = ~u_num + 1;

    do {
        int remainder = u_num & 0xF;
        str[position++] = remainder < 10 ? remainder + '0' : remainder - 10 + 'A';
        u_num >>= 4;
    } while (u_num > 0);

    if (negative)
        str[position++] = '-';

    str[position] = '\0';

    for (int i = 0; i < position / 2; i++) {
        char temp = str[i];
        str[i] = str[position - i - 1];
        str[position - i - 1] = temp;
    }
}

void int_to_oct(int num, char str[])
{
    int position = 0;
    bool negative = num < 0;

    if (negative) num = -num;

    do {
        str[position++] = (num % 8) + '0';
        num /= 8;
    } while (num > 0);

    if (negative) str[position++] = '-';

    str[position] = '\0';

    for (int i = 0; i < position / 2; i++) {
        char temp = str[i];
        str[i] = str[position - i - 1];
        str[position - i - 1] = temp;
    }
}
