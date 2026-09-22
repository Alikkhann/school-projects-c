#ifndef CAT_S21_CAT_H_
#define CAT_S21_CAT_H_

#include <ctype.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
  int n;
  int b;
  int s;
  int e;
  int t;
  int v;
} catOpt;

void parser(int argc, char **argv, catOpt *options);
void print_file(char *name, catOpt options, int *index, int *prev);

#endif