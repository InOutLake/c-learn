#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int c;
  while ((c = getchar()) != EOF) {
    if (c == ' ')
      printf("%c", '_');
    else if (c == '\t')
      printf("%s", "\\t");
    else
      printf("%c", c);
  }
  return EXIT_SUCCESS;
}
