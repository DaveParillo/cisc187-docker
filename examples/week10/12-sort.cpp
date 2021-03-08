#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric> 
#include <vector>
#include <random>

// A fun version of insertion sort from
// http://www.bfilipek.com/2014/12/top-5-beautiful-c-std-algorithms.html
//
// Many job interviews involve a 'whiteboard interview'
// that asks you to write a bubble sort.
// I don't know why this is such a popular question.
// Don't know why it's taught in school either.
//  - It's not particularly easy to memorize
//  - It's not an obvious solution to the sorting problem
//  - It performs rather badly - it's average performance is n-squared!
//
//  If you can get past these points with a future employer,
//  you might score some points with this, which:
//  - is far easier to memorize and explain: the actual sort is only 2 lines
//  - Even though still n-squared, is typically better in practice than
//    bubble sort
//  - demonstrates familiarity with the STL

#define RandomAccessIterable typename

template <RandomAccessIterable It> 
void print(const It begin, const It end, const char* msg) {
    // not very pretty
    // avoids hardcoded ostream_iterator<int>
    using os = std::ostream_iterator<typename std::iterator_traits<It>::value_type>;

    std::cout << msg;
    std::copy(begin, end, os(std::cout, " "));
    std::cout << '\n';
}

template <RandomAccessIterable It> 
void insertion_sort(It begin, It end) {
    for (auto i = begin; i != end; ++i) {
        std::rotate(std::upper_bound(begin, i, *i), i, std::next(i));
        //print (begin, end, "\t");
    }
}

// comapre this to the selection_sort function in
// examples/week04/07-sorting.cpp
//
template <RandomAccessIterable It> 
void selection_sort(It begin, It end) {
    for (auto i = begin; i != end; ++i) {
        std::iter_swap(i, std::min_element(i, end)); // we could pass a comparator to min_element
        //print (begin, end, "\t");
    }
}

int main() {
    // initialize and randomize
    std::vector<int> v(20);
    std::iota(v.begin(), v.end(), -10);
    auto generator = std::mt19937{std::random_device{}()};
    std::shuffle(v.begin(), v.end(), generator);

    // show sorts in action
    print (v.begin(), v.end(), "before:         \t");
    insertion_sort(v.begin(), v.end());
    print (v.begin(), v.end(), "insertion sort: \t");

    std::shuffle(v.begin(), v.end(), generator);
    print (v.begin(), v.end(), "before:         \t");
    selection_sort(v.begin(), v.end());
    print (v.begin(), v.end(), "selection sort: \t");
}


// How Insertion sort works:
//
// rotate (first, middle, last)
//   - takes a range [first, last) and rotates it so that 
//     the middle element becomes the first in that range.
//
// upper_bound (first, last, value)
//   - Returns an iterator pointing to the first element in the range [first,last) 
//     which compares greater than value. 
//     The range should be already sorted (or at least partitioned).
//
// How do those two elements combine into Insertion sort?
//
// std::upper_bound(start, i, *i) returns the position of the first element greater than *i. 
// Then, the range is shifted, so that i-th element becomes first.
//
// Feel free to uncomment 
//     print (begin, end, "\t");
// in the body of the for loop to see the insertions in action.
//

// How Selection sort works:
//
// iter_swap (a, b)
//   - swaps the values of the elements pointed to
//     by the iterators a and b.
//
// min_element(first, last)
//   - finds the smallest element in the range
//
// How do those two elements combine into Selection sort?
//
// std::min_element(i, end) returns the position of the smallest value
// between the current position and the end of the range.
// The values pointed to by the current iterator and the minimum found
// are swapped, and the process repeats on the next iterator.
//


