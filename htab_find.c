// htab_find.c
   // Řešení IJC-DU2, příklad B), 11.4.2022
   // Autor: Tereza Kubincova, FIT
   // Přeloženo: gcc 9.3.0
   // hlada polozku s hodnotou "key" v hashovacej tabulky a vracia odkaz na danu polozku
   // v pripade neuspechu vracia NULL

#include "htab.h"
#include "struct_htab.h"

htab_pair_t * htab_find(htab_t * t, htab_key_t key)
{
    size_t hash = htab_hash_function(key) % t->arr_size;

    htab_item_t *head = t->arr_ptr[hash];
    while (head != NULL)
    {
        if (strcmp(head->item.key, key) == 0)
        {
            return &head->item;
        }
        head = head->next;
    }
    return NULL;
}