#include <iostream>
#include <type_traits>

int main() {
  std::cout << std::boolalpha;

  if(std::is_signed<char>::value){
    std::cout << "char is signed, is it same? " << std::is_same<char, signed char>::value;
  }else{
    std::cout << "char is unsigned, is it same? " << std::is_same<char, unsigned char>::value;
  }
  std::cout << std::endl;
}

