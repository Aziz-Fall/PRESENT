#include "decryption.h"
#include "encryption.h"

int main(int argc, char const *argv[])
{
    uint80_t *key = init();
    init_key(0xf34ab7, key);
    printf(" _________ Before rotation _________\n");
    print_key(*key);
    rotate_bits(key);
    printf(" _________ 1 in rotation _________\n");
    print_key(*key);
    rotate_bits(key);
    printf(" _________ 2 in rotation _________\n");
    print_key(*key);
    rotate_bits(key);
    printf(" _________ 3 in rotation _________\n");
    print_key(*key);
    rotate_bits(key);
    printf(" _________ 4 in rotation _________\n");
    print_key(*key);
    rotate_bits(key);
    printf(" _________ 5 in rotation _________\n");
    print_key(*key);
    rotate_bits(key);
    printf(" _________ 6 in rotation _________\n");
    print_key(*key);

    uint32_t a = boxS(2); 
    printf("a not reverse: %d.\n", a);
    a = reverse_substitution(a);
    printf("reverse a: %d\n", a);

    free(key);
    return 0;
}
