#include <iostream>
#include <stack>
#include <string>
#include <list>
using std::cout;
using std::stack;

#define StackContainer typename

template <StackContainer C>
void pop_all(C& s) {
  cout << "\nsize of stack before: " << s.size() << '\n';
  while(!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
  cout << "\npopped all from stack\n";
  cout << "size of stack after: " << s.size() << '\n';
}

int main () {
  cout << "initialize stack from list:\n";
  std::list<int> t = { 1, 2, 3, 4, 5 };
  stack<int, std::list<int>> istack(t);

  cout << "list has " << t.size() << " entries";

  pop_all (istack);

  stack<std::string> sstack;
  cout << "push strings onto stack...";
  sstack.push("one");
  sstack.push("two");
  sstack.push("three");
  sstack.push("four");
  sstack.push("five");

  pop_all (sstack);

  return 0;
}

