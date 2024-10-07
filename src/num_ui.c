#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "convert_num2.h"
#include "colors.h"

#define MAX_INPUT 100

void print_menu()
{
    printf(BLUE "\n--- Number Conversion Program ---\n" RESET_COLOR);
    printf("1. Convert from Decimal\n");
    printf("2. Convert from Binary\n");
    printf("3. Convert from Hexadecimal\n");
    printf("4. Convert from Octal\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void convert_and_print(int num) 
{
    char result[MAX_INPUT];
    
    printf(GREEN "\nConversion Results:\n" RESET_COLOR);
    
    int_to_dec(num, result);
    printf("Decimal: %s\n", result);
    
    int_to_bin(num, result);
    printf("Binary: %s\n", result);
    
    int_to_hex(num, result);
    printf("Hexadecimal: %s\n", result);
    
    int_to_oct(num, result);
    printf("Octal: %s\n", result);
}

int main_ui() 
{
    char input[MAX_INPUT];
    int choice;
    int num;
    bool running = true;

    while (running) 
    {
        print_menu();
        if (fgets(input, sizeof(input), stdin) == NULL) 
        {
            printf(RED "Error reading input.\n" RESET_COLOR);
            continue;
        }
        choice = atoi(input);

        switch (choice) 
        {
            case 1:
                printf("Enter a decimal number: ");
                if (fgets(input, sizeof(input), stdin) == NULL) 
                {
                    printf(RED "Error reading input.\n" RESET_COLOR);
                    continue;
                }
                num = dec_to_int(input);
                convert_and_print(num);
                break;
            case 2:
                printf("Enter a binary number: ");
                if (fgets(input, sizeof(input), stdin) == NULL) 
                {
                    printf(RED "Error reading input.\n" RESET_COLOR);
                    continue;
                }
                num = bin_to_int(input);
                if (num == 0 && input[0] != '0') 
                {
                    printf(RED "Invalid binary input.\n" RESET_COLOR);
                    continue;
                }
                convert_and_print(num);
                break;
            case 3:
                printf("Enter a hexadecimal number: ");
                if (fgets(input, sizeof(input), stdin) == NULL) 
                {
                    printf(RED "Error reading input.\n" RESET_COLOR);
                    continue;
                }
                num = hex_to_int(input);
                if (num == 0 && input[0] != '0') 
                {
                    printf(RED "Invalid hexadecimal input.\n" RESET_COLOR);
                    continue;
                }
                convert_and_print(num);
                break;
            case 4:
                printf("Enter an octal number: ");
                if (fgets(input, sizeof(input), stdin) == NULL) 
                {
                    printf(RED "Error reading input.\n" RESET_COLOR);
                    continue;
                }
                num = oct_to_int(input);
                if (num == 0 && input[0] != '0') 
                {
                    printf(RED "Invalid octal input.\n" RESET_COLOR);
                    continue;
                }
                convert_and_print(num);
                break;
            case 5:
                printf(YELLOW "Exiting the program. Goodbye!\n" RESET_COLOR);
                running = false;
                break;
            default:
                printf(RED "Invalid choice. Please try again.\n" RESET_COLOR);
        }
    }

    return 0;
}