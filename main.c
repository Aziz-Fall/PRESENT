#include "decryption.h"
#include "encryption.h"

int main(int argc, char const *argv[])
{
    printf("------------------------------------------\n");
    printf("--------------- ENCRYPTION ---------------\n");
    printf("------------------------------------------\n");
    main_key *k1 = init_key(0x000000);
    main_key *k2 = init_key(0x000000);
    main_key *k3 = init_key(0xffffff);
    main_key *k4 = init_key(0xd1bd2d);
    uint32_t c1 = encrypt(0x000000, k1->sub_key);
    uint32_t c2 = encrypt(0xffffff, k2->sub_key);
    uint32_t c3 = encrypt(0x000000, k3->sub_key);
    uint32_t c4 = encrypt(0xf955b9, k4->sub_key);
    printf(" encrypt m: %6x, k: %6x, c: %6x\n", 0x000000, 0x000000, c1);
    printf(" encrypt m: %6x, k: %6x, c: %6x\n", 0xffffff, 0x000000, c2);
    printf(" encrypt m: %6x, k: %6x, c: %6x\n", 0x000000, 0xffffff, c3);
    printf(" encrypt m: %6x, k: %6x, c: %6x\n", 0xf955b9, 0xd1bd2d, c4);
    printf("------------------------------------------\n");
    printf("--------------- DECRYPTION ---------------\n");
    printf("------------------------------------------\n");
    printf(" decrypt c: %6x, k: %6x, d: %6x\n", c1, 0x000000, decrypt(c1, k1->sub_key));
    printf(" decrypt c: %6x, k: %6x, d: %6x\n", c2, 0x000000, decrypt(c2, k2->sub_key));
    printf(" decrypt c: %6x, k: %6x, d: %6x\n", c3, 0xffffff, decrypt(c3, k3->sub_key));
    printf(" decrypt c: %6x, k: %6x, d: %6x\n", c4, 0xd1bd2d, decrypt(c4, k4->sub_key));
    printf("------------------------------------------\n");
    
    return 0;
}
