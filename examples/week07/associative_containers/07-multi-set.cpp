#include <functional>  // std::greater
#include <iostream>
#include <set>

struct Greater {
  constexpr bool operator()(int lhs, int rhs) const 
  {
    return lhs > rhs;
  }
};

int main()
{
    std::multiset<int, Greater> x {2,7,1,8,2,8,1,8,2,8,4,5,9};

    std::cout << "x: ";
    for (auto i: x) {
        std::cout << i << ' ';
    }

    auto greater_than = [] (int lhs, int rhs) { return lhs > rhs;};

    std::set <int, decltype(greater_than)> y(greater_than);
    y = {2,7,1,8,2,8,1,8,2,8,4,5,9};
    std::cout << "\ny: ";
    for (auto i: y) {
        std::cout << i << ' ';
    }

    std::set <int, std::greater<int>> z {2,7,1,8,2,8,1,8,2,8,4,5,9};
    std::cout << "\nz: ";
    for (auto i: z) {
        std::cout << i << ' ';
    }
}

