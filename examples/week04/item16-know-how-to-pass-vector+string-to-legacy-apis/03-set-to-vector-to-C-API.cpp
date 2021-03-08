//
// Example 3.
// If you have a non-vector container, you can always copy the data from the 
// STL container to a vector adn then call your C API function.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <set>

int data[] = { -30, 102, 55, -19, 0, 222, -3000, 4000, 8, -2 };
const int numValues = sizeof data / sizeof(int);

void doSomething(const int* pInts, size_t numInts)
{
  int sum = 0;
  for (size_t i = 0; i < numInts; i++)
    sum += pInts[i];
  std::cout << "Sum of ints in the array is " << sum << std::endl;
}


int main()
{
  using namespace std;

  set<int> intSet;							              	// set that will hold
                                                // data to pass to API

  intSet.insert(data, data + numValues);  			// insert the ints in data
                                                // into the set

  vector<int> v(intSet.begin(), intSet.end());	// copy set data into	
                                                // a vector

  if (!v.empty()) doSomething(&v[0], v.size());	// pass the data to
                                                // the API

  return 0;
}
