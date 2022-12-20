#include "s21_string.h"

#include "s21_errors.h"

// возвращает длину строки
s21_size_t s21_strlen(const char *str) {
  s21_size_t size = 0;
  if (str) {
    while (*str) {
      str++;
      size++;
    }
  }
  return size;
}

// возвращает указатель на первый с в str
char *s21_strchr(const char *str, int c) {
  char *ptr = s21_NULL;
  while (*str != '\0') {
    if (*str == c) {
      ptr = (char *)str;
      break;
    }
    str++;
  }
  if (*str == c) {
    ptr = (char *)str;
  }
  return ptr;
}

// возвращает указатель на последний с в str
char *s21_strrchr(const char *str, int c) {
  char *ptr = s21_NULL;
  int length = (int)s21_strlen(str);
  str += length;
  while (length >= 0) {
    if (*str == c) {
      ptr = (char *)str;
      break;
    }
    str--;
    length--;
  }
  if (*str == c) {
    ptr = (char *)str;
  }
  return ptr;
}

// копирует src в dest
char *s21_strcpy(char *dest, const char *src) {
  char *ptr = dest;
  s21_memcpy(dest, src, s21_strlen(src));
  dest += s21_strlen(src);
  *dest = '\0';
  return ptr;
}

// копирует src в dest первые n байт или до первого '\0', если n > длины src и
// разницу заполнит '\0'
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *ptr = dest;
  s21_size_t srcLen = s21_strlen(src);
  s21_size_t len = n > srcLen ? srcLen : n;
  s21_memcpy(dest, src, n);
  dest += len;
  if (n > srcLen) {
    s21_memset(dest, '\0', n - srcLen);
  } else {
    *dest = '\0';
  }
  return ptr;
}

// копирует src в dest строго первые n байт, не обращая внимания на '\0'
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *iter = (char *)dest;
  char *ptrDest = iter;
  char *ptrSrc = (char *)src;
  while (n-- > 0) {
    *iter++ = *ptrSrc++;
  }
  return ptrDest;
}

// аналогичен s21_memcpy, но использует временный указатель, чтобы
// избежать вероятности затирания
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *ptrDest = (char *)dest;
  char *ptrSrc = (char *)src;
  char *ptrTmp = calloc(s21_strlen(src) + s21_strlen(dest) + 1, sizeof(char));
  s21_copyOf(ptrTmp, ptrSrc, n);
  s21_copyOf(ptrDest, ptrTmp, n);
  free(ptrTmp);
  return dest;
}

// возвращает указатель на первое вхождение needle в haystack
char *s21_strstr(const char *haystack, const char *needle) {
  s21_size_t needLen = s21_strlen(needle);
  while (s21_strlen(haystack) >= needLen &&
         s21_strncmp(haystack, needle, needLen) != 0) {
    haystack++;
  }
  return !s21_strncmp(haystack, needle, needLen) ? (char *)haystack : s21_NULL;
}

// возвращает указатель на первый символ в строке str1, который соответствует
// любому символу, указанному в str2.
char *s21_strpbrk(const char *str1, const char *str2) {
  str1 = str1 + s21_strcspn(str1, str2);
  return !s21_strlen(str1) ? s21_NULL : (char *)str1;
}

// возвращает количество символов отрезка str1, который полностью состоит из
// str2
s21_size_t s21_strspn(const char *str1, const char *str2) {
  int countMatch = 0;
  while (s21_strchr(str2, *str1) && *str1++ != '\0') {
    countMatch++;
  }
  return countMatch;
}

// возвращает количество символов отрезка str1, который полностью не состоит из
// str2
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  int countNonMatch = 0;
  while (!s21_strchr(str2, *str1) && *str1++ != '\0') {
    countNonMatch++;
  }
  return countNonMatch;
}

// заполняет первые n байт str символами c
void *s21_memset(void *str, int c, s21_size_t n) {
  char *ptr = (char *)str;
  while (n-- > 0) {
    *ptr++ = c;
  }
  return str;
}

// объединяет dest и src
char *s21_strcat(char *dest, const char *src) {
  return s21_strncat(dest, src, s21_strlen(src));
}

// объединяет dest и src до n или '\0', если n > длины src
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t lenSrc = s21_strlen(src);
  n = n > lenSrc ? lenSrc : n;
  char *ptr = dest;
  dest += s21_strlen(dest);
  s21_strncpy(dest, src, n);
  return ptr;
}

// возвращает указатель на найденный c в src в первых n байтах или null,
// игнорируя '\0'
void *s21_memchr(void const *str, int c, s21_size_t n) {
  char *iter = (char *)str;
  char *tmp = s21_NULL;
  while (n-- > 0) {
    if (*iter == c) {
      tmp = iter;
      break;
    }
    iter++;
  }
  return tmp;
}

