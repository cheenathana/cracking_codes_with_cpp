#include <string>

namespace reverse_cipher {
   std::string encrypt(std::string);
   std::string decrypt(std::string);
}

namespace caesar_cipher {
   std::string encrypt(std::string, int);
   std::string decrypt(std::string, int);
}

namespace ctransposition_cipher {
   std::string encrypt(std::string, int);
   std::string decrypt(std::string, int);
}

namespace affine_cipher {
   std::string encrypt(std::string, int);
   std::string decrypt(std::string, int);
   int generate_key();
   int get_gcd(int, int);
}
