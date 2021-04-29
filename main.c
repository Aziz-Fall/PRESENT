#include "decryption.h"
#include "encryption.h"
#include "attack.h"

int main(int argc, char const *argv[])
{
    // printf("------------------------------------------\n");
    // printf("--------------- ENCRYPTION ---------------\n");
    // printf("------------------------------------------\n");
    // uint32_t c1 = encrypt(0x000000, 0x000000);
    // uint32_t c2 = encrypt(0xffffff, 0x000000);
    // uint32_t c3 = encrypt(0x000000, 0xffffff);
    // uint32_t c4 = encrypt(0xf955b9, 0xd1bd2d);
    // printf(" encrypt m: %6x, k: %6x, c: %6x\n", 0x000000, 0x000000, c1);
    // printf(" encrypt m: %6x, k: %6x, c: %6x\n", 0xffffff, 0x000000, c2);
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

    data_attack *attack = init_data_attack(0x0, 0x0);

    printf("attack-> m: %d, e: %d\n", attack->m, attack->e);
    generate(attack);
    printf("encrypt[%d]: %6x | decrypt[%d]: %6x\n", 0, attack->encrypt_m[0], 0, attack->decrypt_e[0]);
    printf("encrypt[%d]: %6x | decrypt[%d]: %6x\n", 0x3e8, attack->encrypt_m[0x3e8], 0x3e8, attack->decrypt_e[0x3e8]);
    printf("encrypt[%d]: %6x | decrypt[%d]: %6x\n", 0x186a0, attack->encrypt_m[0x186a0], 0x186a0, attack->decrypt_e[0x186a0]);
    

    free_data_attack(attack);
    return 0;
}
