#include "s21_cat.h"

int main(int argc, char **argv) {
  catOpt options = {0};
  int index = 1;
  int prev = '\n';
  parser(argc, argv, &options);
  if (argc != 1) {
    for (int i = 1; i < argc; i++) {
      print_file(argv[i], options, &index, &prev);
    }
  }
  return 0;
}

void parser(int argc, char **argv, catOpt *options) {
  int opt;
  struct option long_option[] = {
      {"number-nonblank", 0, NULL, 'b'},
      {"number", 0, NULL, 'n'},
      {"squeeze-blank", 0, NULL, 's'},
  };

  while ((opt = getopt_long(argc, argv, "nbseEtTv", long_option, NULL)) != -1) {
    switch (opt) {
      case 'n':
        options->n = 1;
        break;
      case 'b':
        options->b = 1;
        break;
      case 's':
        options->s = 1;
        break;
      case 'e':
        options->e = 1;
        options->v = 1;
        break;
      case 'E':
        options->e = 1;
        break;
      case 't':
        options->t = 1;
        options->v = 1;
        break;
      case 'T':
        options->t = 1;
        break;
      case 'v':
        options->v = 1;
        break;
      default:
        fprintf(stderr, "other options");
    }
  }
}

void print_file(char *name, catOpt options, int *index, int *prev) {
  FILE *file = fopen(name, "r");
  if (file != NULL) {
    int c = fgetc(file);
    bool empty_line = false;
    while (c != EOF) {
      if ((options.s == 1) && (c == '\n') && empty_line) {
        *prev = c;
        c = fgetc(file);
        continue;
      }
      if ((c == '\n') && (*prev == '\n')) {
        empty_line = true;
      } else
        empty_line = false;

      if (((options.n == 1 && options.b != 1) ||
           (options.b == 1 && c != '\n')) &&
          *prev == '\n') {
        printf("%6d\t", *index);
        ++*index;
      }

      if (options.t == 1 && c == '\t') {
        printf("^I");
        *prev = c;
        c = fgetc(file);
        continue;
      }

      if (options.e == 1 && c == '\n') {
        printf("$");
      }

      if (options.v == 1 && !isprint(c)) {
        if (c == 127) {
          printf("^");
          c = '?';
        } else if (iscntrl(c) && (c != '\t') && (c != '\n')) {
          printf("^");
          c = c + 64;
        } else if (c == 255) {
          printf("M-^");
          c = '?';
        } else if ((c > 127) && (c < 160)) {
          printf("M-^");
          c = c - 64;
        } else if (c >= 160) {
          printf("M-");
          c = c - 128;
        }
      }

      putc(c, stdout);

      *prev = c;
      c = fgetc(file);
    }
    fclose(file);
  }
}