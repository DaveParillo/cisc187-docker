#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "BadShipping.h"
#include "BetterShipping.h"
#include "EvenBetterShipping.h"
#include <doctest.h>
#include <string>

TEST_CASE("I can set weight to anything") {
    BadShipping b;
    b.weight = 0;
    CHECK(b.weight == 0);
    b.weight = true;
    CHECK(b.weight == 1);
    b.weight = -42;
    CHECK(b.weight == -42);
}


TEST_CASE("BetterShipping still allows weight to anything") {
    BetterShipping b;
    b.weight(0);
    CHECK(b.weight() == 0);
    b.weight(true);
    CHECK(b.weight() == 1);
    b.weight(-42);
    CHECK(b.weight() == -42);
}

TEST_CASE("EvenBetterShipping defaults") {
    EvenBetterShipping a;
    CHECK(a.weight() == 2);
    CHECK(a.distance() == 100);
    CHECK(a.address() == "My mom's house");
}

TEST_CASE("EvenBetterShipping constructor") {
    EvenBetterShipping a = {12, 999, "Your house"};
    CHECK(a.weight() == 12);
    CHECK(a.distance() == 999);
    CHECK(a.address() == "Your house");
    EvenBetterShipping bad = {-99, 0, ""};
    CHECK(bad.weight() == 1);
    CHECK(bad.distance() == 0);     // this class still needs improvement
    CHECK(bad.address() == "");     // this class still needs improvement
}



TEST_CASE("EvenBetterShipping no longer allows weight to anything") {
    EvenBetterShipping b;
    b.weight(0);
    CHECK(b.weight() == 1);
    b.weight(true);
    CHECK(b.weight() == 1);
    b.weight(-42);
    CHECK(b.weight() == 1);
}


