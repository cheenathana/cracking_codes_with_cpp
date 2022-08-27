#include <string>

#include "cipher.h"

// defining character which are considered for encrypt/decrypt
const std::string SYMBOLS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz123456789!?.";


std::string caesar_cipher::encrypt(std::string message, int key) {
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




