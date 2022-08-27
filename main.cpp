#include <iostream>

#include "cipher.h"

int main() {
   std::string a = "Hello world!!!";

   std::string encrypt = caesar_cipher::encrypt(a, 1);

   std::cout << encrypt << std::endl;
   return 0;
}
