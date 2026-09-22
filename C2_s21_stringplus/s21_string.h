#ifndef S21_STRING_H
#define S21_STRING_H

#include <stdarg.h>
#include <stdlib.h>

// NULL && size_t
#define s21_NULL 0
typedef long unsigned int s21_size_t;

// String Functions
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *dest, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
int s21_sprintf(char *str, const char *format, ...);

// Sprintf Subfunctions:

// Flags, Width, Precision, Set
void set_width(int width, int len, int sign, int precision, int is_precision,
               char **str);
void set_precision(int len, int precision, char **str);
void set_sign(int number, int flag_plus, char **str);
void set_value(char **str, char *token, int len);

// Unsined Int
void u_to_str(char *dest, unsigned long int number, int len);
int count_u_digits(unsigned long int number);

// Signed Int
void int_to_str(char *dest, long int number, int len);
// int str_to_int(char *src);
int count_digits(long int number);

// Double (Float)
void float_to_str(char *dest, double frag_part, int precision);

// Check Functions
int is_digit(char number);
int is_spec(char ch);

// Strerror (Length of Errors_List)
#ifdef __APPLE__
#define ERRORS_LEN 107
#else
#define ERRORS_LEN 133
#endif

#endif
