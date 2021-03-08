#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using std::cout;
using std::endl;
using std::vector;

void run_within_for_each(std::function<void (int)> func);

int main()
{
  auto func1 = [](int y)
  {
    cout << y << ' ';
  };

  auto func2 = [](int z)
  {
    cout << z * 2 << ' ';
  };

  run_within_for_each(func1);
  run_within_for_each(func2);
}

void run_within_for_each(std::function<void (int)> func)
{
  vector<int> numbers{ 1, 2, 3, 4, 5, 10, 15, 20, 25, 35, 45, 50 };
  for (const auto& n: numbers) {
    func(n);
  }
  cout << '\n';
}



