#include "BetterShipping.h"
#include <string>

int main() {
  BetterShipping better;
  //better.weight = -3;  // This is an error now
  better.weight(-3);  // Nothing prevents me from doing this
                      // But now I can fix it and not break my interface
}

