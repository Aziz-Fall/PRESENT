#include "attack.h"
#include "decryption.h"
#include "encryption.h"
#include <time.h>

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