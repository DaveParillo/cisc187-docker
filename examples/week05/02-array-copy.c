#include <stdio.h>

// an old C idiom to copy a 'string'
int main (int argc, char** argv) {
  char a[] = "Hello World!";
  char b[13];

  // painfully print each char, 1 at a time.
  int i;
  for (i=0; i<12;++i) putchar(a[i]);
  printf("\n");

  char* p1 = a;
  char* p2 = b;
  while ((*p2++ = *p1++));

  printf("copy:\n");
  printf("%s\n", p2);  // print chars until '\0' detected
  return 0;
}

