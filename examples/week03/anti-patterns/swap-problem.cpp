#include <cstring>
#include <iostream>

using namespace std;

// swap and add 1 to each of the values
void swap(long& x, long& y) {
    int t;
    t = x+1;
    x = y+1;
    y = t;
}

int main(int argc, char** argv) {
    int a = 10;
    int b = 20;
    for (int i=1; i < argc; ++i) {
        if (!std::strcmp(argv[i], "-a")) {
            ++i;
            if (i < argc) {
                a = std::atoi(argv[i]);
            } else {
                std::cerr << "Error using '-a' argument: no value provided\n";
            }
        } else if (!std::strcmp(argv[i], "-b")) {
            ++i;
            if (i < argc) {
                b = std::atoi(argv[i]);
            } else {
                std::cerr << "Error using '-b' argument: no value provided\n";
            }
        } else {
            std::cerr << "Unrecognized argument. Using defaults.\n";
            std::cerr << "Usage: " << argv[0] 
                      << " [-a an_int] [-b an_int]\n";
        }
    }

    swap (a, b);

    cout << "a: " << a << ", ";
    cout << "b: " << b << endl;

    return 0;
}