// возвращает разницу между первыми не идентичными символами или 0
int s21_strcmp(const char *str1, const char *str2) {
  return s21_memcmp(str1, str2, s21_maxLength(str1, str2));
}

// возвращает разницу между первыми не идентичными символами или 0 на участке в
// n байт или до первого '\0'
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  s21_size_t maxLength = s21_maxLength(str1, str2);
  return s21_memcmp(str1, str2, n > maxLength ? maxLength : n);
}

// возвращает разницу между первыми не идентичными символами или 0 на участке в
// n байт, игнорируя '\0'
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  char *ptr1 = (char *)str1;
  char *ptr2 = (char *)str2;
  while (n-- > 0) {
    if ((*ptr1 != *ptr2)) {
      result = *ptr1 - *ptr2;
      break;
    }
    ptr1++;
    ptr2++;
  }
  return result;
}

// возвращает указатель на str, в которой изъято первое вхождение delim или
// первое и второе, если встречается случай "delim...delim..."
char *s21_strtok(char *str, const char *delim) {
  static char *res;
  str = !str ? res : str;
  str += s21_strspn(str, delim);
  res = str + s21_strcspn(str, delim);
  if (s21_strpbrk(res, delim) != s21_NULL) {
    *res++ = '\0';
  } else {
    *res = '\0';
  }
  str = (*str == '\0') ? s21_NULL : str;
  return str;
}

// возвращает сообщение об ошибке
char *s21_strerror(int errnum) {
  static char result[30] = {0};
  if (errnum >= 0 && errnum < NUM_ERRORS) {
    s21_strcpy(result, errors[errnum]);
  } else {
    s21_sprintf(result, "%s%d", ERR_MSG, errnum);
  }
  return result;
}

// вставляет str в src на позицию start_index при условии, что
// start_index <= длины src
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *ptr = s21_NULL;
  s21_size_t lenSrc = s21_strlen(src);
  s21_size_t lenStr = s21_strlen(str);
  if (str && start_index <= lenSrc) {
    ptr = calloc(lenSrc + lenStr + 1, sizeof(char));
    if (ptr) {
      s21_strcpy(ptr, src);
      s21_memmove(ptr + start_index + lenStr, ptr + start_index,
                  lenSrc - start_index);
      s21_memmove(ptr + start_index, str, lenStr);
    }
  }
  return ptr;
}
// удаляет с обеих сторон src trim_chars
void *s21_trim(const char *src, const char *trim_chars) {
  char *ptr = s21_NULL;
  if (src) {
    ptr = calloc(s21_strlen(src) + 1, sizeof(char));
    if (ptr) {
      src += s21_strspn(src, trim_chars);
      s21_strcpy(ptr, src);
      if (s21_strlen(ptr) > 0) {
        s21_trimEnd(ptr, trim_chars);
      }
    }
  }
  return ptr;
}

// переводит str в нижний регистр
void *s21_to_lower(const char *str) {
  return s21_toUpLowSubFu(str, 65, 90, 32);
}

// переводит str в верхний регистр
void *s21_to_upper(const char *str) {
  return s21_toUpLowSubFu(str, 97, 122, -32);
}

s21_size_t s21_maxLength(const char *s1, const char *s2) {
  return s21_strlen(s1) > s21_strlen(s2) ? s21_strlen(s1) : s21_strlen(s2);
}

void s21_copyOf(char *dest, const char *src, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) {
    dest[i] = src[i];
  }
}
char *s21_trimEnd(char *ptr, const char *trim_chars) {
  s21_size_t lenPtr = s21_strlen(ptr);
  s21_size_t lenTrim = s21_strlen(trim_chars);
  for (s21_size_t i = lenPtr - 1; i; i--) {
    int count = 0;
    for (s21_size_t j = 0; j < lenTrim; j++) {
      if (ptr[i] == trim_chars[j]) {
        count++;
        break;
      }
    }
    if (count) {
      ptr[i] = '\0';
    } else {
      break;
    }
  }
  return ptr;
}

void *s21_toUpLowSubFu(const char *str, int from, int to, int shift) {
  char *ptr = s21_NULL;
  if (str) {
    ptr = calloc(s21_strlen(str) + 1, sizeof(char));
    if (ptr) {
      s21_strcpy(ptr, str);
      char *iter = ptr;
      while (*iter) {
        if (*iter >= from && *iter <= to) {
          *iter += shift;
        }
        iter++;
      }
    }
  }
  return ptr;
}
