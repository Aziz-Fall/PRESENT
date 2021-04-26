#include "decryption.h"
#include "const.h"

uint32_t reverse_permutation(uint32_t state)
{
    uint32_t reverse_state = 0;
    for( uint8_t i = 0; i < 24; i++){
        int c = (state & POS[PERM[i]]) >> PERM[i];
         reverse_state |= (c << i); 
    }
    return reverse_state;
}

uint32_t reverse_substitution(uint32_t state)
{
    uint32_t reverse_state = 0;
    for( uint8_t i = 0; i < 6; i++ )
    {
        uint8_t word = (state & WORDS[i]) >> (i * 4);
        reverse_state |= REV_SUBS[word] << (i * 4);
    }
    return reverse_state;
}