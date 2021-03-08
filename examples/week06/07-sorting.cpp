// A nice example from learncpp.com:
//  http://www.learncpp.com/cpp-tutorial/78-function-pointers/
//
//
#include <iostream>
#include <utility>

// This sorting function takes a function pointer as a parameter.
// The function allows the caller to control how the data gets sorted.
//
// This basic idea is exactly how std::sort works in the STL
// With std::sort, if you don't provide a 'comparator function'
// then the data is sorted according to the 'natural order' of the data provided
//
// The parameter 
//   bool (*comparator)(int, int)
//
// could have simplified using either
//
//   typedef bool (*comparator)(int, int);
//   or
//   using comparator = bool (*)(int, int)
//
// which then reduces the function signature to
//   void selection_sort(int *array, int size, comparator func)
//
// or
//   std::function<bool, (int, int)> comparator;  
//
//
void selection_sort(int *array, int size, bool (*comparator)(int, int))
{
  // depending on what the comaprator actually does, 
  // smallest is a misleading variable name
  // it might actually be 'largest' or something else
  // but 'smallest' is a lot shorter than 'current_min_or_max_comparator_result'
  for (int start = 0; start < size; ++start) {
    // smallest is the index of the smallest element we've encountered so far.
    int smallest = start;

    // Look for smallest element remaining in the array
    for (int current = start+1; current < size; ++current) {
      if (comparator(array[smallest], array[current])) {
        // This is the new smallest number for this iteration
        smallest = current;
      }
    }

    // Swap our start element with our smallest element
    std::swap(array[start], array[smallest]);
  }
}

// A comparison function that sorts in ascending order
bool ascending(int x, int y) 
{
  return x > y; // swap if the first element is greater than the second
}

// A comparison function that sorts in descending order
bool descending(int x, int y) 
{
  return x < y; // swap if the second element is greater than the first
}

bool evens_first(int x, int y)
{
  // if x is even and y is odd, x goes first (no swap needed)
  if ((x % 2 == 0) && !(y % 2 == 0))
    return false;

  // if x is odd and y is even, y goes first (swap needed)
  if (!(x % 2 == 0) && (y % 2 == 0))
    return true;

  // otherwise sort in ascending order
  return ascending(x, y);
}

// print out the values in an array
void print(int *array, int size) 
{
  for (int index=0; index < size; ++index) {
    std::cout << array[index] << " ";
  }
  std::cout << '\n';
}

int main() 
{
  int array[9] = { 3, 7, 9, 5, 6, 1, 8, 2, 4 };

  // Sort the array in descending order using the descending() function
  selection_sort (array, 9, descending);
  print (array, 9);

  selection_sort (array, 9, ascending);
  print (array, 9);

  // Sort all the evens, then the odds
  selection_sort (array, 9, evens_first);
  print (array, 9);
}

