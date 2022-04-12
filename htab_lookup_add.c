// htab_lookup_add.c
   // Řešení IJC-DU2, příklad B), 11.4.2022
   // Autor: Tereza Kubincova, FIT
   // Přeloženo: gcc 9.3.0
   // hlada polozku s hodnotou "key" v tabulke
   // ak sa polozka v tabulke nenachadza, vlozi ju tam

#include "htab.h"
#include "struct_htab.h"


htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key)
{
    htab_pair_t *tmp = htab_find(t, key);

    if (tmp != NULL) 
    {
        tmp->value++;
        return tmp;
    }

    // if the new table size is greater, than the allowed average, resize it to twice its current size
    if ((t->size + 1) / t->arr_size > AVG_LEN_MAX)
    {
        htab_resize(t, 2 * t->arr_size);
    }
    
    //  dynamically allocate a new node
    htab_item_t *new = malloc(sizeof(htab_item_t));
    if (new == NULL)
    {
        return NULL;
    }
    new->item.key = malloc((strlen(key) + 1) * sizeof(char));
    if (new->item.key == NULL)
    {
        return NULL;
    }
    strcpy((char * restrict)new->item.key, key);
    new->next = NULL;
    new->item.value = 1;

    // insert into the table
    size_t hash = htab_hash_function(key) % t->arr_size;
    new->next = t->arr_ptr[hash];
    t->arr_ptr[hash] = new;

    t->size++;
    return &new->item;
}