#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int c;
  int prev;
  while ((c = getchar()) != EOF) {
    if ((prev == ' ' && c != ' ') || (prev != ' '))
      printf("%c\n", c);
    prev = c;
  }
  return EXIT_SUCCESS;
}
