#include "test.h"

int main() {
  int failed = 0;
  failed += memchr_main();
  failed += memcmp_main();
  failed += memcpy_main();
  failed += memset_main();
  failed += strncat_main();
  failed += strchr_main();
  failed += strncmp_main();
  failed += strncpy_main();
  failed += strcspn_main();
  failed += strerror_main();
  failed += strlen_main();
  failed += strpbrk_main();
  failed += strrchr_main();
  failed += strstr_main();
  failed += strtok_main();
  failed += sprintf_main();
  return (failed == 0) ? 0 : 1;
}
