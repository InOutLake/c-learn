#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 32

int setbits(int x, int p, int n, int y) {
  int mask, wildcard, y_bits;
  if (p > INT_MAX)
    perror("p must be lower then max int position (32)");
  if (n > INT_MAX - p)
    n = INT_MAX - p;
  mask = (1 << n) - 1;
  wildcard = mask << (p - n);
  x = x | wildcard;
  y_bits = mask;
  y_bits &= y;
  y_bits = y_bits << (p - n);
  y_bits |= ~wildcard;
  printf("%15s %32b\n", "applying:", y_bits);
  x &= y_bits;

  return x;
}

int main(int argc, char *argv[]) {
  int x = 4231;
  int y = 132;
  printf("%15s %32b\n", "x before:", x);
  printf("%15s %32b\n", "y:", y);
  x = setbits(x, 7, 5, y);
  printf("%15s %32b\n", "x after:", x);
  return EXIT_SUCCESS;
}
