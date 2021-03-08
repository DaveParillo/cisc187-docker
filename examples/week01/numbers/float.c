/* prints a lot of information about floating-point numbers 
 * from:
 * http://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)FloatingPoint.html
 */

#include <stdio.h>
#include <math.h>
#include <values.h>

/* endianness testing */
const int EndianTest = 0x04030201;

#define LITTLE_ENDIAN() (*((const char *) &EndianTest) == 0x01)

/* extract nth LSB from object stored in lvalue x */
#define GET_BIT(x, n) ((((const char *) &x)[LITTLE_ENDIAN() ? (n) / CHARBITS : sizeof(x) - (n) / CHARBITS - 1] >> ((n) % CHARBITS)) & 0x01)

#define PUT_BIT(x, n) (putchar(GET_BIT((x), (n)) ? '1' : '0'))

void print_float_bits(float f) {
  int i;

  i = FLOATBITS - 1;
  PUT_BIT(f, i);
  putchar(' ');
  for(i--; i >= 23; i--) {
    PUT_BIT(f, i);
  }
  putchar(' ');
  for(; i >= 0; i--) {
    PUT_BIT(f, i);
  }
}

void print_float(float f) {
  printf("%10g = %24.17g = ", f, f);
  print_float_bits(f);
  putchar('\n');
}

int main(int argc, char **argv) {
  float f;

  /* Some interesting values */
  print_float(0);
  print_float(-0);
  print_float(0.125);
  print_float(0.25);
  print_float(0.5);
  print_float(1);
  print_float(2);
  print_float(4);
  print_float(8);
  print_float(0.375);
  print_float(0.1);
  print_float(0.2);
  print_float(0.4);
  print_float(0.8);
  print_float(-0.1);
  print_float(-0.2);
  print_float(-0.4);
  print_float(-0.8);
  print_float(1e+12);
  print_float(-1e+12);
  print_float(1e-12);

  puts ("Enter your own values. CTRL-C to exit");
  while(scanf("%f", &f) == 1) {
    print_float(f);
  }

  return 0;
}

