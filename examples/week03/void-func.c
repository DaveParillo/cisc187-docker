// In C, it is legal to define a function that defines no parameter list
// This is not the same as func(void), which explicitly declares no parameters are passed.
//
// Not using void means a function that takes an unspecified (but not variable) 
// number of parameters.
//
// This example compiles and runs, but makes no sense.
// You have been warned.
#include<stdio.h>

const double PI = 3.14159265358979323846;

float area1(float);
float area2(void);
float area3();



int main () {
  int height = 3;
  float width = 5.0f;

  printf("\nArea 1 : %.2f\n", area1(2.0f));
  printf("\nArea 2 : %.2f\n", area2());
  printf("\nArea 3 : %.2f\n", area3(height, width));

  return (0);
}

float area1 (float radius) {
  return PI * radius * radius;
}

float area2 (void) {
  return 1;
}

float area3 () {
  return area1(3);
}


