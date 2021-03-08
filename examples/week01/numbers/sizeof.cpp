#include <iostream>
#include <string>

int main() {
  char c = 'a';
  std::cout << "size of char:    " << sizeof(c) << '\n'
            << "size of int:     " << sizeof(int) << '\n'
            << "size of double:  " << sizeof(double) << '\n'
            << "size of pointer: " << sizeof(&c) << std::endl;

  double foo[10] = {0.1, 3.14159, 1e1, 2e-6, 5, 6, 7, 8, 9, 10};
  std::cout << "size of foo[]:            " << sizeof(foo) << '\n'
            << "no. of elements in foo[]: " << sizeof(foo) / sizeof(foo[0]) << std::endl;

  std::string bar[10] = {
    "hi", "hello world!", "it doesn't actually matter how long these strings are as far as the array is concerned.  What is stored is only a reference to the string in memory" };
  std::cout << "size of bar[]:  " << sizeof(bar) << '\n'
            << "size of &bar:   " << sizeof(&bar) << '\n'
            << "size of *bar:   " << sizeof(*bar) << '\n'
            << "size of bar[0]: " << sizeof(bar[0]) << '\n'
            << "size of bar[2]: " << sizeof(bar[2]) << '\n'
            << "no. of elements in bar[]: " << sizeof(bar) / sizeof(bar[0]) << std::endl;
}
