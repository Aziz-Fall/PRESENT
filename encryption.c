#include "encryption.h"

uint32_t boxS(uint32_t state)
{
    uint32_t final_state = 0;
    for( int i = 0; i < 6; i++)
    {
        uint8_t word = (state & WORDS[i]) >> (i * 4);
        final_state |= ( SUBS[word] << (i * 4));
    }
    return final_state;
}

uint32_t permute(uint32_t state)
{
    uint32_t final_state = 0;
    for( int i = 0; i < 24; i++)
    {
        uint8_t bit = (state & POS[i]) >> i; 
        final_state |= (bit << PERM[i]);
    }
    return final_state;
}

uint32_t encrypt(uint32_t m, uint32_t sub_key[])
{
    uint32_t state = m;
    for( int i = 1; i < 11; i++)
    {        
        state ^= sub_key[i];
        state = boxS(state);
        state = permute(state);
    }

    state ^= sub_key[11];
    
    return state;
}




