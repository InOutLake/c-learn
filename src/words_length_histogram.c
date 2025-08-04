#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *format_center_str(char *str, int width) {
  char *fill_char = " ";
  int padding = width - strnlen(str, width);
  int pad_left = padding / 2;
  int pad_right = padding - pad_left;
  int buffer_size = (width * 4);
  char *buffer = calloc(buffer_size, sizeof(char));
  char *ptr = buffer;

  for (int i = 0; i < pad_left; i++) {
    ptr += sprintf(ptr, "%s", fill_char);
  }

  ptr += sprintf(ptr, "%s", str);

  for (int i = 0; i < pad_right; i++) {
    ptr += sprintf(ptr, "%s", fill_char);
  }

  return buffer;
}

char *format_center_int(int value, int width) {
  char str[width * 4];
  sprintf(str, "%d", value);
  return format_center_str(str, width);
}

char *format_column(int value, int width_outside, int width_inside) {
  const char *blocks[] = {
      " ",
      "\xE2\x96\x81", // ▁  One eighth block
      "\xE2\x96\x82", // ▂  One quarter block
      "\xE2\x96\x83", // ▃  Three eighths bloc
      "\xE2\x96\x84", // ▄  Half block
      "\xE2\x96\x85", // ▅  Five eighths block
      "\xE2\x96\x86", // ▆  Three quarters block
      "\xE2\x96\x87", // ▇  Seven eighths block
      "\xE2\x96\x88", // █  Full block
      "\xE2\x96\x88", // █  Full block
  };
  char sign[width_inside * 4];
  for (int i = 0; i < width_inside; i++) {
    sprintf(sign, "%s", blocks[value]);
  }
  char *buffer = format_center_str(sign, width_outside);
  return buffer;
};

#define COLUMN_WIDTH_OUTER 4
#define COLUMN_WIDTH_INSIDE 2
#define MAX_HEIGHT 100
#define MAX_WORD_LENGTH 11
int main(int argc, char *argv[]) {
  int lengths[MAX_WORD_LENGTH + 1];
  for (int i = 0; i < MAX_WORD_LENGTH; i++) {
    lengths[i] = 0;
  }
  int word_length = 0;
  int ch;
  FILE *file = fopen("/home/inoutlake/projects/c-learn/tmp/histogram.txt", "r");
  if (file == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }
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
    for (int col = 1; col < MAX_WORD_LENGTH; col++) {
      int value = (lengths[col] - h);
      if (value < 0) {
        value = 0;
      } else if (value > 10) {
        value = 9;
      }
      printf("%s",
             format_column(value, COLUMN_WIDTH_OUTER, COLUMN_WIDTH_INSIDE));
    }
    printf("%s\n", "");
  }
  for (int col = 1; col < MAX_WORD_LENGTH; col++) {
    printf("%s", format_center_int(col, COLUMN_WIDTH_OUTER));
  }
  return EXIT_SUCCESS;
}
