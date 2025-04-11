#include <stdio.h>
#include "utils.h"

void flush_input_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void display_menu(void)
{
    printf("\n------------------MENU--------------------------\n");
    printf("c/C: Create account.\n");
    printf("h/H: Transaction history.\n");
    printf("w/W: Withdraw amount.\n");
    printf("d/D: Deposit amount.\n");
    printf("b/B: Balance inquiry.\n");
    printf("t/T: Transfer money.\n");
    printf("e/E: Display all accounts.\n");
    printf("s/S: Save the accounts info in file.\n");
    printf("q/Q: Quit from app.\n");
    printf("------------------------------------------------\n");
    printf("Enter your choice: ");
}