#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "account.h"
#include "transaction.h"
#include "utils.h"

account_t *head=NULL;

void create_account(void)
{
    account_t *new_acc = (account_t *)malloc(sizeof(account_t));

    if (new_acc == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%u", &new_acc->account_number);
    flush_input_buffer();

    printf("Enter Account Holder Name: ");
    fgets(new_acc->account_name, MAX_NAME_LEN, stdin);
    new_acc->account_name[strcspn(new_acc->account_name, "\n")] = '\0';

    printf("Enter Contact Number: ");
    fgets(new_acc->contact_number, MAX_CONTACT_LEN, stdin);
    new_acc->contact_number[strcspn(new_acc->contact_number, "\n")] = '\0';

    new_acc->account_balance = 0.0F;
    new_acc->transaction_count = 0U;
    new_acc->next = head;
    head = new_acc;

    printf("Account created successfully!\n");
}

void display_all_accounts(void)
{
    account_t *temp = head;

    if(temp==NULL)
    {
            printf("No accounts found.\n");
            return;
    }

    while (temp != NULL)
    {
        printf("Account Number: %u\n", temp->account_number);
        printf("Name: %s\n", temp->account_name);
        printf("Balance: %.2f\n", temp->account_balance);
        printf("Contact: %s\n", temp->contact_number);
        temp = temp->next;
    }
}
void withdraw_amount(uint32_t account_number, float amount)
{
    account_t *temp = head;
    while (temp != NULL)
    {
        if (temp->account_number == account_number)
        {
            if (temp->account_balance >= amount)
            {
                temp->account_balance -= amount;
                record_transaction(temp, WITHDRAW, amount);
                printf("Amount withdrawn successfully.\n");
            }
            else
            {
                printf("Insufficient balance.\n");
            }
            return;
        }
        temp = temp->next;
    }
    printf("Account not found.\n");
}

void search_account(uint32_t account_number)
{
    account_t *temp = head;

    printf("Enter Account Number to Search: ");
    scanf("%u", &account_number);

    while (temp != NULL)
    {
        if (temp->account_number == account_number)
        {
            printf("Account Found!\n");
            printf("Account Number: %u\n", temp->account_number);
            printf("Name: %s\n", temp->account_name);
            printf("Balance: %.2f\n", temp->account_balance);
            printf("Contact: %s\n", temp->contact_number);
            return;
        }
        temp = temp->next;
    }
    printf("Account not found.\n");
}

void deposit_amount(uint32_t account_number, float amount)
{
    account_t *temp = head;

    printf("Enter Account Number for Deposit: ");
    scanf("%u", &account_number);

    while (temp != NULL)
    {
        if (temp->account_number == account_number)
        {
            printf("Enter Amount to Deposit: ");
            scanf("%f", &amount);
            temp->account_balance += amount;
            record_transaction(temp, DEPOSIT, amount);
            printf("Amount %.2f deposited successfully!\n", amount);
            return;
        }
        temp = temp->next;
    }
    printf("Account not found.\n");
}

void transfer_money(uint32_t from_acc, uint32_t to_acc, float amount)
{
    account_t *from_account = NULL, *to_account = NULL;
    account_t *temp = head;

    while (temp != NULL)
    {
        if (temp->account_number == from_acc)
        {
            from_account = temp;
        }
        if (temp->account_number == to_acc)
        {
            to_account = temp;
        }
        temp = temp->next;
    }

    if (from_account == NULL || to_account == NULL)
    {
        printf("Invalid account numbers.\n");
        return;
    }

    if (from_account->account_balance < amount)
    {
        printf("Insufficient balance for transfer.\n");
        return;
    }

    from_account->account_balance -= amount;
    to_account->account_balance += amount;

    printf("Amount %.2f transferred successfully from %u to %u.\n", amount, from_acc, to_acc);
}


void show_transaction_history(uint32_t account_number)
{
    account_t *temp = head;

    printf("Enter Account Number to View Transaction History: ");
    scanf("%u", &account_number);

    while (temp != NULL)
    {
        if (temp->account_number == account_number)
        {
            printf("Transaction History for Account: %u\n", account_number);
            for (uint32_t i = 0U; i < temp->transaction_count; i++)
            {
                printf("Transaction ID: %u, Type: %s, Amount: %.2f\n",
                       temp->transactions[i].transaction_id,
                       (temp->transactions[i].type == DEPOSIT) ? "Deposit" : "Withdraw",
                       temp->transactions[i].amount);
            }
            return;
        }
        temp = temp->next;
    }
    printf("Account not found.\n");
}