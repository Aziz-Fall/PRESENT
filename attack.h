#ifndef ATTACK_H
#define ATTACK_H

#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief data is a struct that stores
 * a pair message, key and two arrays 
 * encrypt_m and decrypt_m that contain the 
 * encryption of message and the 
 * decryption of the key respectively.
 * 
 * @param m clear message
 * @param e encrypted message
 * @param encrypt_m arrays 
 * @param decrypt_d arrays.
 */
typedef struct data_attack
{
    uint32_t m;
    uint32_t e;
    uint32_t *encrypt_m;
    uint32_t *decrypt_e;
} data_attack;

/**
 * @brief key_pair is a struct that 
 * stores a key pair.
 */
typedef struct key_pair
{
    uint32_t k1;
    uint32_t k2;
} key_pair;


/**
 * @brief Init the value of the message
 * and the key.
 * 
 * @param m clear message 
 * @param e encrypted message
 * @return data_attack 
 */
data_attack *init_data_attack(uint32_t m, uint32_t e);

/**
 * @brief Encrypt the message and decrypt 
 * the encrypted message with all the keys 
 * between [0 - 0xffffff] and store the 
 * result in the arrays that are in 
 * the variable attack
 *
 * @param attack struct that contains data 
 * using to attack 
 */
void generate(data_attack *attack);

/**
 * @brief free all memories allocated.
 * 
 * @param attack 
 */
void free_data_attack(data_attack *attack);

/**
 * @brief Get the key pair 
 * 
 * @param attack 
 * @return key_pair 
 */
key_pair get_key_pair(data_attack *attack);

#endif