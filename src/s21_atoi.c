#include "s21_string.h"

int s21_atoi(char *str) {
  int result = 0;
  while (*str >= '0' && *str <= '9') {
    result *= 10;
    result += *str++;
    result -= '0';
  }
  return result;
}

long s21_atol(char *str) {
  long result = 0;
  while (*str >= '0' && *str <= '9') {
    result *= 10;
    result += *str++;
    result -= '0';
  }
  return result;
}

double s21_atof(const char *str) {
  double result = 0;
  int e = 0, ch;
  while ((ch = *str++) != '\0' && s21_isDigit(ch)) {
    result = result * 10.0 + (ch - '0');
  }
  if (ch == '.') {
    while ((ch = *str++) != '\0' && s21_isDigit(ch)) {
      result = result * 10 + (ch - '0');
      e--;
    }
  }
  if (ch == 'e' || ch == 'E') {
    int sign = 1;
    int i = 0;
    ch = *str++;
    if (ch == '-') {
      ch = *str++;
      sign = -1;
    } else if (ch == '+') {
      ch = *str++;
    }
    while (s21_isDigit(ch)) {
      i = i * 10 + (ch - '0');
      ch = *str++;
    }
    e += i * sign;
  }
  while (e > 0) {
    result *= 10;
    e--;
  }
  while (e < 0) {
    result *= 0.1;
    e++;
  }
  return result;
}

int s21_atof_length(const char *str) {
  int length = 0;
  char ch;
  while ((ch = *str++) != '\0' && s21_isDigit(ch)) {
    length++;
  }
  if (ch == '.') {
    length++;
    while ((ch = *str++) != '\0' && s21_isDigit(ch)) {
      length++;
    }
  }
  if (ch == 'e' || ch == 'E') {
    length++;
    ch = *str++;
  }
  if (ch == '-' || ch == '+') {
    length++;
    ch = *str++;
  }
  while (s21_isDigit(ch)) {
    length++;
    ch = *str++;
  }
  return length;
}
