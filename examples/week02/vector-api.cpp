//
// A simple program to demonstrate the use of parts of the vector API
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <stdexcept>
#include <string>
#include <vector>

using std::string;
using std::vector;

static vector<string> make_vector() {
  return {
     "reach", "clear", "fall", "set", "yard",
     "liquid", "wise", "badge", "four", "coherent"
   };
}

TEST_SUITE("test vector API") {
    const string empty = "";
    TEST_CASE("make vector") {
        auto words = make_vector();
        REQUIRE(words.size() == 10);
    }
    // at() Returns a reference to the element at specified location pos, with bounds checking.
    // If pos is not within the range of the container, 
    // an exception of type std::out_of_range is thrown.
    TEST_CASE("simple access") {
        auto words = make_vector();
        CHECK(words.at(0) == "reach");   // at()
        CHECK(words[0]    == "reach");   // operator[]
        CHECK(words.at(9) == "coherent");
        CHECK(words[9]    == "coherent");

        // foo.at(i) and foo.[i] refer to the same thing
        for (auto i=0u; i< words.size(); ++i) {
            CHECK(words.at(i) == words[i]);
        }

        // at() include bounds checking
        CHECK_THROWS(words.at(-1));
        CHECK_THROWS_AS(words.at(99), std::out_of_range);

        // [] does not include bounds checking
        // these lines probably crash - try uncommenting them
        // WARN_MESSAGE(words[-1] == empty, "positions before start of vector are indeterminate");
        // WARN_MESSAGE(words[99] == empty, "positions after end of vector are indeterminate");
    }
    TEST_CASE("element access") {
        auto words = make_vector();
        CHECK(words.front() == "reach");
        CHECK(words.back() == "coherent");
    }

    TEST_CASE("operator=") {
        auto words = make_vector();
        CHECK(words[2]    == "fall");      // old value

        words[2] = "falldown";
        CHECK(words[2]    == "falldown");  // new value
    }

    TEST_CASE("assign") {
        std::vector<char> characters;
        constexpr char test_value = '8';
        characters.assign(5, test_value);
        CHECK(characters.size() == 5);
        CHECK(characters[0] == test_value);
        CHECK(characters[1] == test_value);
        CHECK(characters[2] == test_value);
        CHECK(characters[3] == test_value);
        CHECK(characters[4] == test_value);
    }

    TEST_CASE("capacity") {
        auto words = make_vector();
        CHECK(!words.empty());         // prefer this
        CHECK(words.empty() == false); // over this
        CHECK(words.size() == 10);
    }
    TEST_CASE("modifiers") {
        auto words = make_vector();

        CHECK(words.back() == "coherent");   // last word in vector
        words.push_back("howdy");            // add word to end
        CHECK(words.size() == 11);           // vector grows by 1
        CHECK(words.back() == "howdy");      // new last word - coherent is 1 before last
        words.pop_back();                    // remove last word
        CHECK(words.size() == 10);           // vector shrinks as expected
        CHECK(words.back() == "coherent");   // back to where we started


        words.clear();
        CHECK(words.size() == 0);            // avoid doing this in the real world
        CHECK(words.empty());                // prefer this instead
    }
}



