#include "decryption.h"
#include "encryption.h"
#include "attack.h"
/**
 * (m1,c1) = (8a5c19, 7cc9ee) 
 * (m2,c2) = (cfdbd2,cc89f3)
 * 
 * dc415c, f914c6
 */


int main(int argc, char const *argv[])
{
    if( argc > 5 || argc < 5)
    {
        perror("Less arguments :( please put 4 arguments \n");
        exit(1);
    }

    uint32_t m1 = strtol(argv[1], NULL, 16);
    uint32_t c1 = strtol(argv[2], NULL, 16);
    uint32_t m2 = strtol(argv[3], NULL, 16);
    uint32_t c2 = strtol(argv[4], NULL, 16);

    green();
    printf("**********************************************************\n");
    printf("                   ------------------                 \n");
    printf("   ---------------|   KEYS FOUNDED   |------------------\n");
    printf("                   ------------------                 \n");
    printf("* First key pair ... \n\n");
    reset();
    data_attack *attack1 = init_data_attack(m1, c1);
    key_pair k1_2 = attacks(attack1);
    display_key_pair(k1_2, attack1);

    green();
    printf("* Second key pair ...\n\n");
    reset();
    data_attack *attack2 = init_data_attack(m2, c2);
    key_pair k = attacks(attack2);
    display_key_pair(k, attack2);

    green();
    printf("                   ------------------                 \n");
    printf("   ---------------|   CKECKING KEYS  |-----------------\n");
    printf("                   ------------------                 \n\n");
    reset();
    c1 = encrypt(m1, k1_2.k1);
    c2 = encrypt(c1, k1_2.k2);
    uint32_t c3 = encrypt(m2, k.k1);
    uint32_t c4 = encrypt(c3, k.k2);

    printf(" encrypt      \033[0;34m m1\033[0m:\033[0;34m %6x\033[0m, k1: %6x, c': %6x\n", m1, k1_2.k1, c1);
    printf(" encrypt (m = c'): %6x, k2: %6x,\033[0;34m c1\033[0m: \033[0;34m%6x\033[0m\n\n", c1, k1_2.k2, c2);
    printf(" encrypt      \033[0;34m m2\033[0m: \033[0;34m%6x\033[0m, k1: %6x, c': %6x\n", m2, k.k1, c3);
    printf(" encrypt (m = c'): %6x, k2: %6x,\033[0;34m c2\033[0m: \033[0;34m%6x\033[0m\n\n", c3, k.k2, c4);
    green();
    printf("********************************************************\033[0;32m\n");
    reset();

    free_data_attack(attack1);
    free_data_attack(attack2);
    return 0;
}
