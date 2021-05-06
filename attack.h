#ifndef ATTACK_H
#define ATTACK_H

#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void red();
void green();
void blue();
void reset();
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
 * @brief key_pair is a struct that 
 * stores a key pair and 
 * execution time to find the keys
 */
typedef struct key_pair
{
    uint32_t k1;
    uint32_t k2;
    double times;
} key_pair;


/**
 * @brief Init the value of the message
 * and the key.
 * 
 * @param m clear message 
 * @param e encrypted message
 * @return data_attack 
 */
data_attack *init_data_attack(uint32_t m1, uint32_t e1, uint32_t m2, uint32_t e2);

/**
 * @brief Generates array of encryption and decryption
 * and founds the key pair in the same time
 * 
 * @param attack struct that contains data 
 * using to attack 
 */
key_pair attacks(data_attack *attack);

/**
 * @brief free all memories allocated.
 * 
 * @param attack 
 */
void free_data_attack(data_attack *attack);

/**
 * @brief display the key pair
 * 
 * @param k key pair
 * @param a data
 * @param times Execution time to find the keys
 */
void display_key_pair(key_pair k, data_attack *a);

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