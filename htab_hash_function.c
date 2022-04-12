// htab_has_function.c
   // Řešení IJC-DU2, příklad B), 11.4.2022
   // Autor: --
   // Přeloženo: gcc 9.3.0
   // generuje hash pre polozku s hodnotou "key"

#include "htab.h"

size_t htab_hash_function(htab_key_t str) 
{
    unsigned int h = 0;     // musí mít 32 bitů
    const unsigned char *p;

    for(p = (const unsigned char*)str; *p != '\0'; p++)
        h = 65599 * h + *p;
        
    return h;
}
