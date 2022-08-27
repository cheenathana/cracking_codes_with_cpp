#include <iostream>

#include "cipher.h"

int main() {
   std::string a = "This is my secret message.";
   //std::string a = "y";
   std::cout << "Message : " << a << std::endl;

   std::string encrypt = caesar_cipher::encrypt(a, 13);
   std::string decrypt = caesar_cipher::decrypt(encrypt, 13);

   std::cout << encrypt << std::endl;
   std::cout << decrypt << std::endl;

   return 0;
}
