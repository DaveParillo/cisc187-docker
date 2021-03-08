#include <iostream>
#include <set>

using std::cout;
using std::multiset;

int main() {
    cout << "Find all copies of a value in a multiset.\n";
    cout << "Mulitset values:\n";
    multiset<int> digits {3,2,1,3,5,8,13,5,21,3,5,8};

    // 'it' is a multiset<int>::iterator
    for (auto it = digits.begin();
              it != digits.end(); ++it) cout << *it << ' ';


    // lower_bound returns multiset<int>::iterator
    auto lower = digits.lower_bound(5);
    cout << "\nLower bound of 5:\t\t " << *lower;

    --lower;
    cout << "\nValue prior to lower_bound(5):\t " << *lower;
    auto upper = digits.upper_bound(5);
    cout << "\nUpper bound of 5:\t\t " << *upper;
    ++upper;
    ++upper;
    cout << "\n2 beyond the upper bound of 5:\t" << *upper;

    cout << "\nDisplay all copies of 5 from the multiset: ";

    // std::pair<multiset<int>::iterator, 
    //           multiset<int>::iterator> range;
    // 
    // same thing as:
    // std::pair<decltype(lower), decltype(lower)> range;
    //
    std::pair<decltype(lower), decltype(upper)> range;
    range = digits.equal_range(5);

    // if this was a for loop
    // then 'it' would have narrower scope
    auto it = range.first;
    while (it!= range.second) cout << *it++ << ' ';

    return 0;
}
