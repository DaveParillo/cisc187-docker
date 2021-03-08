#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

int func () {
  static int x = 0;
  static int y = 1;
  x = y;
  y += x;
  return x;
}

TEST_CASE("increase values using static variables") {
    CHECK(func() == 1);
    CHECK(func() == 2);
    CHECK(func() == 4);
    CHECK(func() == 8);
    CHECK(func() == 16);
    CHECK(func() == 32);
    CHECK(func() == 64);
    CHECK(func() == 128);
}

