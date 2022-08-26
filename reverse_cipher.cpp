#include <string>

#include "cipher.h"


std::string reverse_cipher::encrypt(std::string message) {
   /* Encrypts the message using REVERSE-CIPHER and returns it

      @param string Message to hide or encrypt
      @return string The encrypted data
   */
   std::string encrypted = "";

   for (int i = message.size() - 1; i >= 0; i--) {
      encrypted += message[i];
   }

   return encrypted;
}


std::string reverse_cipher::decrypt(std::string message) {
   /* Decrypts the message using REVERSE-CIPHER and returns it

      @param string Encrypted message as string
      @return string The actual message
   */
   std::string decrypted = "";

   for (int i = message.size() - 1; i >= 0; i--) {
      decrypted += message[i];
   }

   return decrypted;
}
