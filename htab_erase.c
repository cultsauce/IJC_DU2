// htab_erase.c
   // Řešení IJC-DU2, příklad B), 11.4.2022
   // Autor: Tereza Kubincova, FIT
   // Přeloženo: gcc 9.3.0
   // vymaze polozku s hodnotou "key" z hashovacej tabulky

#include "htab.h"
#include "struct_htab.h"


bool htab_erase(htab_t * t, htab_key_t key)
{
    size_t hash = htab_hash_function(key) % t->arr_size;

    htab_item_t *head = t->arr_ptr[hash];

    if (head == NULL) return false;
    else if (strcmp(head->item.key, key) == 0)
    {
        t->arr_ptr[hash] = head->next;
        free((void *)head->item.key);
        free(head);

        t->size--;
        return true;
    }
    else 
    {
        htab_item_t *delete = NULL;
        while (head->next != NULL)
        {
            if (strcmp(head->next->item.key, key) == 0)
            {
                delete = head->next;
                head->next = head->next->next;
                free((void *)delete->item.key);
                free(delete);

                t->size--;
                return true;
            }
            head = head->next;
        }
    }

    if (t->size / t->arr_size < AVG_LEN_MIN)
    {
        htab_resize(t, t->arr_size / 2);
    }

    return false;
}
