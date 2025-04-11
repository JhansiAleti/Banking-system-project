#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "utils.h"

extern account_t *head;

void save_accounts_to_file(void)
{
    FILE *file_ptr = fopen("accounts.dat", "wb");

    if (file_ptr == NULL)
    {
        printf("Error saving data.\n");
        return;
    }

    account_t *temp = head;
    while (temp != NULL)
    {
        fwrite(temp, sizeof(account_t), 1U, file_ptr);
        temp = temp->next;
    }
    fclose(file_ptr);
}

void load_data_from_file(void)
{
    FILE *file_ptr = fopen(FILE_NAME, "rb");

    if (file_ptr == NULL)
    {
        printf("No previous data found.\n");
        return;
    }

    account_t *new_acc = NULL;
    while ((new_acc = (account_t *)malloc(sizeof(account_t))) != NULL &&
           fread(new_acc, sizeof(account_t), 1U, file_ptr))
    {
        new_acc->next = head;
        head = new_acc;
    }
    fclose(file_ptr);
}
