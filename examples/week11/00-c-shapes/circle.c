#include<stdio.h>

const double PI = 3.14159265358979323846;

float area(float);
float length(float);

int main() {
  float radius, a, len;

  printf("\nEnter the radius of Circle : ");
  scanf("%f", &radius);

  a = area(radius);
  printf("\nArea of Circle : %.2f\n", a);

  len = length(radius);
  printf("\nCircumfrence of Circle : %.2f\n", len);

  return (0);
}


float area (float radius) {
  return PI * radius * radius;
}

float length (float radius) {
  return PI * 2.0 * radius;
}

