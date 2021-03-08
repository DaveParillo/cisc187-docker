
#include <iostream>
#include <list>
#include <vector>

using std::list;
using std::vector;

// a non-generic sum algorithm
// Compute the sum of all the elements in an array
double sum(double array[], int n)
{
  double s = 0;
  for (int i = 0; i < n; ++i ) s = s + array[i];
  return s;
}

struct Node { 
  Node* next; 
  int data; 
  Node(): next{nullptr}, data{0} {}

  // see https://wiki.sei.cmu.edu/confluence/pages/viewpage.action?pageId=88046894
  explicit Node(int x) : next{nullptr}, data{x} {}
};

// a non-generic sum algorithm
// Compute the sum of all the elements in a linked list
int sum(Node* first) //sum ints in list
{
  int s = 0;
  while (first) {    //first not false or zero
    s += first->data;
    first = first->next;
  }
  return s;
}

int main()
{
  double my_array[10] = {3,1,4,1,5,9,5,6,2,6};
  std::cout << "My array total: " << sum(my_array,10) << std::endl;

  Node* a = new Node(3);
  Node* b = new Node(1);
  Node* c = new Node(4);

  Node* head = new Node();
  head->next = a;
  a->next = b;
  b->next = c;
  std::cout << "My list total: " << sum(head) << std::endl;


  return 0;
}

