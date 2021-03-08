#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#define HELLO_CONSTRUCTOR
#include "Hello.h"
#include <doctest.h>
#include <string>

// Even though name() returns a string
// and  "Alice" is a const char*
// docstest can still compare them as equal
TEST_CASE("test default constructor") {
    Hello h;
    CHECK(h.name() == "Alice");
}

TEST_CASE("set name") {
    Hello h;
    h.name("Bob");
    CHECK(h.name() == "Bob");
}

TEST_CASE("set initial value") {
    Hello h = {"Clara"};
    CHECK(h.name() == "Clara");
}

