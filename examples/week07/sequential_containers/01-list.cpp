#include <algorithm>
#include <iostream>
#include <list>
using std::cout;
using std::list;

void print_list(const list<int>& t) {
  // range-based for loop
  cout << "list contains: " << '\n';
  for(const int i: t) {
    cout << i << " ";
  }
  cout << "\n\n";
}
list<int>::iterator move_to(list<int>& t, int value) {
  auto it = t.begin();
  while((*++it != value) && (it != t.end()));
  return it;
}

int main () {
  list<int> my_list = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  cout << "size: "  << my_list.size() << '\n';
  cout << "front: " << my_list.front() << '\n';
  cout << "back: "  << my_list.back() << "\n\n";

  cout << "push_back 13: " << '\n';
  my_list.push_back(13);
  cout << "size: "  << my_list.size() << '\n';
  cout << "back() " << my_list.back() << '\n';

  print_list(my_list);

  // need an iterator to insert and erase
  auto it1 = move_to(my_list, 5);
  if (it1 != my_list.end()) {
    cout << "insert 21 before 5:" << '\n';
    my_list.insert(it1, 21);
  }
  print_list(my_list);

  it1 = move_to(my_list, 7);
  if (it1 != my_list.end()) {
    cout << "erase 7:" << '\n';
    my_list.erase(it1);
  }

  print_list(my_list);

  cout << "erase items between 21 and 8:" << '\n';
  it1 = move_to(my_list, 21);
  auto it2 = move_to(my_list, 8);
  if (it1 != my_list.end() && it2 != my_list.end()) {
    cout << "found items: " << *it1 << " & " << *it2 << '\n';
    my_list.erase(it1, it2);
    print_list(my_list);
  }

  return 0;
}
