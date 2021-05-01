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
        attack->decrypt_e[i] = -1;
    }

    return attack;
} 

key_pair attacks(data_attack *attack)
{
    time_t begin, end;
    key_pair k1_2;
    begin = time(NULL);
    for( uint32_t i = 0x0; i < 0xffffff; i++ )
    {
        // if( i % 100 == 0)
        //     printf("i: %d\n", i);
        attack->encrypt_m[i] = encrypt(attack->m, i);
        attack->decrypt_e[decrypt(attack->e, i)] = i;
        uint32_t result = attack->decrypt_e[attack->encrypt_m[i]];
        if( result != -1 )
        {
            k1_2.k1 = i;
            k1_2.k2 = result;
            break;
        }

    }

    end = time(NULL);

    double secondes = difftime( end, begin );
    k1_2.times = secondes;
    
    return k1_2;
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
    k1_2.k1 = -1;
    k1_2.k2 = -1;
    for( uint32_t i = 0; i < 0xffffff; i++ )
    {
        uint32_t result = 0;
        result = attack->decrypt_e[attack->encrypt_m[i]];
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
    printf( "Execution time to find the keys: %f sec\n\n", k.times); 
    reset();
}