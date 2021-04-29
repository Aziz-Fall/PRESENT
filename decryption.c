#include "decryption.h"
#include "const.h"

uint32_t reverse_permutation(uint32_t state)
{
    uint32_t reverse_state = 0;
    for( uint8_t i = 0; i < 24; i++){
        int c = (state & POS[i]) >> i;
        reverse_state |= (c << REV_PERM[i]); 
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

uint32_t decrypt(uint32_t c, uint32_t key)
{   
    main_key *K = init_key(key);

    uint32_t state = c;
    state ^= K->sub_key[11];
    for( int i = 10; i > 0; i--)
    {
        state = reverse_permutation(state);
        state = reverse_substitution(state);
        state ^= K->sub_key[i];
    }

    free(K);

    return state;
}