#include <iostream>

int main()
{
  int count = 2;
  auto lambda = [count] { 
    std::cout << "Hello, lambda " << count << "!\n"; 
  };
  lambda();
}

