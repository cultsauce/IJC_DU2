// struct_htab.h
   // Řešení IJC-DU2, příklad B), 11.4.2022
   // Autor: Tereza Kubincova, FIT
   // Přeloženo: gcc 9.3.0
   // deklaracie privatnych struktur v hashovacej tabulke

#include "htab.h"

#ifndef STRUCT_HTAB_H
#define STRUCT_HTAB_H

typedef struct htab_item
{
    htab_pair_t item;
    struct htab_item *next;
} htab_item_t;

struct htab
{
    size_t size;
    size_t arr_size;
    htab_item_t **arr_ptr;   
};

#endif /*STRUCT_HTAB_H*/
