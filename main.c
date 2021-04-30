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
    // printf("------------------------------------------\n");
    // printf("--------------- ENCRYPTION ---------------\n");
    // printf("------------------------------------------\n");
    // uint32_t c1 = encrypt(0x8a5c19, 0x36c8);
    // uint32_t c2 = encrypt(c1, 0x3f967c);
    // uint32_t c3 = encrypt(0x000000, 0xffffff);
    // uint32_t c4 = encrypt(0xf955b9, 0xd1bd2d);
    // printf(" encrypt m: %6x, k: %6x, c: %6x\n", 0x8a5c19, 0x36c8, c1);
    // printf(" encrypt m: %6x, k: %6x, c: %6x\n", c1, 0x3f967c, c2);
    // printf(" encrypt m: %6x, k: %6x, c: %6x\n", 0x000000, 0xffffff, c3);
    // printf(" encrypt m: %6x, k: %6x, c: %6x\n", 0xf955b9, 0xd1bd2d, c4);
    // printf("------------------------------------------\n");
    // printf("--------------- DECRYPTION ---------------\n");
    // printf("------------------------------------------\n");
    // printf(" decrypt c: %6x, k: %6x, d: %6x\n", c1, 0x000000, decrypt(c1, 0x000000));
    // printf(" decrypt c: %6x, k: %6x, d: %6x\n", c2, 0x000000, decrypt(c2, 0x000000));
    // printf(" decrypt c: %6x, k: %6x, d: %6x\n", c3, 0xffffff, decrypt(c3, 0xffffff));
    // printf(" decrypt c: %6x, k: %6x, d: %6x\n", c4, 0xd1bd2d, decrypt(c4, 0xd1bd2d));
    // printf("------------------------------------------\n");

    green();
    printf("**********************************************************\033[0;32m\n");
    printf("------------------      KEYS FOUNDED    ------------------\033[0;32m\n");
    printf("**********************************************************\033[0;32m\n\n");

    printf("* First pair ... \n\n");
    reset();
    data_attack *attack1 = init_data_attack(m1, c1);
    key_pair k1_2 = attacks(attack1);
    display_key_pair(k1_2, attack1);

    green();
    printf("* Second pair ...\n\n");
    reset();
    data_attack *attack2 = init_data_attack(m2, c2);
    k1_2 = attacks(attack2);
    display_key_pair(k1_2, attack2);

    green();
    printf("*********************************************************\033[0;32m\n");
    reset();
    free_data_attack(attack1);
    free_data_attack(attack2);
    return 0;
}
