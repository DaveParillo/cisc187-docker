#include <stdio.h>

int main (void) {
  int rc = puts("Hello World");

  if (rc == EOF) {
    perror("puts()"); // POSIX requires that errno is set
  }
  puts("Goodbye");  // but you don't have to use it
}
