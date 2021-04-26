#include "decryption.h"
#include "const.h"

uint32_t reverse_permutation(uint32_t state)
{
    uint32_t reverse_state = 0;
    for( uint8_t i = 0; i < 16; i++){
        int c = (state & POS[PERM[i]]) >> PERM[i];
         reverse_state |= (c << i); 
    }
    return reverse_state;
}