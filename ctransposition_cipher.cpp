#include <string>
#include <vector>

#include "cipher.h"


std::string ctransposition_cipher::encrypt(std::string message, int key) {
   // a vector of vector of string
   std::vector<std::vector<std::string>> columnar;

   int count = 0;

   while (count < message.size()) {
      std::vector<std::string> fill_rows(key, "");

      for (int j = 0; j < key; j++) {
         fill_rows[j] = message[count];
         count++;
      }

      columnar.push_back(fill_rows);
   }

   std::string encrypted = "";
   for (int col = 0; col < key; col++) {
      for (int row = 0; row < columnar.size(); row++) {
         encrypted += columnar[row][col];
      }
   }

   return encrypted;
}
