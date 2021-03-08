#include <iostream>
#include <string>
#include <queue>
#include <list>
using namespace std;

template <class T>
void pop_all(T& q) {
  cout << "\nsize of queue: " << q.size() << '\n';
  while(!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  cout << "\npop all from queue\n";
  cout << "size of queue: " << q.size() << '\n';
}

int main () {
  cout << "initialize queue from list:\n";
  std::list<int> t = { 1, 2, 3, 4, 5 };
  queue<int, std::list<int>> iqueue(t);

  cout << "list has " << t.size() << " entries";

  pop_all (iqueue);

  queue<std::string> squeue;
  cout << "push strings onto queue...";
  squeue.push("one");
  squeue.push("two");
  squeue.push("three");
  squeue.push("four");
  squeue.push("five");

  pop_all (squeue);

  return 0;
}
