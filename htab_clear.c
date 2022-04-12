// htab_clear.c
   // Řešení IJC-DU2, příklad B), 11.4.2022
   // Autor: Tereza Kubincova, FIT
   // Přeloženo: gcc 9.3.0
   // "vycisti" hashovaciu tabulku - zmaze vsetky prvky

#include "htab.h"
#include "struct_htab.h"


void htab_clear(htab_t * t)
{
    for (size_t i = 0; i < t->arr_size; i++)
    {
        htab_item_t *head = t->arr_ptr[i];
        while (head != NULL)
        {
            t->arr_ptr[i] = head->next;
            free((void *)head->item.key);
            free(head);
            head = t->arr_ptr[i];
        }
    }
    t->size = 0;
}