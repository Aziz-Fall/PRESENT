#include "encryption.h"
#include "const.h"

uint32_t boxS(uint32_t state)
{
    uint32_t final_state = 0;
    for( int i = 0; i < 6; i++)
    {
        uint8_t word = (state & WORDS[i]) >> (i * 4);
        //printf(" word[%d] = %d\n", i, word);
        final_state = final_state | ( SUBS[word] << (i * 4));
        //printf("final[%d] = %d\n", i, final_state);
    }
    return final_state;
}

uint32_t permute(uint32_t state)
{
    uint32_t final_state = 0;
    for( int i = 0; i < 24; i++)
    {
        uint8_t bit = (state & POS[i]) >> i; 
        final_state = final_state | (bit << PERM[i]);
    }
    return final_state;
}


