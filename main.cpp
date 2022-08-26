#include <iostream>

#include "cipher.h"

int main() {
   std::string a = "Hello world!!!";

   std::string encrypt = reverse_cipher::encrypt(a);
   std::string decrypt = reverse_cipher::decrypt(encrypt);

   std::cout << encrypt << std::endl << decrypt << std::endl;;
   return 0;
}
