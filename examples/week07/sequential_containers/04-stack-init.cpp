#include <deque>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

 
int main()
{
    std::stack<int> first;
    first.push(5);
    std::cout << "first: " << first.size() << '\n';
 
    // copy contruct a stack
    std::stack<int> second(first);
    std::cout << "second: " << second.size() << '\n';

    // create a stack from a deque
    std::deque<int> pi {3, 1, 4, 1, 5, 9};
    std::cout << "deque: " << pi.size() << '\n';
    std::stack<int> third(pi);
    std::cout << "third: " << pi.size() << '\n';
 
    // create a stack from a vector
    std::vector<int> euler {2, 7, 1, 8, 2, 8};
    std::stack<int, std::vector<int>> fourth(euler);

    std::cout << "vector: " << euler.size() << '\n';
    std::cout << "fourth: " << fourth.size() << '\n';

}
