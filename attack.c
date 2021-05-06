#include "attack.h"
#include "decryption.h"
#include "encryption.h"
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

data_attack *init_data_attack(uint32_t m1, uint32_t e1, uint32_t m2, uint32_t e2)
{
    data_attack *attack = malloc(sizeof(data_attack));
    if( !attack )
    {
        printf("Failure  allocation Attack :(\n");
        exit(2);
    }

    attack->m1 = m1;
    attack->e1 = e1;
    attack->decrypt_e1 = NULL;
    attack->encrypt_m1 = NULL;
    attack->m2 = m2;
    attack->e2 = e2;
    attack->decrypt_e2 = NULL;
    attack->encrypt_m2 = NULL;

    attack->decrypt_e1 = malloc(sizeof(int) * 0xffffff);
    if( !attack->decrypt_e1 )
    {
        printf("Failure  allocation DECRYPT :(\n");
        exit(2);
    }

    attack->encrypt_m1 = malloc(sizeof(int) * 0xffffff);
    if( !attack->encrypt_m1 )
    {
        printf("Failure allocation ENCRYPT :(\n");
        exit(2);
    }
    attack->decrypt_e2 = malloc(sizeof(int) * 0xffffff);
    if( !attack->decrypt_e2 )
    {
        printf("Failure  allocation DECRYPT :(\n");
        exit(2);
    }

    attack->encrypt_m2 = malloc(sizeof(int) * 0xffffff);
    if( !attack->encrypt_m2 )
    {
        printf("Failure allocation ENCRYPT :(\n");
        exit(2);
    }
  
    for( uint32_t i = 0x0; i <0xffffff; i++ )
    {
        main_key *K = init_key(i);

        attack->encrypt_m1[i] = encrypt(attack->m1, K->sub_key);
        attack->encrypt_m2[i] = encrypt(attack->m2, K->sub_key);
        
        attack->decrypt_e1[decrypt(attack->e1, K->sub_key)] = i; 
        attack->decrypt_e2[decrypt(attack->e2, K->sub_key)] = i; 
       
        free(K);
    }

    return attack;
} 

key_pair attacks(data_attack *attack)
{
    key_pair k1_2;
    for( uint32_t i = 0x0; i < 0xffffff; i++ )
    {
        uint32_t r1 = attack->decrypt_e1[attack->encrypt_m1[i]];
        uint32_t r2 = attack->decrypt_e2[attack->encrypt_m2[i]];
        if( r2 == r1 )
        {   
            if( check_key(i, r1, attack) )
            {    
                k1_2.k1 = i;
                k1_2.k2 = r1;
                printf(" (k1, k2) -- (%6x, %6x)\n", i, r1);
            }
        }
    }

    return k1_2;
}

bool check_key(uint32_t k_1, uint32_t k_2, data_attack *a)
{   
    main_key *k1 = init_key(k_1);
    main_key *k2 = init_key(k_2);

    uint32_t c1 = encrypt(a->m1, k1->sub_key);
    uint32_t c2 = encrypt(c1, k2->sub_key);
    uint32_t c3 = encrypt(a->m2, k1->sub_key);
    uint32_t c4 = encrypt(c3, k2->sub_key);
    free(k1);
    free(k2);
    return ( c2 == a->e1 && c4 == a->e2 ) ? true : false;
}
void free_data_attack(data_attack *attack)
{
    free(attack->decrypt_e1);
    free(attack->encrypt_m1);
    free(attack->decrypt_e2);
    free(attack->encrypt_m2);
    free(attack);
}

void display_key_pair(key_pair k, data_attack *a)
{
    printf("(");
    blue();
    printf("m1");
    reset();
    printf(", ");
    red();
    printf("k1");
    reset();
    printf(")-(");
    blue();
    printf("%6x", a->m1);
    reset();
    printf(", ");
    red();
    printf("%6x", k.k1);
    reset();
    printf(" ) | (");
    blue();
    printf("c1");
    reset();
    printf(", ");
    red();
    printf("k2");
    reset();
    printf(")-(");
    blue();
    printf("%6x", a->e1);
    reset();
    printf(", ");
    red();
    printf("%6x)\n\n", k.k2);
    reset();
    printf("(");
    blue();
    printf("m2");
    reset();
    printf(", ");
    red();
    printf("k1");
    reset();
    printf(")-(");
    blue();
    printf("%6x", a->m2);
    reset();
    printf(", ");
    red();
    printf("%6x", k.k1);
    reset();
    printf(" ) | (");
    blue();
    printf("c2");
    reset();
    printf(", ");
    red();
    printf("k2");
    reset();
    printf(")-(");
    blue();
    printf("%6x", a->e2);
    reset();
    printf(", ");
    red();
    printf("%6x)\n\n", k.k2);
    reset();
}