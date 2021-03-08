#include "call-stack.h"
#include <iostream>

int main()
{
  std::cout << "Programs always start in function main.\n";

  dig();

  std::cout << "Returned to main.\nexiting.";
  return 0;
}


void dig()
{
  std::cout << "Digging...\n";
  deeper();
  std::cout << "Still digging...\n";
}

void deeper()
{
  std::cout << "now even deeper....\n";
}

