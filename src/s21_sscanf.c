#include "s21_string.h"

char *SPECS = "cdieEfgGosuxXpn%";
char *LENGTHS = "hlL";
char *SPECS_FLOAT = "feEgG";

struct Options {
  int widthStatus;
  int countW;
  int skipStep;
  int length;
  int readedSymbols;
  int countIteration;
  int specN;
  int emptyStr;
  int errorConvertDigit;
  int minus;
  int percent;
} Options;

int s21_sscanf(const char *str, const char *format, ...) {
  va_list ap;
  va_start(ap, format);
  char *tmpFormat = (char *)format;
  char *tmpStr = (char *)str;
  while (*tmpFormat) {
    tmpFormat += s21_skipSpacesFormat(tmpFormat);
    Options.errorConvertDigit = 1;
    if (*tmpFormat == '%') {
      if (s21_checkFormatLine(++tmpFormat)) {
        char specifiers[256] = {0};
        s21_getSpecifier(tmpFormat, specifiers);
        tmpFormat += s21_strlen(specifiers) - 1;
        s21_setOptions(specifiers, tmpStr);
        tmpStr = s21_agregator(tmpStr, specifiers, ap);
        Options.readedSymbols = s21_strlen(str) - s21_strlen(tmpStr);
        s21_checkCountIteration();
      }
    }
    if (Options.errorConvertDigit) {
      break;
    }
    tmpFormat++;
  }
  va_end(ap);
  return !s21_strlen(str) ? -1 : Options.countIteration;
}

int s21_checkFormatLine(char *format) {
  return (!s21_checkSpecs(*format) && !s21_ifSpecNotFound(*format)) ? 0 : 1;
}

void s21_getSpecifier(char *format, char *tmpSpecifier) {
  while (*format) {
    if (s21_checkSpecs(*format)) {
      *tmpSpecifier = *format;
      break;
    }
    *tmpSpecifier++ = *format++;
  }
}

void s21_setOptions(char *specifier, char *str) {
  Options.countW = s21_atoi(specifier);
  Options.length = s21_getLength(specifier);
  Options.skipStep = (*specifier == '*') ? 1 : 0;
  Options.specN = (*specifier == 'n') ? 1 : 0;
  Options.emptyStr = !s21_strlen(str) ? 1 : 0;
  Options.errorConvertDigit = 0;
  Options.widthStatus = Options.countW > 0 ? 1 : 0;
  Options.minus = 1;
  Options.percent = 0;
}

char *s21_agregator(char *str, char *format, va_list ap) {
  str += s21_skipSpaces(str, format);
  char spec = format[s21_strlen(format) - 1];
  if (spec == '%') str = s21_process_percent(str);
  if (spec == 'c') str = s21_process_c(str, ap);
  if (spec == 's') str = s21_process_s(str, ap);
  if (spec == 'u') str = s21_process_u(str, format, ap);
  if (spec == 'd') str = s21_process_d(str, format, ap);
  if (spec == 'o') str = s21_process_o(str, format, ap);
  if (spec == 'x' || spec == 'X' || spec == 'p')
    str = s21_process_x_p(str, format, ap);
  if (spec == 'i') str = s21_process_i(str, format, ap);
  if (spec == 'n') s21_process_n(ap);
  if (s21_isSpecFloat(spec)) str = s21_process_float(str, ap);
  return str;
}

char *s21_process_percent(char *str) {
  if (*str == '%') {
    str++;
  } else {
    str += s21_strlen(str);
  }
  Options.percent = 1;
  return str;
}

char *s21_process_c(char *str, va_list ap) {
  if (!Options.skipStep) {
    if (!Options.length) {
      char *ch = va_arg(ap, char *);
      *ch = *str;
    } else {
      wchar_t *ch = va_arg(ap, wchar_t *);
      *ch = *str;
    }
  }
  return str + 1;
}

char *s21_process_s(char *str, va_list ap) {
  char *buff = calloc(s21_strlen(str) + 1, sizeof(char));
  s21_copyStrToBuff(buff, str);
  if (!Options.skipStep) {
    s21_write_s(buff, ap);
  }
  s21_size_t length = s21_strlen(buff);
  free(buff);
  return str + length;
}

char *s21_process_u(char *str, char *format, va_list ap) {
  unsigned long result = 0;
  str += s21_checkMinusPlus(str);
  char digit[16] = {0};
  s21_copyStrToDigitDec(digit, str);
  if (!s21_strlen(digit)) {
    Options.errorConvertDigit = 1;
  } else {
    result = s21_convertDigitToUD(digit);
  }
  if (!Options.skipStep) {
    s21_write_u(format, ap, result);
  }
  return str + s21_strlen(digit);
}

