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
    char str[] = "1234"; 
    int val = dec_to_int(str);  
    printf("%s -> %d\n", str, val);
}

void handle_test_bin_to_int()
{
    char str[] = "10101010";
    int val = bin_to_int(str);  
    printf("%s -> %d\n", str, val);
}
