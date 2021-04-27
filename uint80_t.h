#ifndef UINT80_T_H
#define UINT80_T_H

#include <stdint.h>
#include <stdio.h>

/**
 * @brief uint4_t represent an integer 
 * of 4 bits.
 */
typedef struct uint4_t 
{
    unsigned int b: 4;
} uint4_t;

/**
 * @brief uint80_t represent an integer
 * of 80 bits.
 * 
 */
typedef struct uint80_t 
{
    /**
     * @brief Array containing 80 bits
     */
    uint4_t tab[20];

}uint80_t;

/**
 * @brief init the array tab by putting 
 * all bits of K tab
 * 
 * @param K master key
 * @param int80 
 */
void init_key(uint32_t K, uint80_t *int80);

/**
 * @brief Allocate a memory for type uint80_t;
 * @return uint80_t* 
 */
uint80_t *init();

/**
 * @brief print each value of the array 
 * uint80_t
 * @param int80 
 */
void print_key(uint80_t int80);

/**
 * @brief rotate the bit of the key 
 * of 61 positons
 * @param *K master 
 */
void rotate_bits(uint80_t *K);

/**
 * @brief shift the key to p position
 * 
 * @param K key
 * @param p position 
 */
void offset(uint80_t *K, int p);

/**
 * @brief Update the master key after a lap
 * @param K master key
 * @param i lap
 */
void updateKey(uint80_t *K, int i);

/**
 * @brief Get the sub key of the master key
 * 
 * @param K master key
 * @return uint32_t sub key
 */
uint32_t get_sub_key(uint80_t *K);

#endif