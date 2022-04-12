// htab_init.c
   // Řešení IJC-DU2, příklad B), 11.4.2022
   // Autor: Tereza Kubincova, FIT
   // Přeloženo: gcc 9.3.0
   // vytvori prazdnu hashovaciu tabulku velkosti n

#include "htab.h"
#include "struct_htab.h"


htab_t *htab_init(size_t n)
{
    htab_t *tab = malloc(sizeof(htab_t));
    if (tab == NULL)
    {
        return NULL;
    }

    tab->arr_ptr = malloc(n * sizeof(htab_item_t *));
    if (tab->arr_ptr == NULL)
    {
        return NULL;
    }
    tab->arr_size = n;
    tab->size = 0;
    for (size_t i = 0; i < n; i++)
    {
        tab->arr_ptr[i] = NULL;
    }
    return tab;
}
