#include <iostream>
#include <string>

int add     (int x, int y);
int multiply(int x, int y);
int subtract(int x, int y);
int divide  (int x, int y);

int main()
{
  std::string op;

  int x = 10;
  int y = 2;

  int (*pf)(int x, int y);

  while (true)
  {
    std::cout << "Operation: ";
    std::cin >> op;
    if (op[0] == 'q') break;

    switch (op[0])
    {
      case 'a':
        pf = add;
        break;
      case 'm':
        pf = multiply;
        break;
      case 's':
        pf = subtract;
        break;
      case 'd':
        pf = divide;
        break;
      default:
        pf = add;
        std::cout << "input unrecognized.  defaulting to 'add'\n";
        break;

    }

    std::cout << (*pf)(x,  y) << std::endl;

  }

  return 0;
}


int add(int x, int y)
{
  return x + y;
}

int multiply(int x, int y)
{
  return x * y;
}

int subtract(int x, int y)
{
  return x - y;
}

int divide(int x, int y)
{
  return x / y;
}
