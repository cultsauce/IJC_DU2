// io.c
   // Řešení IJC-DU2, příklad B), 11.4.2022
   // Autor: Tereza Kubincova, FIT
   // Přeloženo: gcc 9.3.0
   // nacita slovo zo suboru daneho paraetrom f s maximalnou dlzkou max a ulozi ho do s

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int read_word(char *s, int max, FILE *f)
{
    if (f == NULL) return -1;

    int c, idx = 0, in_word = 0;
    s[0] = '\0';
    while ((c = fgetc(f)) != EOF)
    {
        // end of current word
        if (isspace(c) && in_word)
        {
            return idx;
        }
        // the current word hasnt started
        else if (isspace(c)) continue;
        
        // start of word, start saving characters
        else
        {
            in_word = 1;
            s[idx] = c;
            s[++idx] = '\0';
            if (idx >= max - 1)
            {
                fprintf(stderr, "prekrocena maximalni delka slova\n");

                // discard the rest of the current word
                while ((c = fgetc(f)) != EOF)
                {
                    if (isspace(c)) break;
                }
                return idx;
            }
        }
    }
    return EOF;
}
