#include "decryption.h"
#include "encryption.h"

int main(int argc, char const *argv[])
{
    uint32_t a = permute(15); 
    printf("a: %d.\n", a);
    a = reverse_permutation(a);
    printf("reverse a: %d\n", a);
    return 0;
}
