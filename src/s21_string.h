#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <limits.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_atoi.h"
#include "s21_sprintf.h"
#include "s21_sscanf.h"

#define s21_NULL ((void *)0)
typedef unsigned long s21_size_t;

// Main
void *s21_memchr(void const *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
s21_size_t s21_strlen(const char *str);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strspn(const char *str1, const char *str2);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strtok(char *str, const char *delim);
char *s21_strchr(const char *str, int c);
char *s21_strrchr(const char *str, int c);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strerror(int errnum);

// Bonus
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

// Helper
void s21_copyOf(char *dest, const char *src, s21_size_t n);
s21_size_t s21_maxLength(const char *s1, const char *s2);
void *s21_toUpLowSubFu(const char *str, int from, int to, int shift);
char *s21_trimEnd(char *ptr, const char *trim_chars);

#endif  // SRC_S21_STRING_H_
