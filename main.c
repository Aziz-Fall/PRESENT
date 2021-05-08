#include "decryption.h"
#include "encryption.h"
#include "attack.h"
#include <time.h>

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

    printf("*******************************************\n\n");
    time_t begin, end;

    begin = time(NULL);

    data_attack *attack = init_data_attack(m1, c1, m2, c2);
    attacks(attack);

    end = time(NULL);

    double secondes = difftime( end, begin );

    printf("\n-Time: %.3f sec\n\n", secondes);
    printf("*******************************************\n");
    free_data_attack(attack);
    return 0;
}
