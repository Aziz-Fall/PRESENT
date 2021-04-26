#ifndef DECRYPTION_H
#define DECRYPTION_H

#include <stdint.h>

/**
 * @brief calculate the reverse permutation 
 * of the state.
 * @param state a variable of 24 bits
 * @return uint32_t reverse permutation
 */
uint32_t reverse_permutation(uint32_t state);

/**
 * @brief calculate the reverse substitution
 * of the state 
 * @param state a variable of 24 bits.
 * @return uint32_t reverse substitution
 */
uint32_t reverse_substitution(uint32_t state);

#endif