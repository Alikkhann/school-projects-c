#include "s21_string.h"

// Sprintf

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;

  char *format_str = str;

  va_start(args, format);
  while (*format) {
    if (*format != '%') {
      *str = *format;
      str++;
      format++;
      continue;
    }

    if (*format == '%') {
      format++;
      int flag_plus = 0;
      int flag_minus = 0;
      int dot = 0;
      int width = 0;
      int precision = 0;
      int length = 0;
      int space = 0;
      int format_specifier = 0;
      while (*format && !is_spec(*format) && format_specifier != 1) {
        switch (*format) {
          case '+': {
            flag_plus = 1;
            break;
          }
          case '-': {
            flag_minus = 1;
            break;
          }
          case '.': {
            dot = 1;
            break;
          }
          case 'h': {
            length = 'h';
            break;
          }
          case 'l': {
            length = 'l';
            break;
          }
          case ' ': {
            if (!space) {
              *str = *format;
              str++;
            }
            space = 1;
            break;
          }
          case '%': {
            *str = *format;
            str++;
            format_specifier++;
            break;
          }
        }

        if (is_digit(*format) && !dot) {
          width = width * 10 + (*format - 48);
          format++;
        } else if (dot && is_digit(*format)) {
          precision = precision * 10 + (*format - 48);
          format++;
        } else {
          format++;
        }
      }
      switch (*format) {
        case 'd': {
          long int number = va_arg(args, long int);

          if (length == 'h') {
            number = (short int)number;
          } else if (length == 'l') {
            number = (long int)number;
          } else {
            number = (int)number;
          }
          int is_negative = number < 0;
          int sign = is_negative || flag_plus;
          int is_precision = precision <= 0 ? 0 : 1;
          int len = count_digits(number);
          char str_int[len + 1];
          int_to_str(str_int, number, len);

          if (!flag_minus && width) {
            set_width(width, len, sign, precision, is_precision, &str);
          }
          set_sign(number, flag_plus, &str);
          if (precision) {
            set_precision(len, precision, &str);
          }

          set_value(&str, str_int, len);

          if (flag_minus && width) {
            set_width(width, len, sign, precision, is_precision, &str);
          }
          format++;
          break;
        }
        case 'f': {
          double number = va_arg(args, double);

          precision = precision == 0 ? 6 : precision;
          int is_negative = number < 0;
          int sign = is_negative || flag_plus;
          int int_part = number;
          double frag_part = number - int_part;

          int int_len = count_digits(int_part);
          char str_int[int_len + 1];
          if (!flag_minus && width) {
            set_width(width, int_len, sign, precision, -1, &str);
          }
          int_to_str(str_int, int_part, int_len);

          set_sign(number, flag_plus, &str);

          char str_frag[precision + 1];
          float_to_str(str_frag, frag_part, precision);
          if (str_frag[precision] > '4') {
            int check = 0;
            for (int i = precision - 1; i >= 0; --i) {
              if (str_frag[i] != '9') {
                str_frag[i] += 1;
                break;
              } else {
                str_frag[i] = '0';
                if (i == 0) {
                  check = 1;
                }
              }
            }
            if (str_frag[0] == '0' && check) {
              for (int i = int_len - 1; i >= 0; --i) {
                if (str_int[i] != '9') {
                  str_int[i] += 1;
                  break;
                } else if (i != 0) {
                  str_int[i] = '0';
                } else {
                  for (int j = int_len; j > 0; j--) {
                    str_int[j] = str_int[j - 1];
                  }
                  str_int[1] = '0';
                  str_int[0] = '1';
                  int_len++;
                  break;
                }
              }
            }
          }
          set_value(&str, str_int, int_len);

          *str = '.';
          str++;
          set_value(&str, str_frag, precision);

          if (flag_minus && width) {
            set_width(width, int_len, sign, precision, -1, &str);
          }
          format++;
          break;
        }
        case 'u': {
          unsigned long int number = va_arg(args, unsigned long int);
          if (length == 'h') {
            number = (unsigned short int)number;
          } else if (length == 'l') {
            number = (unsigned long int)number;
          } else {
            number = (unsigned int)number;
          }

          int is_precision = precision == 0 ? 0 : 1;
          int len = count_u_digits(number);
          char str_u[len + 1];
          u_to_str(str_u, number, len);

          if (!flag_minus && width) {
            set_width(width, len, -1, precision, is_precision, &str);
          }
          if (precision) {
            set_precision(len, precision, &str);
          }
          set_value(&str, str_u, len);

          if (flag_minus && width) {
            set_width(width, len, -1, precision, is_precision, &str);
          }
          format++;
          break;
        }
        case 'c': {
          int number;

          if (length == 'l') {
            number = va_arg(args, wchar_t);
          } else {
            number = va_arg(args, int);
          }

          if (!flag_minus && width) {
            set_width(width, 1, 0, 0, 0, &str);
          }
          *str = (char)number;
          str++;
          if (flag_minus && width) {
            set_width(width, 1, 0, 0, 0, &str);
          }
          format++;
          break;
        }
        case 's': {
          char *str_str;
          char buffer[4000];
          wchar_t *str_wchar;

          if (length == 'l') {
            str_wchar = va_arg(args, wchar_t *);

            str_str = buffer;
            int i = 0;
            while (str_wchar[i]) {
              buffer[i] = str_wchar[i];
              i++;
            }
            buffer[i] = '\0';
          } else {
            str_str = va_arg(args, char *);
          }
          int len = s21_strlen(str_str);
          if (!flag_minus && width) {
            set_width(width, len, 0, 0, 0, &str);
          }
          set_value(&str, str_str, precision ? precision : len);

          if (flag_minus && width) {
            set_width(width, len, 0, 0, 0, &str);
          }
          format++;
          break;
        }
      }
    }
  }
  *str = '\0';
  va_end(args);
  return s21_strlen(format_str);
}

