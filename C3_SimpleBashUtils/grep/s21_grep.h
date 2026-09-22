#ifndef S21_GREP_H
#define s21_GREP_H

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int i, e, v, c, s, l, n, h, f, o;
  int len_pattern;
  char regular[1024];
} grepOpt;

void parser(int argc, char** argv, grepOpt* options);
void output(char* line, int len);
void regular(int argc, char** argv, grepOpt* options);
void openFile(char* path, grepOpt* options, regex_t* re);
void matches(regex_t* re, char* line, grepOpt* options, int line_number);
void addFromFile(grepOpt* options, char* path);
void regular_add(grepOpt* options, char* pattern);

#endif
