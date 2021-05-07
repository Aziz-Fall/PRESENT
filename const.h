#ifndef CONST_H
#define CONST_H 

#include <inttypes.h>
#include <stdint.h>

extern const __uint128_t BITS_PIVOTED; 

/**
 * @brief WORDS is an array which contains 
 * a word of 4 bits of one and this bits 
 * are between positions 0 and 3, 4 and 7,
 * ..., 20 and 23.
 */
extern const uint32_t WORDS[6];

/**
 * @brief SUBS is an array of substitution
 * each cage of table contains 
 * corresponding bit position.
 */
extern const uint16_t SUBS[16];

/**
 * @brief REV_SUBS is an array of reverse
 * of substitution each cage contains 
 * conrresponding bit of substited.
 */
extern const uint16_t REV_SUBS[16];

/**
 * @brief PERM is an array of permutation 
 * each cage of table contains the position
 * of the bit to permute.
 */
extern const uint16_t PERM[24];

/**
 * @brief REV_PERM is an array of reverse
 * of permutation each cage of table contains the position
 * of the bit to permute.
 */
extern const uint16_t REV_PERM[24];

/**
 * @brief POS is an array of bits position
 * between 0 to 24.
 */
extern const uint32_t POS[24];

#endif