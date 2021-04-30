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

    data_attack *attack = init_data_attack(0xcfdbd2, 0xcc89f3);
    key_pair k1_2 = attacks(attack);

    display_key_pair(k1_2, attack);

    free_data_attack(attack);
    return 0;
}
