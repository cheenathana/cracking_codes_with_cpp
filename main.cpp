#include <iostream>
#include <fstream>
#include <sstream>

#include "ciphers/cipher.h"

int main() {
   // READING FILE AS A STRING AND DOING ENCRYPTION & DECRYPTION
   // std::ifstream f;

   // f.open("demo.txt");     // opening in read mode
   // if (f.fail()) {
   //    std::cout << "Problem in opening the file!!!" << std::endl;
   //    return 1;
   // }

   // std::stringstream buf;
   // buf << f.rdbuf();   // rdbuf - return a pointer to string buffer object
   //                     // << will read all the contents in to buf
   // std::string file_contents, encrypt, decrypt;
   // file_contents = buf.str();

   // std::cout << file_contents << std::endl;
   // std::cout << "=================================" << std::endl;

   // encrypt = ctransposition_cipher::encrypt(file_contents, 8);

   // std::cout << encrypt << std::endl;
   // std::cout << "=================================" << std::endl;


   // decrypt = ctransposition_cipher::decrypt(encrypt, 8);

   // std::cout << decrypt << std::endl;
   // std::cout << "=================================" << std::endl;


   // f.close();
   //
   int kk = affine_cipher::generate_key();
   std::cout << "Key:  " << kk << std::endl;
   std::string enc = affine_cipher::encrypt(
         "A computer would deserve to be called intelligent if it", 3127);
   std::cout << enc << std::endl;


   std::string aa = affine_cipher::decrypt(
         "ZjV6dmJcxAjl6JwCjCxvxA5xjc6joxjV8wwxCjnKcxwwnLxKcjnejnc", 3127);

   std::cout <<"Decrypt : "<< aa << std::endl;

   return 0;
}
