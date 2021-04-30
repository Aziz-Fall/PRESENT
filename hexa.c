#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

int main(int argc, char const *argv[])
{
    printf("argc: %d\n", argc);
    
    for( int i = 1; i < argc; i++)
    {
        printf("hexa[%d]: %s, %6x\n", i, argv[i], (uint32_t)strtol(argv[i], NULL, 16));
    }

    free(hexa);
    return 0;
}
