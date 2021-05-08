#ifndef ATTACK_H
#define ATTACK_H

#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * @brief data is a struct that stores
 * a pair message, key and the arrays 
 * encrypt_m and decrypt_m that contain the 
 * encryption of message and the 
 * decryption of the ciphers respectively.
 * 
 * @param m1 clear message
 * @param e1 encrypted message
 * @param m2 clear message
 * @param e2 encrypted message
 * @param encrypt_m1 array which contain the encrypted message m1
 * @param decrypt_d1 array which contain the decrypted message c1
 * @param encrypt_m2 array which contain the encrypted message m2
 * @param decrypt_d2 array which contain the decrypted message c2
 */
typedef struct data_attack
{
    uint32_t m1;
    uint32_t e1;
    uint32_t m2;
    uint32_t e2;
    uint32_t *encrypt_m1;
    uint32_t *decrypt_e1;
    uint32_t *encrypt_m2;
    uint32_t *decrypt_e2;
} data_attack;

/**
 * @brief Initialize clear and encrypted message
 *  and generates array of encryption and decryption
 * 
 * @param m1 clear message 
 * @param e1 encrypted message
 * @param m2 clear message 
 * @param e2 encrypted message
 * @return data_attack 
 */
data_attack *init_data_attack(uint32_t m1, uint32_t e1, uint32_t m2, uint32_t e2);

/**
 * @brief Search the collision between encrypted array 
 * and decrypted array and return the key pair 
 * founds
 * 
 * @param attack struct that contains data 
 * using to attack 
 */
void attacks(data_attack *attack);

/**
 * @brief free all memories allocated.
 * 
 * @param attack 
 */
void free_data_attack(data_attack *attack);

/**
 * @brief Check if the key pair (k1, k2) founds 
 * is the good key
 * 
 * @param k1 key 
 * @param k2 key 
 * @param a attack data
 * @return true 
 * @return false 
 */
bool check_key(uint32_t k1, uint32_t k2, data_attack *a);

#endif