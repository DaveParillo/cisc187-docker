#include <iostream>
#include <vector>

int main()
{
  std::vector<int> vi;
  for (int i=1; i<=5; i++) vi.push_back(i);

  std::cout << "vi contains:";
  for (std::vector<int>::iterator it = vi.begin() ; it != vi.end(); ++it) {
    std::cout << ' ' << *it;
  }
  std::cout << '\n';


  // repeat the same loop but let auto determine the type:
  std::cout << "vi contains:";
  for (auto it = vi.begin() ; it != vi.end(); ++it) {
    std::cout << ' ' << *it;
  }
  std::cout << '\n';

  //range for does similar job simply:
  std::cout << "vi contains:";
  for (auto i: vi)  {
    std::cout << ' ' << i;     // i is an int, not an iterator
  }
  std::cout << '\n';

}

