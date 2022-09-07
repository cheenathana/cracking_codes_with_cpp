#include <string>
#include <stdexcept>

#include "cipher.h"

// defining character which are considered for encrypt/decrypt
const std::string SYMBOLS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890 !?.";


void split_key_parts(int key, int& key_a, int& key_b) {
   key_a = key / SYMBOLS.size();
   key_b = key % SYMBOLS.size();
}


void validate_key_strength(int key_a) {
   // Key value and Lenght of the SYMBOLS should not be equal
   if (key_a == 1) {
      std::runtime_error weak_key("Weak key selected. Choose a different key.");
      throw weak_key;
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
   validate_key_strength(keyA);

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
