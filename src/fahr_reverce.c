#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main() {
  printf("%10s %7s", "Fahrenheit", "Celsius\n");
  for (float fahr = UPPER; fahr > LOWER; fahr -= STEP) {
    printf("%10.0f %7.1f\n", fahr, 9.0 / 5.0 * (fahr - 32));
  }
  return 0;
}
