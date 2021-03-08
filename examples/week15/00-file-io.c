//#include <cstdio>  // to use these facilities in a C++ program
#include <stdio.h>

// Using standard C to read and write files

const int maxString = 1024;

int main () {
  const char* file_name = "test.txt";			// file name
  const char* str = "This is a plain old C-string.\n";

  // create/write the file
  printf("writing file\n");
  FILE* writer = fopen(file_name, "w");
  for(int i = 0; i < 5; i++) {
    fputs(str, writer);
  }

  fclose(writer);
  printf("done.\n");

  // read the file
  printf("reading file\n");
  char buf[maxString];
  FILE* reader = fopen(file_name, "r");
  while(fgets(buf, maxString, reader)) {
    fputs(buf, stdout);
  }

  fclose(reader);
  remove(file_name);

  printf("done.\n");

  return 0;
}
