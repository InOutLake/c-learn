#include <stdio.h>
#include <stdlib.h>

#define INSIDE 1
#define OUT 0

int main(int argc, char *argv[]) {
  int c, state;
  state = OUT;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t') {
      if (state == INSIDE)
        printf("%c", '\n');
      state = OUT;
    } else {
      state = INSIDE;
      printf("%c", c);
    }
  }
  return EXIT_SUCCESS;
}
