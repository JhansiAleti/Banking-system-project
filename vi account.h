#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <stdint.h>
#include "transaction.h"

#define MAX_NAME_LEN 50
#define MAX_CONTACT_LEN 15
#define MAX_TRANSACTIONS 100

typedef struct account
{
    uint32_t account_number;
    char account_name[MAX_NAME_LEN];
    char contact_number[MAX_CONTACT_LEN];
    float account_balance;
    transaction_t transactions[MAX_TRANSACTIONS];
    uint32_t transaction_count;
    struct account *next;
} account_t;

// Global head pointer
extern account_t *head;

// Function prototypes
void create_account(void);
void display_all_accounts(void);
void search_account(uint32_t account_number);
void deposit_amount(uint32_t account_number, float amount);
void withdraw_amount(uint32_t account_number, float amount);
void transfer_money(uint32_t from_acc, uint32_t to_acc, float amount);
void show_transaction_history(uint32_t account_number);
void save_accounts_to_file(void);

#endif  // ACCOUNT_H

