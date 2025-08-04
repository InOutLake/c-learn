#include <stdio.h>
#include <stdlib.h>

int squeeze(char s1[], const char s2[]);
int main(int argc, char *argv[]) {
  char s1[] = "some string";
  char s2[] = "sg";
  squeeze(s1, s2);
  printf("%s\n", s1);
  return EXIT_SUCCESS;
}

int squeeze(char s1[], const char s2[]) {
  int i, j;
  for (i = 0; s1[i] != '\0'; i++) {
    for (j = 0; s2[j] != '\0'; j++) {
      if (s1[i] == s2[j]) {
        s1[i] = ' ';
      }
    }
  }
  return 0;
}
