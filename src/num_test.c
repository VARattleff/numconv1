#include <stdio.h>
#include "convert_num.h"

void handle_test_dec_to_int();
void handle_test_bin_to_int();

int test_convert_num()
{
    printf("-------------------\n");
    printf("dec_to_int test:\n");
    handle_test_dec_to_int();
    printf("-------------------\n");
    printf("bin_to_int test:\n");
    handle_test_bin_to_int();
    printf("-------------------\n");

    return 0;    
}

void handle_test_dec_to_int()
{
    char str[] = "12sdfsdfsdf3d4"; 
    
    int val = dec_to_int(str);  
    printf("%s -> %d\n", str, val);

}

void handle_test_bin_to_int()
{
    char *str[] = {"-1010", "0100", "10101010"};
    int position = 0;

    while (position < 3)
    {
        int val = bin_to_int(str[position]);  
        printf("%s -> %d\n", str[position], val);
        position++;
    };
}
