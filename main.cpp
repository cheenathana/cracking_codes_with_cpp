#include <iostream>

#include "cipher.h"

int main() {
   std::string a = "Common sense is not so common.";
   std::cout << "Message : " << a << std::endl;

   std::string encrypt = ctransposition_cipher::encrypt(a, 9);
   std::string decrypt = ctransposition_cipher::decrypt(encrypt, 9);

   std::cout << encrypt << std::endl;
   std::cout << decrypt << std::endl;

   return 0;
}
