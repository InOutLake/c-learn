#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int c;
  long n = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n' || c == '\t' || c == ' ')
      n++;
  }
  printf("%ld\n", n);
  return EXIT_SUCCESS;
}
