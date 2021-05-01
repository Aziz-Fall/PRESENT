#include "decryption.h"
#include "encryption.h"
#include "attack.h"

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
    printf("********************************************************\n");
    printf("** First key pair ... \n\n");
    reset();
    data_attack *attack1 = init_data_attack(m1, c1);
    key_pair k1_2 = attacks(attack1);
    display_key_pair(k1_2, attack1);

    green();
    printf("** Second key pair ...\n\n");
    reset();
    data_attack *attack2 = init_data_attack(m2, c2);
    key_pair k = attacks(attack2);
    display_key_pair(k, attack2);

    green();
    printf("********************************************************\n");
    reset();

    free_data_attack(attack1);
    free_data_attack(attack2);
    return 0;
}
