#include "decryption.h"
#include "encryption.h"

int main(int argc, char const *argv[])
{
    uint80_t *key = init();
    init_key(0xf34ab7, key);
    print_key(*key);
    rotate_bits(key);
    print_key(*key);

    uint32_t a = boxS(2); 
    printf("a not reverse: %d.\n", a);
    a = reverse_substitution(a);
    printf("reverse a: %d\n", a);

    free(key);
    return 0;
}
