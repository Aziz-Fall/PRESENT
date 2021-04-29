#include "main_key.h"
#include "const.h"
#include <stdlib.h>
#include <errno.h>

/**
 * @brief Get the sub key of the master key
 * 
 * @param K master key
 * @return uint32_t sub key
 */
uint32_t get_sub_key(main_key *K)
{
    uint32_t sub_key = 0;
    for( int i = 10; i < 16; i++)
    {
        sub_key |= K->tab[i].b;
        sub_key <<= 4; 
    }

    return (sub_key >> 4);
}

void init_sub_key(main_key *K)
{
  for( int i = 1; i < 12; i++ )
  {
    K->sub_key[i] = get_sub_key(K);
    updateKey(K, i);
  }
}

main_key *init_key(uint32_t K)
{
    main_key *key = malloc(sizeof(main_key));

    if( !key )
    {
        perror("Echec allocation :(\n");
        exit(1);
    }

    for( uint8_t i = 0; i < 20; i++ )
    {
        if( i < 6 )
        {
            key->tab[i].b = (WORDS[5 - i] & K) >> ((5 - i) * 4);;        }
        else 
        {
            key->tab[i].b = 0x0;
        }
        if( i < 12)
        {
          key->sub_key[i] = 0x0;
        }
    }

    init_sub_key(key);

    return key;
}

void print_key(main_key int80)
{
    for( uint8_t i = 0; i < 20; i++)
    {
        printf("tab[%d] = %d\n", i, int80.tab[i].b);
    }
}


void updateKey(main_key *K, int i)
{
    rotate_bits(K);
    // substitution.
    K->tab[0].b = SUBS[K->tab[0].b];

    int bit_substitution = 0x0;
    bit_substitution |= (K->tab[15].b << 1);
    bit_substitution |= (0x8 & K->tab[16].b) >> 3;

    bit_substitution ^=  i;
    int k_15 = (bit_substitution & 0x1);
    k_15 <<= 3;
    bit_substitution >>= 1;
    K->tab[15].b = bit_substitution & 0xf;
    K->tab[16].b = (K->tab[16].b & 0x7) | k_15;
    
}


void rotate_bits(main_key *K)
{
    uint64_t left_bits = 0;
    uint32_t right_bits = 0;
    for( int i = 0; i < 15; i++ )
    {
        left_bits |= K->tab[i].b;
        left_bits <<= 4;
    }

    // Use 60 bits
    left_bits >>= 4;

    uint64_t _left = 0x800000000000000;
    uint32_t _right = 0x80000;

    for( int i = 15; i < 20; i++ )
    { 
        right_bits |= K->tab[i].b;
        right_bits <<= 4;
    }   

    // Use 20 bits
    right_bits >>= 4;
    
    _left = (_left & left_bits) >> 59;
    _right = (_right & right_bits) >> 19;

    left_bits = (left_bits << 1) | _right;
    right_bits = (right_bits << 1) | _left;

    // Use 60 bits
    // left_bits <<= 4;
    // left_bits >>= 4;

    for( int i = 4; i >= 0; i-- )
    {
        K->tab[i].b = ( 0xf & right_bits); 
        right_bits >>= 4;
    }

    for( int i = 19; i > 4; i-- )
    {   
        K->tab[i].b = ( 0xf & left_bits); 
        left_bits >>= 4;
    }
}

/*

******** 0 ième tours ************
  0    1    2    3   4
0000 0000 0000 0000 0001
                     1
  5    6    7    8   9    10   11   12   13   14   15   16   17   18   19
1110 0110 1001 0101 0110 1110 0000 0000 0000 0000 0000 0000 0000 0000 0000
 14   6    9    5    6    14
1110 0110 1001 0101 0110 1110

******** 1 ième tours ************

   0    1    2    3   4       5    6    7    8   9    10   11   12   13   14   15   16   17   18   19
 0000 0000 0000 0000 0000 - 0000 0000 0000 0000 0011 1100 1101 0010 1010 1101 1100 0000 0000 0000 0000
                                                 3    12   13   2    10   13   12   

******** 2 ième tours ************

  0    1    2    3   4        5    6    7    8   9    10   11   12   13   14   15   16   17   18   19
1000 0000 0000 0000 0000 -  0000 0000 0000 0000 0000 0000 0000 0000 0000 0111 1001 1010 0101 0101 1011
  8                                                                       7    9    10    5   5    11
******** 3 ième tours ************

  0    1    2    3   4        5    6    7    8   9    10   11   12   13   14   15   16   17   18   19
0011 0100 1010 1011 0111 -  0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 1111
 3    4    10   11    7                                                                            15


******** 4 ième tours ************
  0    1    2    3   4       5    6    7    8   9    10   11   12   13   14   15   16   17   18   19
0000 0000 0000 0001 1110 - 0110 1001 0101 0110 1110 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000
                1   14      6    9    5    6    14
  0    1    2    3   4       5    6    7    8   9    10   11   12   13   14   15   16   17   18   19
0000 0000 0000 0001 1110 - 0110 1001 0101 0110 1110 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000

******** 5 ième tours ************
  0    1    2    3   4       5    6    7    8   9    10   11   12   13   14   15   16   17   18   19
0000 0000 0000 0000 0000 - 0000 0000 0000 0011 1100 1101 0010 1010 1101 1100 0000 0000 0000 0000 0000
                                            3   12   13    2   10  13    12

******** 6 ième tours ************
  0    1    2    3   4       5    6    7    8   9    10   11   12   13   14   15   16   17   18   19
0000 0000 0000 0000 0000 - 0000 0000 0000 0111 1001 1010 0101 0101 1011 1000 0000 0000 0000 0000 0000
                                            7   9    10   5    5    11   8

000 0000 0000 0000 00000 - 0000 0000 0000 0000 0000 0000 0000 0000 0111 1001 1010 0101 0101 1011 1000

******** 7 ième tours ************

initiale
1111 0011 0100 1010 1011 0111

1111 0011 0100 1010 1011 0111 0000

1 1 0 0 - 1 1 0 1 - 0 0 1 0 - 1 0 1 0 - 1 1 0 1 -    1 1 0 0
                                                   19 18  17  16
*/

void offset(main_key *K, int p)
{   
}