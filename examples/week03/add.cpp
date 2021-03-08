#include <iostream>

// This function takes two parameters.
// First declare the function
int addNumbers(int x, int y);

int main()
{
  std::cout << addNumbers(13, 21); // Call the function.
  std::cout << std::endl;
  return 0;
}

// We can define it any time after we declare it
int addNumbers(int x, int y){
  int answer = x + y;
  return answer;
}

