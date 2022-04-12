// htab_free.c
   // Řešení IJC-DU2, příklad B), 11.4.2022
   // Autor: Tereza Kubincova, FIT
   // Přeloženo: gcc 9.3.0
   // uvolni vsetku dynamicku pamat alokovanu hashovacej tabulke

#include "htab.h"
#include "struct_htab.h"


void htab_free(htab_t * t)
{
    htab_clear(t);
    free(t->arr_ptr);
    free(t);
}