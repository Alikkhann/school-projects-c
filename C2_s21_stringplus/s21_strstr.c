#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  //находит и выводит совпад подстраку  "need table"
  char *res = s21_NULL;
  if (haystack != s21_NULL || needle != s21_NULL) {
    if (*needle == '\0') {
      res = (char *)haystack;
    }
    s21_size_t length = s21_strlen(needle);
    while (*haystack != '\0') {
      if (!s21_memcmp(haystack++, needle, length)) {
        res = (char *)(haystack - 1);
        break;
      }
    }
  }
  return res;
}
