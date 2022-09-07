#include <string>
#include <stdexcept>

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
   key_a = key / SYMBOLS.size();
   key_b = key % SYMBOLS.size();
}


int get_gcd(int x, int y) {
   //
}


void validate_key_strength(int key_a, int key_b) {
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
            "Pick a different key".
         );
      throw weak_cipher_key_error;
   }

   // CONDITION 03
   if (get_gcd(key_a, SYMBOLS.size()) != 1) {
      std::runtime_error weak_cipher_key_error(
            "KeyA and size of SYMBOLS are not relatively prime. "
            "Decrypting will cause issues. Pick a different key."
         );
      throw weak_cipher_key_error;
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
