#include <cassert>

// multiplies the operand defined at construction time
// by one provided to the function call overload
class Multiply {
    const int operand;
public:
    Multiply () : operand(1) {}
    Multiply (int n) : operand(n) {}
    int operator () ( int n ) const { return operand * n; }
};

int main() {
    const Multiply identity;
    const Multiply times5(5);
    const Multiply times13 = {13}; // same as previous, avoids c++ 'most vexing parse'
    assert (identity(1) == 1);
    assert (identity(-2) == -2);

    assert (times5(5) == 25);
    assert (times13(10) == 130);

    return 0;
}