// Flags, Width, Precision, Set

void set_width(int width, int len, int sign, int precision, int is_precision,
               char **str) {
  for (int i = len + sign + precision - is_precision; i < width; i++) {
    **str = ' ';
    (*str)++;
  }
}

void set_precision(int len, int precision, char **str) {
  for (int i = len; i < precision; i++) {
    **str = '0';
    (*str)++;
  }
}

void set_sign(int number, int flag_plus, char **str) {
  if (number >= 0 && flag_plus) {
    **str = '+';
    (*str)++;

  } else if (number < 0) {
    **str = '-';
    (*str)++;
  }
}

void set_value(char **str, char *token, int len) {
  for (int i = 0; i < len; i++) {
    **str = token[i];
    (*str)++;
  }
}

// Unsigned Int

void u_to_str(char *dest, unsigned long int number, int len) {
  int divider = 10;

  if (number == 0) {
    dest[0] = '0';
    dest[1] = '\0';
  } else {
    for (long long int i = len - 1; i >= 0; i--) {
      dest[i] = (number % divider) + 48;
      number /= divider;
    }
    dest[len] = '\0';
  }
}

int count_u_digits(unsigned long int number) {
  int len = !number;
  unsigned long int temp = number;
  while (temp) {
    temp /= 10;
    len++;
  }
  return len;
}

// Signed Int

void int_to_str(char *dest, long int number, int len) {
  int is_negative = number < 0;
  int divider = 10;
  if (is_negative) {
    number = -number;
  }

  if (number == 0) {
    dest[0] = '0';
    dest[1] = '\0';
  } else {
    for (long int i = len - 1; i >= 0; i--) {
      dest[i] = (number % divider) + 48;
      number /= divider;
    }
    dest[len] = '\0';
  }
}

int count_digits(long int number) {
  int len = !number;
  long int temp = number;
  while (temp) {
    temp /= 10;
    len++;
  }
  return len;
}

// Double (Float)

void float_to_str(char *dest, double frag_part, int precision) {
  int divider = 10;
  int number;

  if (frag_part < 0) {
    frag_part = -frag_part;
  }

  for (int i = 0; i <= precision; i++) {
    frag_part *= 10;
    number = (int)frag_part;
    dest[i] = (number % divider) + 48;
    number /= divider;
    frag_part -= number;
  }
}

// Check Functions

int is_digit(char number) { return (number >= 48 && number <= 57) ? 1 : 0; }
int is_spec(char ch) {
  return (ch == 'd' || ch == 'c' || ch == 'f' || ch == 's' || ch == 'u') ? 1
                                                                         : 0;
};
