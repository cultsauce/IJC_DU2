// htab_size.c
   // Řešení IJC-DU2, příklad B), 11.4.2022
   // Autor: Tereza Kubincova, FIT
   // Přeloženo: gcc 9.3.0
   // vracia pocet poloziek v hashovacej tabulke

#include "htab.h"
#include "struct_htab.h"


size_t htab_size(const htab_t * t)
{
    if (t != NULL)
        return t->size;
    else return 0;
}