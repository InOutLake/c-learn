#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1000
int lower(const char str[], char output[]) {
  int i;
  for (i = 0; str[i] != '\0'; i++) {
    output[i] = 'A' <= str[i] && str[i] <= 'Z' ? str[i] - ('A' - 'a') : str[i];
  }
  output[i] = '\0';
  return 0;
}

int main(int argc, char *argv[]) {
  char output[MAX_LENGTH];
  lower("Make Alaska Great AGAIN!", output);
  printf("%s\n", output);
  return EXIT_SUCCESS;
}
