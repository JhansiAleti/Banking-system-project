#include <stdio.h>
#include <stdint.h>
#include "account.h"
#include "utils.h"

int main(void)
{
    char choice;
    uint32_t account_number, from_acc, to_acc;
    float amount;

    do
    {
        display_menu();
        printf("Enter your choice:");
        scanf(" %c", &choice);

        switch (choice)
        {
        case 'c':
        case 'C':
            create_account();
            break;

        case 'h':
        case 'H':
            printf("Enter Account Number: ");
            scanf("%u", &account_number);
            show_transaction_history(account_number);
            break;

        case 'w':
        case 'W':
            printf("Enter Account Number: ");
            scanf("%u", &account_number);
            printf("Enter Amount to Withdraw: ");
            scanf("%f", &amount);
            withdraw_amount(account_number, amount);
            break;

        case 'd':
        case 'D':
            printf("Enter Account Number: ");
            scanf("%u", &account_number);
            printf("Enter Amount to Deposit: ");
            scanf("%f", &amount);
            deposit_amount(account_number, amount);
            break;

        case 'b':
        case 'B':
            printf("Enter Account Number: ");
            scanf("%u", &account_number);
            search_account(account_number);
            break;

        case 't':
        case 'T':
            printf("Enter From Account Number: ");
            scanf("%u", &from_acc);
            printf("Enter To Account Number: ");
            scanf("%u", &to_acc);
            printf("Enter Amount to Transfer: ");
            scanf("%f", &amount);
            transfer_money(from_acc, to_acc, amount);
            break;

        case 'e':
        case 'E':
            display_all_accounts();
            break;

        case 's':
        case 'S':
            save_accounts_to_file();
            break;

        case 'q':
        case 'Q':
            printf("Exiting the application.\n");
            break;

        default:
            printf("Invalid choice. Try again!\n");
        }
    } while (choice != 'q' && choice != 'Q');

    return 0;
}
