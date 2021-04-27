#include "uint80_t.h"
#include "const.h"
#include <stdlib.h>
#include <errno.h>

uint80_t *init()
{
    uint80_t *key = malloc(sizeof(uint80_t));

    if( !key )
    {
        perror("Echec allocation :(\n");
        exit(1);
    }

    return key;
}

void print_key(uint80_t int80)
{
    for( uint8_t i = 0; i < 20; i++)
    {
        printf("tab[%d] = %d\n", i, int80.tab[i].b);
    }
}

void init_key(uint32_t K, uint80_t *int80)
{
    for( uint8_t i = 0; i < 20; i++ )
    {
        if( i < 6 )
        {
            uint4_t u;
            int80->tab[i].b = (WORDS[5 - i] & K) >> ((5 - i) * 4);;        }
        else 
        {
            int80->tab[i].b = 0x0;
        }
    }
}

void rotate_bits(uint80_t *K)
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
    left_bits <<= 4;
    left_bits >>= 4;

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
  0    1    2    3   4
0000 0000 0000 0000 0001

  5    6    7    8   9    10   11   12   13   14   15   16   17   18   19
1110 0110 1001 0101 0110 1110 0000 0000 0000 0000 0000 0000 0000 0000 0000
 14   6    9    5    6    14
1110 0110 1001 0101 0110 1110

******** 2 ième tours ************

  0    1    2    3   4
0000 0000 0000 0000 0001
  5    6    7    8   9    10   11   12   13   14   15   16   17   18   19
1110 0110 1001 0101 0110 1110 0000 0000 0000 0000 0000 0000 0000 0000 0000

   0    1    2    3   4       5    6    7    8   9    10   11   12   13   14   15   16   17   18   19
 0000 0000 0000 0000 0000 - 0000 0000 0000 0000 0011 1100 1101 0010 1010 1101 1100 0000 0000 0000 0000
                                                 3    12   13   2    10   13   12   

******** 3 ième tours ************

  0    1    2    3   4        5    6    7    8   9    10   11   12   13   14   15   16   17   18   19
1000 0000 0000 0000 0000 -  0000 0000 0000 0000 0000 0000 0000 0000 0000 0111 1001 1010 0101 0101 1011
  8                                                                       7    9    10    5   5    11
******** 3 ième tours ************
  0    1    2    3   4       5    6    7    8   9    10   11   12   13   14   15   16   17   18   19
0011 0100 1010 1011 0111 - 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 1111
  3   4    10   11   7                                                                            15

******** 4 ième tours ************
  0    1    2    3   4       5    6    7    8   9    10   11   12   13   14   15   16   17   18   19
0000 0000 0000 0001 1110 - 0110 1001 0101 0110 1110 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000
                1   14      6    9    5    6    14
 
******** 5 ième tours ************
  0    1    2    3   4       5    6    7    8   9    10   11   12   13   14   15   16   17   18   19
0000 0000 0000 0000 0000 - 0000 0000 0000 0011 1100 1101 0010 1010 1101 1100 0000 0000 0000 0000 0000
                                            3   12   13    2   10  13    12
initiale
1111 0011 0100 1010 1011 0111

1111 0011 0100 1010 1011 0111 0000
*/

void offset(uint80_t *K, int p)
{   
}