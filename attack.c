#include "attack.h"
#include "decryption.h"
#include "encryption.h"
#include <time.h>
#include <stdbool.h>

void red() 
{
  printf("\033[1;31m");
}

void green()
{
  printf("\033[0;32m");
}

void blue()
{
  printf("\033[0;34m");
}

void reset() 
{
  printf("\033[0m");
}

void fusion(uint32_t tab[], int begin, int middle, int end)
{
    int n1 = middle - begin + 1;
    int n2 = end - middle;

    uint32_t *left = malloc(sizeof(uint32_t) * n1),
    *right = malloc(sizeof(uint32_t) * n2);

    for (int i = 0; i < n1; i++)
    left[i] = tab[begin + i];

    for (int j = 0; j < n2; j++)
    right[j] = tab[middle + 1 + j];
    
    int i, j, k;
    i = 0;
    j = 0;
    k = begin;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            tab[k] = left[i];
            i++;
        }
        else
        {
            tab[k] = right[j];
            j++;
        }
        k++;
    }   
    while (i < n1)
    {
        tab[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        tab[k] = right[j];
        j++;
        k++;
    }

    free(right);
    free(left);
}
    
void triFusion(uint32_t tab[], int begin, int end)
{
    if (begin < end)
    {
        int m = (begin + end) / 2;
        triFusion(tab, begin, m);
        triFusion(tab, m + 1, end);
        fusion(tab, begin, m, end);
    }
}

data_attack *init_data_attack(uint32_t m, uint32_t e)
{
    data_attack *attack = malloc(sizeof(data_attack));
    if( !attack )
    {
        printf("Failure  allocation Attack :(\n");
        exit(2);
    }

    attack->m = m;
    attack->e = e;
    attack->decrypt_e = NULL;
    attack->encrypt_m = NULL;

    attack->decrypt_e = malloc(sizeof(int) * 0xffffff);
    if( !attack->decrypt_e )
    {
        printf("Failure  allocation DECRYPT :(\n");
        exit(2);
    }

    attack->encrypt_m = malloc(sizeof(int) * 0xffffff);
    if( !attack->encrypt_m )
    {
        printf("Failure allocation ENCRYPT :(\n");
        exit(2);
    }

    for( int i = 0; i < 0xffffff; i++ )
    {
        attack->encrypt_m[i] = 0;
        attack->decrypt_e[i] = 0;
    }

    return attack;
}

uint32_t search(uint32_t tab[], uint32_t c)
{
    for( uint32_t i = 0; i < 0xffffff; i++)
    {
        if( c == tab[i])
            return i;
    }

    return -1;
} 

key_pair attacks(data_attack *attack)
{
    time_t begin, end;
    key_pair k1_2;
    begin = time(NULL);
    for( uint32_t i = 0x0; i < 0xffffff; i++ )
    {
        attack->encrypt_m[i] = encrypt(attack->m, i);
        attack->decrypt_e[i] = decrypt(attack->e, i);
    }

    k1_2 = get_key_pair(attack);

    end = time(NULL);

    unsigned long secondes = (unsigned long) difftime( end, begin );
    k1_2.times = secondes;
    
    return k1_2;
}

void free_data_attack(data_attack *attack)
{
    free(attack->decrypt_e);
    free(attack->encrypt_m);
    free(attack);
}

/**
 * @brief search a corresponding key in the array tab.
 * the algrithme used, searches the key in half of the 
 * array each round.So it do log(n) round to search a key.
 * 
 * @param tab array 
 * @param c encrypted message
 * @param begin begin array
 * @param end end array
 * @return uint32_t result
 */
uint32_t search_key(uint32_t tab[], uint32_t c, uint32_t begin, uint32_t end)
{
    uint32_t middle = (begin + end) / 2;

    if( middle == 0 && tab[middle] != c) return -1;
    else if(tab[middle] == c ) return middle;
    else if ( c > tab[middle] && c < tab[end]) return -1;
    else if ( c > tab[middle] && c > tab[end]) return -1;
    else if ( c > tab[middle] ) return search_key(tab, c, middle, end);
    else if ( c <= tab[middle] ) return search_key(tab, c, begin, middle);
    
    return -1;
}

key_pair get_key_pair(data_attack *attack)
{
    key_pair k1_2;
    k1_2.k1 = -1;
    k1_2.k2 = -1;
    for( uint32_t i = 0; i < 0xffffff; i++ )
    {
        uint32_t result = 0;
        result = search(attack->decrypt_e, attack->encrypt_m[i]);
        if( result != -1 )
        {
            k1_2.k1 = i;
            k1_2.k2 = result;
            return k1_2;
        }
    }

    return k1_2;
}

void display_key_pair(key_pair k, data_attack *a)
{
    printf("(");
    blue();
    printf("m");
    reset();
    printf(", ");
    red();
    printf("k1");
    reset();
    printf(")-(");
    blue();
    printf("%6x", a->m);
    reset();
    printf(", ");
    red();
    printf("%6x", k.k1);
    reset();
    printf(" ) | (");
    blue();
    printf("c");
    reset();
    printf(", ");
    red();
    printf("k2");
    reset();
    printf(")-(");
    blue();
    printf("%6x", a->e);
    reset();
    printf(", ");
    red();
    printf("%6x)\n\n", k.k2);
    reset();
    green();
    printf( "Execution time to find the keys: %u sec\n\n", k.times); 
    reset();
}