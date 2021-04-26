#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief boxS do substitution of bits
 * 
 * @param state is variable of 24 bits
 * @return uint32_t a variable substituted.
 */
uint32_t boxS(uint32_t state);

/**
 * @brief permute the bits of the state
 * 
 * @param state is variable of 24 bits
 * @return uint32_t variable permuted.
 */
uint32_t permute(uint32_t state);

#endif
