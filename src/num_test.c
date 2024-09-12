#include <stdio.h>
#include "convert_num.h"

void handle_test_dec_to_int();

int test_convert_num()
{
    handle_test_dec_to_int();
    return 0;    
}

void handle_test_dec_to_int()
{
    char *str[] = {"-1234", "1234"};
    int position = 0;

    while (position < 2)
    {
        int val = dec_to_int(str[position]);  
        printf("%s -> %d\n", str[position], val);
        position++;
    };
}