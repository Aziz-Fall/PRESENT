#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <stdio.h>
#include <stdlib.h>
#include "const.h"
#include "main_key.h"

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

/**
 * @brief Encrypt the message m using the key 
 * 
 * @param key master key
 * @param m message
 * @return uint32_t message encrypted 
 */
uint32_t encrypt(uint32_t m, uint32_t key);

#endif
