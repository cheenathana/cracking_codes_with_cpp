#include <string>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

#include "cipher.h"

/*
 * ENCRYPTION PROCESS
 * plain text -> multiply by keyA -> Add keyB -> Mod by size(if larger) -> cipher text
 *
 * DECRYPTION PROCESS
 * cipher text -> substract keyB -> multiply by mod inverse of keyA -> mod by size -> text
 */

// defining character which are considered for encrypt/decrypt
const std::string SYMBOLS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890 !?.";


void split_key_parts(int key, int& key_a, int& key_b) {
   /* To generate a split key out of passed in key to enhance encryption security
    *
    * @param int User entered key
    * @param int& Reference value for holding keyA
    * @param int& Reference value for holding keyB
    * @return None
    */
   key_a = key / SYMBOLS.size();
   key_b = key % SYMBOLS.size();
}


int affine_cipher::get_gcd(int x, int y) {
   /* To calculate Greatest Common Divisor of two numbers 
    * 
    * @param int Non-negative value
    * @param int Non-negative value
    * @return int Greatest Common Divisor of x,y
    */
   if (x == 0)
      return y;
   if (y == 0)
      return x;

   if (x == y)
      return x;

   if (x > y)
      return get_gcd(x-y, y);

   return get_gcd(x, y-x);
}


void validate_key_strength(int key_a, int key_b) {
   /* To validate the picked key is secure or not based on three conditions.
    * If key is not secure, a runtime exception will be raised.
    *
    * @param int KeyA
    * @param int KeyB
    */
   // CONDITION 01
   if (key_a == 1 || key_b == 0) {
      std::runtime_error weak_cipher_key_error(
            "Selected cipher key is weak. "
            "Either KeyA is 1 or KeyB is 0. "
            "Pick a different key."
         );
      throw weak_cipher_key_error;
   }

   // CONDITION 02
   if (key_a < 0 || key_b < 0 || key_b > (SYMBOLS.size() - 1)) {
      std::runtime_error weak_cipher_key_error(
            "Selected cipher key is weak. "
            "KeyA mut greater than 0 and KeyB b/w 0 and size of SYMBOLS. "
            "Pick a different key."
         );
      throw weak_cipher_key_error;
   }

   // CONDITION 03
   if (affine_cipher::get_gcd(key_a, SYMBOLS.size()) != 1) {
      std::runtime_error weak_cipher_key_error(
            "KeyA and size of SYMBOLS are not relatively prime. "
            "Decrypting will cause issues. Pick a different key."
         );
      throw weak_cipher_key_error;
   }
}


int affine_cipher::generate_key() {
   /* Picking a key for Affine Cipher has many restriction as all key is not 
    * as secure. So to randomly generate key which is valid and more secure
    * use this function
    *
    * @return int Generated secure key to use it with Affine Cipher
    */
   int keyA = 0, keyB = 0;

   // seeding the random generator
   srand(time(0));

   while (1) {
      keyA = 2 + (rand() % SYMBOLS.size());
      keyB = 2 + (rand() % SYMBOLS.size());

      if (get_gcd(keyA, SYMBOLS.size()) == 1)
         return keyA * SYMBOLS.size() + keyB;
   }
}


int find_mod_inverse(int x, int m) {
   /* To calculate the Inverse-Mod value for two numbers.
    * We use brute-force method to calculate the mod-inverse value.
    * (x * i) % m == 1
    * where, i - modular inverse value
    * We have to substitute for i value from 1 to m and see if it satisfies
    * the equeation. The i value which satisfies the equation is mod inverse value
    *
    * @param int x
    * @param int m
    * @return int Modular-Inverse value
    */
   for (int i = 1; i < m; i++) {
      if ( ( (x * i) % m ) == 1)
         return i;
   }
}


std::string affine_cipher::encrypt(std::string message, int key) {
   /* Encrypts the message using AFFINE CIPHER based on the key and returns it.
    * Affine cipher is a modified version of ceaser cipher.
    * KeyA - int used to multiply with the letter's index
    * KeyB - add it to the above product
    * 
    * @param string Message to be hidden
    * @param int Key used for shifting
    * @return string Encrypted data
    */
   std::string encrypt = "";
   int keyA = 0, keyB = 0;

   split_key_parts(key, keyA, keyB);
   validate_key_strength(keyA, keyB);

   for (int i = 0; i < message.size(); i++) {
      // checking if the character is present in the SYMBOLS
      size_t index = SYMBOLS.find(message[i]);
      if (index == std::string::npos) {
         encrypt += message[i];
         continue;
      }

      // finding the new index based on the key parts
      int padding = index * keyA + keyB;

      // resize the padding if it is greater than SYMBOL size
      if (padding > SYMBOLS.size()) {
         padding %= SYMBOLS.size();
      }

      encrypt += SYMBOLS[padding];
   }

   return encrypt;
}


std::string caesar_cipher::decrypt(std::string encrypted, int key) {
   /* Decrypts the data using AFFINE CIPHER based on the key and returns it
    *
    * @param string Encrypted data
    * @param int Key used for shifting
    * @return string Hidden message
    */
   std::string decrypted = "";
   int keyA = 0, keyB = 0;

   split_key_parts(key, keyA, keyB);

   for (int i = 0; i < encrypted.size(); i++) {
      // checking if the character is present in the SYMBOLS
      size_t index = SYMBOLS.find(encrypted[i]);
      if (index == std::string::npos) {
         decrypted += encrypted[i];
         continue;
      }

      // finding the old index based on the key
      int padding = index / key;

      // resize the padding if the value is negative
      if (padding == 0) {
         padding = SYMBOLS.size() + padding;
      }

      decrypted += SYMBOLS[padding];
   }

   return decrypted;;
}
