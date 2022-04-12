// htab_bucket_count.c
   // Řešení IJC-DU2, příklad B), 11.4.2022
   // Autor: Tereza Kubincova, FIT
   // Přeloženo: gcc 9.3.0
   // funkcia vracia velkost pola hashovacej tabulky

#include "htab.h"
#include "struct_htab.h"


size_t htab_bucket_count(const htab_t * t)
{
    if (t != NULL)
        return t->arr_size;
    else return 0;
}