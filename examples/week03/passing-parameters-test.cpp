#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

//
// A copy of x is passed to this function.
// Changes to x are not reflected in the caller.
//
void by_value(int x) {
  x = 99;
}

// but you can always change the copy and return the copy
int meaning_of_life(int x) {
  x = 42;
  return x;
}

//
// A reference to x is passed to this function.
// Changes to x are not reflected in the caller.
//
// What if the signature is changed to 'const int& x'?
//
void by_reference(int& x) {
  x = -1;
}

TEST_CASE("test pass by value"
        * doctest::description("alpha is not changed")) {
    auto alpha = 11;
    by_value(alpha);
    CHECK(alpha == 11);
}

TEST_CASE("test pass by reference"
        * doctest::description("beta is changed")) {
    auto beta = 11;
    by_reference(beta);
    CHECK_EQ(beta, -1);
}

TEST_CASE("test return value"
        * doctest::description("alpha is unchanged, copy returned")) {
    auto alpha = 11;
    CHECK_EQ(meaning_of_life(alpha), 42);
}