char *s21_process_d(char *str, char *format, va_list ap) {
  str += s21_checkMinusPlus(str);
  long result = 0;
  char digit[12] = {0};
  s21_copyStrToDigitDec(digit, str);
  if (!s21_strlen(digit)) {
    Options.errorConvertDigit = 1;
  } else {
    result = s21_atol(digit);
  }
  if (!Options.skipStep) {
    s21_write_sig_int(format, ap, result * Options.minus);
  }
  return str + (!s21_strlen(digit) ? 0 : s21_strlen(digit));
}

char *s21_process_o(char *str, char *format, va_list ap) {
  long result = 0;
  str += s21_checkMinusPlus(str);
  char digit[20] = {0};
  s21_copyStrToDigitOct(digit, str);
  str += s21_isPrefix_0(str) ? 1 : 0;
  result = !s21_strlen(digit) ? 0 : s21_convertDigitToOct(digit);
  if (!Options.skipStep) {
    s21_write_u(format, ap, result * Options.minus);
  }
  Options.errorConvertDigit = !s21_strlen(digit) ? 1 : 0;
  return str + s21_strlen(digit) - (s21_isPrefix_0(digit) ? 1 : 0);
}

char *s21_process_x_p(char *str, char *format, va_list ap) {
  long result = 0;
  str += s21_checkMinusPlus(str);
  char digit[20] = {0};
  s21_copyStrToDigitHex(digit, str);
  str += s21_isPrefix_0x(str) ? 2 : 0;
  result = !s21_strlen(digit) ? 0 : s21_convertDigitToHex(digit);
  if (!Options.skipStep) {
    s21_write_u(format, ap, result * Options.minus);
  }
  Options.errorConvertDigit = !s21_strlen(digit) ? 1 : 0;
  return str + s21_strlen(digit) - (s21_isPrefix_0x(digit) ? 2 : 0);
}

char *s21_process_i(char *str, char *format, va_list ap) {
  long result = 0;
  str += s21_checkMinusPlus(str);
  char digit[20] = {0};
  s21_copyStrToDigitHex(digit, str);
  if (s21_isPrefix_0(digit)) {
    char tmp[12] = {0};
    s21_copyStrToDigitOct(tmp, str);
    s21_strcpy(digit, tmp);
    str += 1;
    result = !s21_strlen(digit) ? 0 : s21_convertDigitToOct(digit);
  } else if (s21_isPrefix_0x(digit)) {
    str += 2;
    result = !s21_strlen(digit) ? 0 : s21_convertDigitToHex(digit);
  } else if (!s21_atol(digit)) {
    Options.errorConvertDigit = 1;
  } else {
    result = s21_atol(digit);
  }
  if (!Options.skipStep) {
    s21_write_sig_int(format, ap, result * Options.minus);
  }
  Options.errorConvertDigit = !s21_strlen(digit) ? 1 : 0;
  int shift = s21_isPrefix_0(digit) ? 1 : (s21_isPrefix_0x(digit) ? 2 : 0);
  return str + s21_strlen(digit) - shift;
}

void s21_process_n(va_list ap) {
  if (!Options.skipStep) {
    int *c = va_arg(ap, int *);
    *c = Options.readedSymbols;
  }
}

char *s21_process_float(char *str, va_list ap) {
  double result = 0;
  str += s21_checkMinusPlus(str);
  int length = s21_atof_length(str);
  char digit[40] = {0};
  length = Options.widthStatus ? Options.countW : length;
  s21_strncpy(digit, str, length);
  result = !s21_strlen(digit) ? 0 : s21_atof(digit);
  if (!Options.skipStep) {
    s21_write_float(ap, result * Options.minus);
  }
  Options.errorConvertDigit = !s21_strlen(digit) ? 1 : 0;
  return str + s21_strlen(digit);
}

void s21_write_s(const char *str, va_list ap) {
  char *destCh = s21_NULL;
  wchar_t *destWCh = s21_NULL;
  if (Options.length) {
    destWCh = va_arg(ap, wchar_t *);
    s21_strcpy_width(destWCh, str);
  } else {
    destCh = va_arg(ap, char *);
    s21_strcpy(destCh, str);
  }
}

void s21_write_u(char *format, va_list ap, unsigned long res) {
  if (!Options.length) {
    unsigned int *res_pointer = va_arg(ap, unsigned int *);
    *res_pointer = res;
  } else {
    char ch = format[s21_strlen(format) - 2];
    if (ch == 'l') {
      unsigned long *res_pointer = va_arg(ap, unsigned long *);
      *res_pointer = res;
    }
    if (ch == 'h') {
      unsigned short *res_pointer = va_arg(ap, unsigned short *);
      *res_pointer = res;
    }
  }
}

void s21_write_sig_int(char *format, va_list ap, long res) {
  if (!Options.length) {
    int *res_pointer = va_arg(ap, int *);
    *res_pointer = res;
  } else {
    char ch = format[s21_strlen(format) - 2];
    if (ch == 'l') {
      long *res_pointer = va_arg(ap, long *);
      *res_pointer = res;
    }
    if (ch == 'h') {
      short *res_pointer = va_arg(ap, short *);
      *res_pointer = res;
    }
  }
}

