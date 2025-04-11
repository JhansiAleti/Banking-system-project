#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <stdint.h>

typedef struct account account_t;

typedef enum
{
    DEPOSIT,
    WITHDRAW
} transaction_type_t;

typedef struct transaction
{
    uint32_t transaction_id;
    transaction_type_t type;
    float amount;
} transaction_t;
void record_transaction(account_t *acc, transaction_type_t type, float amount);

#endif  // TRANSACTION_H