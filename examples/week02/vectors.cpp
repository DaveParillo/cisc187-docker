#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;


/**
 * A vector 'hello world':
 *
 * 1. Fill a vector in one simple way, using push_back
 * 2. iterate through the vector and print
 *
 */
int main() {
  vector<string> words;

  words.push_back("reach");
  words.push_back("clear");
  words.push_back("fall");
  words.push_back("set");
  words.push_back("yard");
  words.push_back("liquid");
  words.push_back("wise");
  words.push_back("badge");
  words.push_back("four");
  words.push_back("coherent");
  // or all on one line as:
  // vector<string> words = {
  //   "reach", "clear", "fall", "set", "yard",
  //   "liquid", "wise", "badge", "four", "coherent"
  // };

  cout << "Word list: \n";
  for (string s: words) {
    cout << "  " << s << ", \thas " << s.size() << " letters\n";
  }

  return 0;
}


