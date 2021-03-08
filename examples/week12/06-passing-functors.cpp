#include <stdio.h>
#include <algorithm>
#include <vector>

 
void print_func(int y) {
  printf("%d",y);
}

struct print_class {
    void operator() (int y) { printf("%d",y); }
};
 
int main()
{
  std::vector<int> numbers {3, 1, 4, 1, 5, 9};
  puts("print using regular function:");
  std::for_each(numbers.begin(), numbers.end(), print_func);

  puts("\nrepeat with function object:");
  // failure to call the print_class function without ()'s 
  // is a common source of error
  //                                                       vv
    std::for_each(numbers.begin(), numbers.end(), print_class());
  //std::for_each(numbers.begin(), numbers.end(), print_class  );  // compile error

  puts("\nrepeat with function object variable:");
  print_class p;
  std::for_each(numbers.begin(), numbers.end(), p);


  puts("\nrepeat with lambda:");
  std::for_each(numbers.begin(), numbers.end(), 
      [] (int y) { printf("%d",y); });

  puts("\nrepeat with lambda variable:");
  auto print = [] (int y) { printf("%d",y);};

  std::for_each(numbers.begin(), numbers.end(), print);
}

