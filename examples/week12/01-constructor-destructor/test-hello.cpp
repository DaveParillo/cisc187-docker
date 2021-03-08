#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "Hello.h"
#include <doctest.h>
#include <string>

TEST_CASE("simple test") {
    Hello kitty;
    CHECK(kitty.name() == "Alice");
    kitty.name("Felix");
    CHECK(kitty.name() == "Felix");
}


