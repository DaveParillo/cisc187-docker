#include <map>
#include <iostream>

void show(const std::map<int, int> &a,
          const std::map<int, int> &b,
          const std::map<int, int> &c)
{
  std::cout << "a: " << a.size() 
    << " b: " << b.size()
    << " c: " << c.size() << '\n';
}

int main()
{
  std::map<int, int> x {{3, 1}, {4, 1}, {5, 9}, 
                        {6, 1}, {7, 1}, {8, 9}};
  std::map<int, int> y; 
  std::map<int, int> z;

  show(x, y, z);
  y = x;
  show(x, y, z);

  z = std::move(x);
  show(x, y, z);
}

