#include "attack.h"
#include "decryption.h"
#include "encryption.h"
#include <time.h>
#include <stdbool.h>

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


void generate(data_attack *attack)
{
    time_t begin, end;
    begin = time(NULL);
    for( uint32_t i = 0x0; i < 0xffffff; i++ )
    {
        attack->encrypt_m[i] = encrypt(attack->m, i);
        attack->decrypt_e[i] = decrypt(attack->e, i);
    }
    triFusion(attack->decrypt_e, 0, (0xffffff - 1));
    triFusion(attack->encrypt_m, 0, (0xffffff - 1));
    end = time(NULL);
    unsigned long secondes = (unsigned long) difftime( end, begin );
    printf( "Finished in %ld sec\n", secondes ); 
    

}

void free_data_attack(data_attack *attack)
{
    free(attack->decrypt_e);
    free(attack->encrypt_m);
    free(attack);
}

key_pair get_key_pair(data_attack *attack)
{
    key_pair k1_2;
    k1_2.k1 = 0;
    k1_2.k2 = 0;


    return k1_2;
}

int search_key(uint32_t tab[], uint32_t c, uint32_t begin, uint32_t end)
{
    uint32_t middle = (begin + end) / 2;
    if(tab[middle] == c ) return middle;
    else if ( c > tab[middle]) return search_key(tab, c, middle, end);
    else if ( c <= tab[middle]) return search_key(tab, c, begin, middle);

    return -1;
}