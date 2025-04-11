#include "transaction.h"
#include "account.h"
#include <stdio.h>
#include <stdint.h>

static uint32_t transaction_id_counter = 1U;  // Global counter for unique transaction IDs

void record_transaction(account_t *acc, transaction_type_t type, float amount)
{
    if (acc->transaction_count < MAX_TRANSACTIONS)
    {
        transaction_t *transaction = &acc->transactions[acc->transaction_count];
        transaction->transaction_id = transaction_id_counter++;
        transaction->type = type;
        transaction->amount = amount;
        acc->transaction_count++;

        printf("Transaction recorded successfully.\n");
    }
    else
    {
        printf("Transaction limit reached for this account.\n");
    }
}