#include "decryption.h"
#include "encryption.h"

int main(int argc, char const *argv[])
{
    uint80_t *key = init();
    init_key(0x0, key);
    printf(" _________ Sub Keys of 000000 _________\n");
    //print_key(*key);
    for( int i = 0; i < 11; i++)
    {
        updateKey(key, i);
        printf("key[%d] = %x \n", i, get_sub_key(key));
    }
    printf("------------------------------------------\n");
    // printf(" _________ 1 in rotation _________\n");

    // rotate_bits(key);
    // print_key(*key);
    // updateKey(key, 1);

    // printf(" _________ 2 in rotation _________\n");

    // rotate_bits(key);
    // print_key(*key);
    // updateKey(key, 2);

    // printf(" _________ 3 in rotation _________\n");

    // rotate_bits(key);
    // print_key(*key);
    // updateKey(key, 3);
    // rotate_bits(key);
    // printf(" _________ 4 in rotation _________\n");
    // print_key(*key);
    // rotate_bits(key);
    // printf(" _________ 5 in rotation _________\n");
    // print_key(*key);
    // rotate_bits(key);
    // printf(" _________ 6 in rotation _________\n");
    // print_key(*key);

    uint32_t a = boxS(2); 
    printf("a not reverse: %d.\n", a);
    a = reverse_substitution(a);
    printf("reverse a: %d\n", a);

    free(key);
    return 0;
}
