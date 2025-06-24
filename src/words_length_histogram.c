#include <stdio.h>
#include <stdlib.h>

char *print_column(int value, int width_outside, int width_inside) {
  const char *fill_char = " ";
  const char *blocks[] = {
      "\xE2\x96\x81", // ▁  One eighth block       (index 0)
      "\xE2\x96\x82", // ▂  One quarter block      (index 1)
      "\xE2\x96\x83", // ▃  Three eighths block    (index 2)
      "\xE2\x96\x84", // ▄  Half block             (index 3)
      "\xE2\x96\x85", // ▅  Five eighths block     (index 4)
      "\xE2\x96\x86", // ▆  Three quarters block   (index 5)
      "\xE2\x96\x87", // ▇  Seven eighths block    (index 6)
      "\xE2\x96\x88", // █  Full block             (index 7)
      "\xE2\x96\x88", // █  Full block (extra)     (index 8)
      "\xE2\x96\x88"  // █  Full block (extra)     (index 9)
  };
  int padding = width_outside - width_inside;
  int pad_left = padding / 2;
  int pad_right = padding - pad_left;
  char *buffer = (char *)malloc(width_outside * 2);
  char *result = buffer;
  for (int i = 0; i < pad_left; i++) {
    result += sprintf(result, "%s\n", fill_char);
  }
  for (int i = 0; i < width_inside; i++) {
    result += sprintf(result, "%s\n", blocks[value]);
  }
  for (int i = 0; i < pad_right; i++) {
    result += sprintf(result, "%s\n", fill_char);
  }
  return result;
};

#define COLUMN_WIDTH_OUTER 4
#define COLUMNT_WIDTH_INSIDE 2
#define MAX_HEIGHT 200
#define MAX_WORD_LENGTH 15
int main(int argc, char *argv[]) {
  int lengths[MAX_WORD_LENGTH + 1];
  int word_length = 0;
  int ch;
  FILE *file = fopen("/home/inoutlake/c-learn/tmp/histogram.txt", "r");
  while ((ch = fgetc(file)) != EOF) {
    if (ch == ' ' || ch == '\t' || ch == '\n') {
      if (word_length > MAX_WORD_LENGTH)
        lengths[MAX_WORD_LENGTH]++;
      lengths[word_length] += 1;
      word_length = 0;
    } else {
      word_length++;
    }
  }
  for (int h = MAX_HEIGHT; h > 0; h -= 10) {
    for (int col = 1; col < MAX_WORD_LENGTH; h++) {
      print_column()
    }
  }
  return EXIT_SUCCESS;
}
