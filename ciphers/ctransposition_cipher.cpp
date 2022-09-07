#include <string>
#include <vector>
#include <stdexcept>

#include "cipher.h"

/* Transposition Cipher
 * ===================
 * Types of Transposition cipher:
 *   1. Rail-fence cipher
 *   2. Route cipher
 *   3. Myszkowski cipher
 *   4. Disrupted cipher
 *   5. Columnar chpher
 *
 * Here we use Columnar Transposition cipher to encrypt and decrypt
 */

std::string ctransposition_cipher::encrypt(std::string message, int key) {
   /* Using Columnar Transposition cipher to encrypt the message
    *
    * @param string The secret message to hide
    * @param int Key
    * @return string Encrypted data
    */
   // a vector of vector of string
   std::vector<std::vector<std::string>> columnar;
   std::string encrypted = "";
   int count = 0;

   while (count < message.size()) {
      // Vector with size, equivalent to key to hold message
      std::vector<std::string> fill_rows(key, "");

      for (int j = 0; j < key; j++) {
         fill_rows[j] = message[count];
         count++;
      }

      columnar.push_back(fill_rows);
   }

   // Picking the message column wise from the nested array
   for (int col = 0; col < key; col++) {
      for (int row = 0; row < columnar.size(); row++) {
         encrypted += columnar[row][col];
      }
   }

   return encrypted;
}


std::string ctransposition_cipher::decrypt(std::string encrypted, int key) {
   /* Using Columnar Transposition cipher to decrypt the decrypted data
    *
    * @param string The encrypted data
    * @param int Key
    * @return string Message
    */
   std::string decrypted = "";
   int row_needed = encrypted.size() / key;

   for (int i = 0; i < row_needed; i++) {
      for (int j = 0; j < key; j++) {
         try {
            decrypted += encrypted.at(i + (j * row_needed));
         }
         catch (std::out_of_range& e) {
            continue;
         }
      }
   }

   return decrypted;
}
