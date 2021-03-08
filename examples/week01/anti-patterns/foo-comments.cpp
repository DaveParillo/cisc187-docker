#include <string>
#include <fstream>
#include <iostream>
#include <cstdio>

// The contents of this file are an object lesson on
// how NOT to write comments

/**
 * The FooCalculator class calculates a Foo.
 *
 * @author Dave Parillo
 *
 */
struct FooCalculator {
    /**
     * The Integer maxFoo defines the maximum foo
     */
    int maxFoo = 100;
    /**
     * The Integer foo defines the current foo.
     */
    int foo = 0;
    /**
     * The member thing is an array of strings.
     */
    std::string thing[100];
};

FooCalculator f;

/**
 * The isFooSmallEnough method determines if the foo is small enough
 * @return boolean {@code true} if foo is smaller than max
 * @return boolean {@code false} if foo is larger than max
 */
bool isFooSmallEnough() {
  return f.foo < f.maxFoo;
}

/**
 * Compute a rammer
 */
void rammer(std::string stat) {
  if (isFooSmallEnough()) {
    f.thing[f.foo++] = stat;
  }
  std::cout << stat << '\n';
}


/**
 * Calculate the ramerstat function.
 * @param rammer  A String that stores the rammer value
 */
void rammerstat(std::string x) {
    std::ifstream ram(x);   
    std::string stat;
    while (getline(ram,stat)) {
      rammer(stat);
    }

    ram.close();
}

/**
 * Main is a global function.
 */
int main(int argc, char** argv) {
  if (argc > 1) {
    for (int i = 1;i < argc; ++i) {
      rammerstat(argv[i]);
    }
  } else {
    puts ("Usage: foo-comments args");
  }
}
