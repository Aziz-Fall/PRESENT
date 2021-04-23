#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tab[16] = { 0x1,    0x2,    0x4,    0x8, 
                    0x10,   0x20,   0x40,   0x80,
                    0x100,  0x200,  0x400,  0x800,
                    0x1000, 0x2000, 0x4000, 0x8000
                  };
    int s[16] = {
                 0xc, 0x5, 0x6, 0xb,
                 0x9, 0x0, 0xa, 0xd,
                 0x3, 0xe, 0xf, 0x8,
                 0x4, 0x7, 0x1, 0x2
                };

    unsigned int p = 0;
    int b = 5337;

    // s: substitution
    for( int i = 0; i < 16; i++){
        int c = (b & tab[i]) >> i;
        p = p | (c << s[i]);
        printf("tab[%d] = %d, %u\n", i, tab[i], tab[i] );
    }
    // s-1: reciproque de s
    printf(" p = %d \n", p);
    int d = 0;
    for( int i = 0; i < 16; i++){
        int c = (p & tab[s[i]]) >> s[i];
        d = d | (c << i); 
    }

    printf(" d = %d \n", d);

    return 0;

}