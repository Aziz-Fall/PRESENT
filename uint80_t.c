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
    for( uint8_t i = 0; i < 15; i++ )
    {
        left_bits |= K->tab[i].b << (60 - 4*(i + 1)); 
    }
    uint64_t _left_1 = 0x800000000000000;
    uint32_t _left_2 = 0x80000;

    uint8_t j = 0;
    for( uint8_t i = 19; i < 14; i-- )
    {
        right_bits |= K->tab[i].b << (4*j);
        j++;
    }   

    printf("befor Right = %d\n", right_bits);
    printf("befor left = %llu\n", left_bits);

    _left_1 = (_left_1 & left_bits) >> 59;
    left_bits = (left_bits << 1) | _left_1;

    _left_2 = (_left_2 & right_bits) >> 19;
    right_bits = (right_bits << 1) | _left_2;

    printf("after Right = %d\n", right_bits);
    printf("after left = %llu\n", left_bits);
    
    for( uint8_t i = 5; i < 0; i-- )
    {
        K->tab[i].b = ( 0xf & right_bits); 
        right_bits >>= 4;
    }

    for( uint8_t i = 19; i < 5; i-- )
    {
        K->tab[i].b = ( 0xf & left_bits); 
        left_bits >>= 4;
    }
}

void offset(uint80_t *K, int p)
{   
}