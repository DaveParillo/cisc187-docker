#include "Hello.h"
#include <cstdio>

void say_hi_to(Hello someone) {
  printf("Hello, %s\n", someone.name().c_str());
}

int main() {
  Hello me;               // Create an object from a class
  say_hi_to(me);          // use the name
                          // what is the default value of name?

  me.name("Dave");        // Call a function to change the name
  say_hi_to(me);          // use the name
  return 0;
}