void s21_write_float(va_list ap, double result) {
  if (!Options.length) {
    float *ptr = va_arg(ap, float *);
    *ptr = (float)result;
  } else {
    long double *ptr = va_arg(ap, long double *);
    *ptr = result;
  }
}

void s21_checkCountIteration() {
  if (!Options.skipStep && !Options.specN && !Options.emptyStr &&
      !Options.errorConvertDigit) {
    Options.countIteration += Options.percent ? 0 : 1;
  }
}

int s21_checkSpecs(char c) {
  int result = 0;
  char *ptr = SPECS;
  while (*ptr) {
    if (*ptr == c) {
      result = 1;
      break;
    }
    ptr++;
  }
  return result;
}

int s21_ifSpecNotFound(char c) {
  return c == ' ' || c == '*' || (c >= '0' && c <= '9') || c == 'l' ||
         c == 'L' || c == 'h';
}

wchar_t *s21_strcpy_width(wchar_t *dest, const char *src) {
  while (*src != '\0') {
    *dest++ = *src++;
  }
  *dest = '\0';
  return dest;
}

int s21_skipSpaces(const char *str, const char *format) {
  int shift = 0;
  char ch = *format + s21_strlen(format) - 1;
  if (ch != 'c') {
    while (*str == ' ') {
      Options.readedSymbols++;
      str++;
      shift++;
    }
  }
  return shift;
}

int s21_skipSpacesFormat(char *str) {
  int length = 0;
  while (*str == ' ') {
    str++;
    length++;
  }
  return length;
}

int s21_checkMinusPlus(const char *str) {
  Options.minus = *str == '-' ? -1 : 1;
  if (*str == '-' || *str == '+') {
    Options.countW -= Options.widthStatus > 0 ? 1 : 0;
  }
  return (*str == '-' || *str == '+') ? 1 : 0;
}

char *s21_copyStrToBuff(char *dest, char *src) {
  int length = Options.widthStatus ? Options.countW : (int)s21_strlen(src);
  while (length-- > 0 && *src != ' ' && *src) {
    *dest++ = *src++;
  }
  *dest = '\0';
  return dest;
}

long s21_convertDigitToOct(char *str) {
  unsigned long result = 0;
  unsigned long basis = 1;
  str += s21_isPrefix_0(str) ? 1 : 0;
  int count = s21_strlen(str) - 1;
  str += count;
  while (count-- >= 0) {
    result += (*str - 48) * basis;
    str--;
    basis *= 8;
  }
  return result;
}

long s21_convertDigitToHex(char *str) {
  unsigned long result = 0;
  unsigned long basis = 1;
  str += s21_isPrefix_0x(str) ? 2 : 0;
  s21_size_t length = s21_strlen(str);
  if (length <= 16) {
    int num = 48, bigLet = 55, smLet = 87;
    int count = length - 1;
    str += count;
    unsigned long tmp = 0;
    while (count-- >= 0) {
      if (*str >= '0' && *str <= '9') {
        tmp = (*str - num);
      } else if (*str >= 'A' && *str <= 'F') {
        tmp = (*str - bigLet);
      } else if (*str >= 'a' && *str <= 'f') {
        tmp = (*str - smLet);
      }
      result += tmp * basis;
      str--;
      basis *= 16;
    }
  }
  return length > 16 ? 0xffffffff : result;
}

unsigned long s21_convertDigitToUD(char *str) {
  unsigned long result = strtoul(str, &str, 10);
  return Options.minus == -1 ? ULONG_MAX - result + 1 : result;
}

char *s21_copyStrToDigit(char *digit, char *str, char *template) {
  s21_size_t length = s21_strspn(str, template);
  length = Options.widthStatus ? (s21_size_t)Options.countW : length;
  while (length-- > 0) {
    *digit++ = *str++;
  }
  return digit;
}

void s21_copyStrToDigitHex(char *digit, char *str) {
  s21_copyStrToDigit(digit, str, "0xX123456789abcdefABCDEF");
}

void s21_copyStrToDigitOct(char *digit, char *str) {
  s21_copyStrToDigit(digit, str, "01234567");
}

void s21_copyStrToDigitDec(char *digit, char *str) {
  s21_copyStrToDigit(digit, str, "0123456789");
}

int s21_isPrefix_0(char *str) {
  char ch = *(str + 1);
  return *str == '0' && ch != 'x' && ch != 'X' && ch != ' ';
}

int s21_isPrefix_0x(char *str) {
  char ch = *(str + 1);
  return *str == '0' && (ch == 'x' || ch == 'X');
}

int s21_isSpecFloat(char ch) { return !s21_strchr(SPECS_FLOAT, ch) ? 0 : 1; }

int s21_getLength(char *str) { return !s21_strpbrk(str, LENGTHS) ? 0 : 1; }

int s21_isDigit(char c) { return c >= '0' && c <= '9'; }
