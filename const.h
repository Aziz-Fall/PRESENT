#ifndef CONST_H
#define CONST_H 

#include <inttypes.h>
#include <stdint.h>
#include <float.h>

const __uint128_t BITS_PIVOTED = 0x1fffffffffffffff;

/**
 * @brief WORDS is an array that contains 
 * a word of 4 bits of one and this bits 
 * are between positions 0 and 3, 4 and 7,
 * ..., 20 and 23.
 */
const uint32_t WORDS[6] = { 
                            0xf,    0xf0,    0xf00, 
                            0xf000, 0xf0000, 0xf00000
                        };

/**
 * @brief SUBS an array of substitution, 
 * each cage of table contains 
 * corresponding bit position.
 */
const uint16_t SUBS[16] = {
                            0xc, 0x5, 0x6, 0xb,
                            0x9, 0x0, 0xa, 0xd,
                            0x3, 0xe, 0xf, 0x8,
                            0x4, 0x7, 0x1, 0x2
                        };

const uint8_t PERM[24] = {
                            0x0,  0x6,  0xc, 0x12, 0x1,  0x7,
                            0xd,  0x13, 0x2, 0x8,  0xe,  0x14,
                            0x3,  0x9,  0xf, 0x15, 0x4,  0xa,
                            0x10, 0x16, 0x5, 0xb,  0x11, 0x17
                        };

/**
 * @brief POS is an array of bits position
 * between 0 to 24.
 */
const uint32_t POS[24] = {  0x1,      0x2,      0x4,      0x8, 
                            0x10,     0x20,     0x40,     0x80,
                            0x100,    0x200,    0x400,    0x800,
                            0x1000,   0x2000,   0x4000,   0x8000,
                            0x10000,  0x20000,  0x40000,  0x80000,
                            0x100000, 0x200000, 0x400000, 0x800000
                        };

#endif