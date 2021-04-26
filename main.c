#include "decryption.h"
#include "encryption.h"

int main(int argc, char const *argv[])
{
    uint32_t a = boxS(2); 
    printf("a not reverse: %d.\n", a);
    a = reverse_substitution(a);
    printf("reverse a: %d\n", a);
    return 0;
}
