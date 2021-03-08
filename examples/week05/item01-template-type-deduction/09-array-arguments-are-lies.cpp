// We begin with the observation that there is no such thing as a function parameter
// that’s an array. Yes, yes, the syntax is legal:

void myFunc1(int param[]) {}

// but the array declaration is treated as a pointer declaration, 
// meaning that myFunc
// could equivalently be declared like this:

void myFunc2(int* param) {}   // same function as above


// The upshot is that when you pass an array to a function,
// it's type is *always* a pointer type


