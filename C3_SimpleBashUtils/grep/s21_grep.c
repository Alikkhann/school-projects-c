#define _GNU_SOURCE
#define POSSIX_C_SOURCE 200809L
#include "s21_grep.h"

int main(int argc, char** argv) {
  grepOpt options = {0};
  parser(argc, argv, &options);
  regular(argc, argv, &options);
  return 0;
}

void parser(int argc, char** argv, grepOpt* options) {
  int opt;
  char short_options[] = "e:ivcf:lnhso";
  while ((opt = getopt(argc, argv, short_options)) != -1) {
    switch (opt) {
      case 'e':
        options->e = 1;
        regular_add(options, optarg);
        break;
      case 'i':
        options->i = REG_ICASE;
        break;
      case 'v':
        options->v = 1;
        break;
      case 'c':
        options->c = 1;
        break;
      case 'l':
        options->l = 1;
        break;
      case 'n':
        options->n = 1;
        break;
      case 'h':
        options->h = 1;
        break;
      case 's':
        options->s = 1;
        break;
      case 'f':
        options->f = 1;
        addFromFile(options, optarg);
        break;
      case 'o':
        options->o = 1;
        break;
      default:
        break;
    }
  }
  if (options->len_pattern == 0 && optind < argc) {
    regular_add(options, argv[optind]);
    optind++;
  }

  if (argc - optind == 1 || options->c) {
    options->h = 1;
  }
}

void output(char* line, int len) {
  for (int i = 0; i < len; i++) {
    printf("%c", line[i]);
  }
  if (line[len - 1] != '\n') printf("\n");
}

void regular(int argc, char** argv, grepOpt* options) {
  regex_t re;
  int comp = regcomp(&re, options->regular, REG_EXTENDED | options->i);
  if (comp) {
    perror("No compiling regex\n");
    exit(1);
  }
  for (int i = optind; i < argc; i++) {
    openFile(argv[i], options, &re);
  }

  regfree(&re);
}

void openFile(char* path, grepOpt* options, regex_t* re) {
  FILE* file = fopen(path, "r");
  if (file == NULL) {
    if (!options->s) perror("Error");
    exit(1);
  }

  char* line = NULL;
  size_t len = 0;
  ssize_t read;
  int res_counter = 0;
  int line_counter = 0;

  while ((read = getline(&line, &len, file)) != -1) {
    line_counter++;
    int res = regexec(re, line, 0, NULL, 0);
    if ((res == 0 && !options->v) || (res != 0 && options->v)) {
      if (!options->c && !options->l) {
        if (!options->h) printf("%s:", path);
        if (options->o) {
          matches(re, line, options, line_counter);
        } else {
          if (options->n) printf("%d:", line_counter);
          output(line, read);
        }
      }
      res_counter++;
    }
  }

  if (options->c && !options->l) {
    printf("%d\n", res_counter);
  }

  if (options->l && res_counter > 0) {
    printf("%s\n", path);
  }

  free(line);
  fclose(file);
}

void matches(regex_t* re, char* line, grepOpt* options, int line_number) {
  int index = 0;
  regmatch_t match;
  while (1) {
    int res = regexec(re, line + index, 1, &match, 0);
    if (res != 0) break;

    if (options->n) {
      printf("%d:", line_number);
    }

    for (int i = match.rm_so; i < match.rm_eo; i++) {
      printf("%c", line[i + index]);
    }
    printf("\n");
    index += match.rm_eo;
  }
}

void addFromFile(grepOpt* options, char* path) {
  FILE* file = fopen(path, "r");
  if (file == NULL) {
    if (!options->s) perror("Error");
    exit(1);
  }

  char* line = NULL;
  size_t len = 0;
  int read;

  while ((read = getline(&line, &len, file)) != -1) {
    if (line[read - 1] == '\n') line[read - 1] = '\0';
    regular_add(options, line);
  }

  free(line);
  fclose(file);
}

void regular_add(grepOpt* options, char* pattern) {
  if (options->len_pattern != 0) {
    strcat(options->regular, "|");
    options->len_pattern++;
  }

  options->len_pattern +=
      sprintf(options->regular + options->len_pattern, "(%s)", pattern);
}
