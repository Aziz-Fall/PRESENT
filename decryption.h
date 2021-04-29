#ifndef DECRYPTION_H
#define DECRYPTION_H

#include <stdint.h>
#include "main_key.h"
#include "const.h"

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


/**
 * @brief decrypt an encrypted message c
 * 
 * @param c encrypted message
 * @param subs_key subs_key
 * @return uint32_t message decrypted
 */
uint32_t decrypt(uint32_t c, uint32_t subs_key[]);

#endif