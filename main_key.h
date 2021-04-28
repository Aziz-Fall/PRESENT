#ifndef MAIN_KEY_H
#define MAIN_KEY_H

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
 * @brief main_key represent an integer
 * of 80 bits.
 * 
 */
typedef struct main_key 
{
    /**
     * @brief Array containing 80 bits
     */
    uint4_t tab[20];
    uint32_t sub_key[12];

}main_key;

/**
 * @brief init the array tab by putting 
 * all bits of K tab
 * 
 * @param K master key
 * @param int80 
 */
void init_key(uint32_t K, main_key *int80);

/**
 * @brief Allocate a memory for type main_key;
 * @return main_key* 
 */
main_key *init();

/**
 * @brief print each value of the array 
 * main_key
 * @param int80 
 */
void print_key(main_key int80);

/**
 * @brief rotate the bit of the key 
 * of 61 positons
 * @param *K master 
 */
void rotate_bits(main_key *K);

/**
 * @brief shift the key to p position
 * 
 * @param K key
 * @param p position 
 */
void offset(main_key *K, int p);

/**
 * @brief Update the master key after a lap
 * @param K master key
 * @param i lap
 */
void updateKey(main_key *K, int i);

/**
 * @brief Init the sub keys of the 
 * main Key K
 * 
 * @param K main Key.
 */
void init_sub_key(main_key *K);

#endif