#include <string>

#include "cipher.h"

// defining character which are considered for encrypt/decrypt
const std::string SYMBOLS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890 !?.";


std::string caesar_cipher::encrypt(std::string message, int key) {
   /* Encrypts the message using CAESAR CIPHER based on the key and returns it
    *
    * @param string Message to be hidden
    * @param int Key used for shifting
    * @return string Encrypted data
    */
   std::string encrypt = "";

   for (int i = 0; i < message.size(); i++) {
      size_t index = SYMBOLS.find(message[i]);

      // checking if the character is present in the SYMBOLS
      if (index == std::string::npos) {
         encrypt += message[i];
         continue;
      }

      // finding the new index based on the key
      int padding = index + key;

      // resize the padding if it is greater than SYMBOL size
      if (padding > SYMBOLS.size()) {
         padding -= SYMBOLS.size();
      }

      encrypt += SYMBOLS[padding];
   }

   return encrypt;
}


std::string caesar_cipher::decrypt(std::string encrypted, int key) {
   /* Decrypts the data using CAESAR CIPHER based on the key and returns it
    *
    * @param string Encrypted data
    * @param int Key used for shifting
    * @return string Hidden message
    */
   std::string decrypted = "";

   for (int i = 0; i < encrypted.size(); i++) {
      size_t index = SYMBOLS.find(encrypted[i]);

      // checking if the character is present in the SYMBOLS
      if (index == std::string::npos) {
         decrypted += encrypted[i];
         continue;
      }

      // finding the old index based on the key
      int padding = index - key;

      // resize the padding if the value is negative
      if (padding < 0) {
         padding = SYMBOLS.size() + padding;
      }

      decrypted += SYMBOLS[padding];
   }

   return decrypted;;
}
