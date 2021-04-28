#include "decryption.h"
#include "encryption.h"

int main(int argc, char const *argv[])
{
    printf("------------------------------------------\n");
    printf(" encrypt m: %6x, k: %6x, c: %6x\n", 0x000000, 0x000000, encrypt(0x000000, 0x000000));
    printf(" encrypt m: %6x, k: %6x, c: %6x\n", 0xffffff, 0x000000, encrypt(0xffffff, 0x000000));
    printf(" encrypt m: %6x, k: %6x, c: %6x\n", 0x000000, 0xffffff, encrypt(0x000000, 0xffffff));
    printf(" encrypt m: %6x, k: %6x, c: %6x\n", 0xf955b9, 0xd1bd2d, encrypt(0xf955b9, 0xd1bd2d));
    printf("------------------------------------------\n");
    // 
    return 0;
}
