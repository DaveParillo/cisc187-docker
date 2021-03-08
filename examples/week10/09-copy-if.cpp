
#include <iostream>
#include <list>
#include <vector>

using std::list;
using std::vector;

namespace mesa {

  // contrary to the textbook, this template IS in the STL
  // as of C++11
  
  template<class In, class Out, class Pred>
    Out copy_if(In first, In last, Out res, Pred p)
    // copy elements that fulfill the predicate
    {
      while (first!=last) {
        if (p(*first)) *res++ = *first;
        ++first;
      }
      return res;
    }
}  // namespace mesa

// copy the odd elements of a list of ints into a vector of doubles
void copy_odd(vector<double>& vd, list<int>& li)
{
  if (vd.capacity() < li.size()) {
    std::cout << "\nresizing...\n";
    vd.resize(li.size());
  }
  // Technically, the -> bool is not needed here
  // The compiler can deduce the return type
  mesa::copy_if(li.begin(), li.end(), vd.begin(), 
      [](int x) -> bool {return x % 2 != 0;});    
}

int main()
{
  list<int> odd_list = {1,1,2,3,5,8,13,21,34,55};
  vector<double> v(odd_list.size());
  copy_odd(v,odd_list);
  for (int d: v) {
    std::cout << d << std::endl;
  }
  return 0;
}

