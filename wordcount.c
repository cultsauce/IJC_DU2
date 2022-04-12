// wordcount.c
   // Řešení IJC-DU2, příklad B), 11.4.2022
   // Autor: Tereza Kubincova, FIT
   // Přeloženo: gcc 9.3.0
   // nacita slova zo standardneho vstupu a vypise ich + pocet vyskytov

#include "htab.h"
#include "io.c"

#define MAX_WORD_LEN 127

void print_htab_pair(htab_pair_t *pair)
{
    printf("%s\t%d\n", pair->key, pair->value);
}

int main()
{
    htab_t * tab = htab_init(100);
    char word[MAX_WORD_LEN + 1];
    while (read_word(word, MAX_WORD_LEN, stdin) != EOF)
    {
        htab_pair_t *item = htab_lookup_add(tab, word);
        if (item == NULL) fprintf(stderr, "nepodarilo se pridat slovo\n");
    }
    htab_for_each(tab, print_htab_pair);
    htab_free(tab);
}