#include<stdio.h>
#include<string.h>  // for strcpy function

// In C, a string is literally an array of char
//
// This is not the same as the string class from the STL.
// See strings.cpp for that

int main()
{
  char a[] = {'h', 'e', 'l', 'l', 'o', '\0'};  // the char array must be null terminated
  char b[] = {'h', 'e', 'l', 'l', 'o', 0};     // null == 0
  char* c = "hello";                           // a string is just a special case of a char array

  for (int i = 0; a[i]; ++i) {                 // explain why this loop terminates
    printf ("%c %c %c\n", a[i], b[i], c[i]);
  }

  // copying strings 
  char* d = 0;
  d = a;      // we only copied a pointer here!
  if (a == d) {
    d[0] = 'H';
  }
  printf ("\na and d strings:\n  %s %s\n", a, d);

  char e[sizeof(b)];
  strcpy(e, b); 
  e[0] = 'H';
  printf ("\nb and e strings:\n  %s %s\n", b, e);

  // a = e;    // compile error.  C strings are not assignable

  return 0;
}
