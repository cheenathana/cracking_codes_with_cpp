#include <string>

namespace reverse_cipher {
   std::string encrypt(std::string);
   std::string decrypt(std::string);
}

namespace caesar_cipher {
   std::string encrypt(std::string, int key);
   std::string decrypt(std::string, int key);
}
