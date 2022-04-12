// htab_for_each.c
   // Řešení IJC-DU2, příklad B), 11.4.2022
   // Autor: Tereza Kubincova, FIT
   // Přeloženo: gcc 9.3.0
   // na kazdu polozku tabulky aplikuje funkciu danu parametrom f

#include "htab.h"
#include "struct_htab.h"


void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data))
{
    for (size_t i = 0; i < t->arr_size; i++)
    {
        htab_item_t *head = t->arr_ptr[i];
        while (head != NULL)
        {
            f(&head->item);
            head = head->next;
        }
    }
}