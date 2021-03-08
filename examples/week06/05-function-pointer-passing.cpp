#include <iostream>
#include <string>

using op = int(*)(int x, int y);

int add     (int x, int y);
int multiply(int x, int y);
int subtract(int x, int y);
int divide  (int x, int y);

op  get_command(const char command);
int calculate(const op operation, int x, int y);

int main()
{
  std::string op;

  int x = 10;
  int y = 2;

  while (true)
  {
    std::cout << "Operation (a,m,s,d, or q): ";
    std::cin >> op;
    if (op[0] == 'q') break;

    auto pf = get_command(op[0]);

    std::cout << calculate(pf, x,  y) << std::endl;

  }

  return 0;
}

op get_command(const char command) {
  op pf = nullptr;         // pointer to a function to execute on all operands
  switch (command) {
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
  return pf;

}

int calculate(const op operation, int x, int y) {
  return (*operation)(x,  y);
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
