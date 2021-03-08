#include <iostream>
#include <string>
using std::cout;
using std::oct;
using std::hex;
using std::dec;

int main() {
  std::string heading = "\ndec\toct\thex\tchar\n";
  for (int i = 0; i < 128; ++i) {
    if (!(i%20)) cout << heading;
    char c = i;
    // the printable characters are between hex 20 and 7e
    cout << dec << i << '\t'
         << oct << i << '\t'
         << hex << i << "\t'" << c << "'\n";
  }
  return 0;
}

