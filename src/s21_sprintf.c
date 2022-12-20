#include "s21_string.h"

char* revers(char* str, int i) {
  str[i] = '\0';
  for (int j = 0, k = s21_strlen(str) - 1, c; j < k; j++, k--) {
    c = str[j];
    str[j] = str[k];
    str[k] = c;
  }
  return str;
}

char* s21_int_to_string(long int number, long int floating) {
  int i = 1;
  char* str = calloc(32, sizeof(char));
  if (number < 0) number *= -1;
  if (number != 0) {
    while (number > 0) {
      str[i++ - 1] = (number % 10) + '0';
      number /= 10;
    }
  } else if (floating != 0) {
    str[i - 1] = '0';
  }
  return revers(str, i);
}

char* s21_add_sign(char* dest, char* src, int signed_conversion,
                   int space_signed_conversion, long int number) {
  if (number < 0 || (int)signed_conversion == 1) {
    dest = realloc(dest, s21_strlen(src) + 2);
    if (number < 0) {
      dest[0] = '-';
    } else {
      dest[0] = '+';
    }
    dest[1] = '\0';
  } else if (space_signed_conversion == 1) {
    dest = realloc(dest, s21_strlen(src) + 2);

    dest[0] = ' ';

    dest[1] = '\0';
  }
  return dest;
}

char* s21_add_zero(char* dest, char* src, int floating) {
  if ((int)floating <= (int)s21_strlen(src)) return dest;
  s21_size_t k = s21_strlen(dest);
  if (s21_strlen(dest)) floating++;
  dest = realloc(dest, (floating + 1) * sizeof(char));
  for (; k < (floating - s21_strlen(src)); k++) s21_strcat(dest, "0");
  dest[k] = '\0';
  return dest;
}

int s21_pow(int x, int y) {
  int temp = x;
  for (int i = 1; i < y; i++) temp *= x;
  return temp;
}

int s21_round(double y) { return (int)(y + 0.5); }

char* s21_float_to_string(long double number, int floating) {
  if (number < 0) number *= -1;
  int int_part = number;
  char* str = s21_int_to_string(int_part, 1);
  if (floating == 0) {
    const size_t offset = s21_strlen(str) - 1;
    if (int_part % 2 == 1)
      str[offset] = (((int)(number + 0.5) % 10) + '0');
    else
      str[offset] = (((int)number % 10) + '0');
  } else {
    number -= int_part;
    int f_len = (floating != -1) ? floating : 6;
    str[s21_strlen(str)] = '.';
    char* temp =
        s21_int_to_string(s21_round((1 + number) * s21_pow(10, f_len)), 1);
    for (int i = 0; i <= f_len - 1; i++) temp[i] = temp[i + 1];
    temp[f_len] = '\0';
    s21_strcat(str, temp);
    free(temp);
  }
  return str;
}

int s21_max(int a, int b) { return (a > b) ? a : b; }

char* s21_uint_to_string(unsigned long long number, long int floating) {
  int i = 0;
  char* str = calloc(32, sizeof(char));
  if (number != 0) {
    while (number > 0) {
      str[i++] = (number % 10) + '0';
      number /= 10;
    }
  } else if (floating != 0) {
    str[i] = '0';
  }
  return revers(str, i + 1);
}

char* s21_add_spaces(char* dest, s21sprintf* s21) {
  int str_len = s21_strlen(dest);
  if (str_len >= s21->width) return dest;
  char* temp = calloc(s21->width + 1, sizeof(char));
  int padding_len = s21->width - str_len;
  char* spc_ptr = calloc(padding_len + 1, sizeof(char));
  s21->fillnull > 0 ? s21_memset(spc_ptr, '0', padding_len)
                    : s21_memset(spc_ptr, ' ', padding_len);
  spc_ptr[padding_len] = 0;
  if (s21->fill_left == 1) {
    s21_strcat(temp, dest);
    s21_strcat(temp, spc_ptr);
  } else {
    s21_strcat(temp, spc_ptr);
    s21_strcat(temp, dest);
  }
  free(spc_ptr);
  free(dest);
  dest = temp;
  return dest;
}

void s21_reset_struct(s21sprintf* s21) {
  s21->format = 0;
  s21->fill_left = 0;
  s21->signed_conversion = 0;
  s21->space_signed_conversion = 0;
  s21->width = -1;
  s21->floating = -1;
  s21->h_flag = 0;
  s21->l_flag = 0;
  s21->L_flag = 0;
  s21->pointer = NULL;
  s21->octothorpe = 0;
  s21->fillnull = 0;
}

void fill_result(char* buf, char* result, s21sprintf* s21) {
  s21_strcat(buf, result);
  s21_reset_struct(s21);
  free(result);
}

void flag_persent(s21sprintf* s21, char* result, char* buf) {
  result = calloc(2, sizeof(char));
  result[0] = '%';
  fill_result(buf, result, s21);
}

void digital(const char* c, s21sprintf* s21) {
  if ((int)s21->floating == -1)
    s21->width = s21_atoi((char*)c);
  else if ((int)s21->floating == 0)
    s21->floating = s21_atoi((char*)c);
  if (c[0] == '0') s21->fillnull = 1;
}

void insert_and_free(s21sprintf* s21, char* temp, char* buf, char* result) {
  s21_strcat(result, temp);
  free(temp);
  result = s21_add_spaces(result, s21);
  fill_result(buf, result, s21);
}

void flag_i_d(s21sprintf* s21, char* temp, char* buf, char* result,
              long int d) {
  temp = s21_int_to_string(d, s21->floating);
  result = calloc(s21_strlen(temp) + 1, sizeof(char));
  result = s21_add_sign(result, temp, s21->signed_conversion,
                        s21->space_signed_conversion, d);
  result = s21_add_zero(result, temp, s21->floating);
  insert_and_free(s21, temp, buf, result);
}

void flag_f(s21sprintf* s21, char* temp, char* buf, char* result,
            long double f) {
  temp = s21_float_to_string(f, s21->floating);
  result = calloc(s21_strlen(temp) + 1, sizeof(char));

  result = s21_add_sign(result, temp, s21->signed_conversion,
                        s21->space_signed_conversion, f);
  insert_and_free(s21, temp, buf, result);
}

void flag_c(s21sprintf* s21, char* buf, char* result, wchar_t symbol) {
  result = calloc((s21->width != -1 ? s21->width : 0) + 2, sizeof(char));
  if (s21->width != -1 && s21->fill_left == 0) {
    for (int i = 0; i < s21->width; i++) {
      result[i] = ' ';
      if (i == s21->width - 1) result[i] = symbol;
    }
  } else if (s21->width != -1) {
    result[0] = symbol;
    for (int i = 1; i < s21->width; i++) result[i] = ' ';
  } else {
    result[0] = symbol;
  }
  fill_result(buf, result, s21);
}

void flag_s(s21sprintf* s21, char* string, char* buf, char* result) {
  int input_len = s21_strlen(string);
  if (s21->floating < input_len && s21->floating >= 0)
    input_len = s21->floating;
  int output_len = s21_max(s21->width, input_len);
  int padding_len = s21_max(0, s21->width - input_len);
  result = calloc(output_len + 1, sizeof(char));
  result[output_len] = '\0';
  char* s_ptr;
  char* p_ptr;
  if (s21->fill_left == 1) {
    s_ptr = &result[0];
    p_ptr = &result[input_len];
  } else {
    s_ptr = &result[padding_len];
    p_ptr = &result[0];
  }
  s21_memset(p_ptr, ' ', padding_len);
  s21_memcpy(s_ptr, string, input_len);
  fill_result(buf, result, s21);
}

void flag_u(s21sprintf* s21, char* temp, char* buf, char* result, uint64_t u) {
  if (s21->h_flag) {
    u = (uint16_t)u;
  } else if (s21->l_flag) {
    u = (uint64_t)u;
  } else {
    u = (uint32_t)u;
  }
  temp = s21_uint_to_string(u, s21->floating);
  result = calloc(s21_strlen(temp) + 1, sizeof(char));
  result = s21_add_zero(result, temp, s21->floating);
  insert_and_free(s21, temp, buf, result);
}

char* s21_hex_to_string(unsigned long int number, s21sprintf* s21, int hex,
                        char c) {
  int i = 1;
  char* str = calloc(20, sizeof(char));
  if (number != 0) {
    while (number > 0) {
      if (c == 'X')
        str[i++ - 1] = "0123456789ABCDEF"[number % hex];
      else
        str[i++ - 1] = "0123456789abcdef"[number % hex];
      hex = !hex ? 1 : hex;
      number /= hex;
    }
  } else if (s21->floating != 0) {
    str[i - 1] = '0';
  }
  if (s21->octothorpe == 1) {
    c == 'o' ? s21_strcat(str, "0") : s21_strcat(str, "x0");
    i++;
  }
  return revers(str, i);
}

char* s21_g_to_string(long double number, s21sprintf* s21, char c) {
  int point = (s21->floating != -1) ? s21->floating : 6;
  int count_e = 0;
  long double copy = number;
  if ((int)number == 0) {
    while ((int)number == 0) {
      number *= 10;
      count_e--;
    }
  } else {
    while ((int)number > 9) {
      number /= 10;
      count_e++;
    }
  }
  char* str = s21_float_to_string(number, point - 1);
  if ((count_e < 0 ? count_e * -1 : count_e) > point) {
    if (!s21->octothorpe) {
      for (int i = s21_strlen(str); str[i - 1] == '0'; i--) str[i - 1] = '\0';
    }
    if (count_e < 0 && c == 'g') s21_strcat(str, "e-");
    if (count_e < 0 && c == 'G') s21_strcat(str, "E-");
    if (count_e > 0 && c == 'g') s21_strcat(str, "e+");
    if (count_e > 0 && c == 'G') s21_strcat(str, "E+");
    if (count_e < 10) s21_strcat(str, "0");
    char* clear = s21_int_to_string(count_e, s21->floating);
    s21_strcat(str, clear);
    free(clear);
  } else {
    str = s21_float_to_string(
        copy, point - (count_e < 0 ? (1 + count_e * -1) : 1 + count_e));
    if (!s21->octothorpe) {
      for (int i = s21_strlen(str); str[i - 1] == '0'; i--) str[i - 1] = '\0';
    }
  }
  return str;
}

char* s21_e_to_string(long double number, int floating, char c) {
  int point = (floating != -1) ? floating : 6;
  int count_e = 0;
  if ((int)number == 0) {
    while ((int)number == 0) {
      number *= 10;
      count_e--;
    }
  } else {
    while ((int)number > 9) {
      number /= 10;
      count_e++;
    }
  }
  char* str = s21_float_to_string(number, point);
  if (count_e < 0 && c == 'e') s21_strcat(str, "e-");
  if (count_e < 0 && c == 'E') s21_strcat(str, "E-");
  if (count_e > 0 && c == 'e') s21_strcat(str, "e+");
  if (count_e > 0 && c == 'E') s21_strcat(str, "E+");
  if (count_e < 0) count_e *= -1;
  if (count_e < 10) s21_strcat(str, "0");
  char* clean = s21_int_to_string(count_e, floating);
  s21_strcat(str, clean);
  free(clean);
  return str;
}

void flag_g(s21sprintf* s21, char* temp, char* buf, char* result, long double f,
            char c) {
  temp = s21_g_to_string(f, s21, c);
  result = calloc(s21_strlen(temp) + 1, sizeof(char));

  result = s21_add_sign(result, temp, s21->signed_conversion,
                        s21->space_signed_conversion, f);
  insert_and_free(s21, temp, buf, result);
}

void flag_e(s21sprintf* s21, char* temp, char* buf, char* result, long double f,
            char c) {
  temp = s21_e_to_string(f, s21->floating, c);
  result = calloc(s21_strlen(temp) + 1, sizeof(char));

  result = s21_add_sign(result, temp, s21->signed_conversion,
                        s21->space_signed_conversion, f);
  insert_and_free(s21, temp, buf, result);
}

void flag_o(s21sprintf* s21, char* temp, char* buf, char* result,
            unsigned long int o) {
  temp = s21_hex_to_string(o, s21, 8, 'o');
  result = calloc(s21_strlen(temp) + 1, sizeof(char));
  result = s21_add_zero(result, temp, s21->floating);
  insert_and_free(s21, temp, buf, result);
}

void flag_x(s21sprintf* s21, char* temp, char* buf, char* result,
            unsigned long int o, char c) {
  temp = s21_hex_to_string(o, s21, 16, c);
  result = calloc(s21_strlen(temp) + 1, sizeof(char));
  result = s21_add_zero(result, temp, s21->floating);
  insert_and_free(s21, temp, buf, result);
}

int s21_sprintf(char* buf, const char* format, ...) {
  *buf = 0;
  va_list param;
  va_start(param, format);
  char* temp = NULL;
  char* result = NULL;
  long int d;
  long double f;
  wchar_t symbol;
  char* string;
  uint64_t u;
  s21sprintf s21;
  s21_reset_struct(&s21);
  int count_bytes;
  s21.pointer = (char*)format;
  for (const char* c = format; *c; c++) {
    if (*c == '\0') break;
    if (s21.format == 0 && *c != '%') {
      count_bytes = s21_strlen(buf);
      s21_strncat(buf, c, 1);
      continue;
    }
    if (s21.format == 0 && *c == '%') {
      s21.format = 1;
      s21.pointer = (char*)c;
      continue;
    }
    if (!s21.format) continue;
    if (*c == '%') flag_persent(&s21, result, buf);
    if (*c == '-') s21.fill_left = 1;
    if (*c == '+') s21.signed_conversion = 1;
    if (*c == ' ') s21.space_signed_conversion = 1;
    if (*c == '.') s21.floating = 0;
    if (*c == '#') s21.octothorpe = 1;
    if (*c == 'h') s21.h_flag = 1;
    if (*c == 'l') s21.l_flag = 1;
    if (*c == 'L') s21.L_flag = 1;
    if (*c == '1' || *c == '2' || *c == '3' || *c == '4' || *c == '5' ||
        *c == '6' || *c == '7' || *c == '8' || *c == '9' || *c == '0') {
      digital(c, &s21);
      while (*(c + 1) > 47 && *(c + 1) < 58) c++;
    }
    if (*c == 'i' || *c == 'd') {
      if (s21.h_flag)
        d = (short int)va_arg(param, int);
      else if (s21.l_flag)
        d = va_arg(param, long int);
      else
        d = va_arg(param, int);
      flag_i_d(&s21, temp, buf, result, d);
    }
    if (*c == 'f') {
      if (s21.L_flag)
        f = va_arg(param, long double);
      else
        f = va_arg(param, double);
      flag_f(&s21, temp, buf, result, f);
    }
    if (*c == 'c') {
      symbol = (char)va_arg(param, int);
      flag_c(&s21, buf, result, symbol);
    }
    if (*c == 's') {
      string = va_arg(param, char*);
      flag_s(&s21, string, buf, result);
    }
    if (*c == 'u') {
      u = va_arg(param, uint64_t);
      flag_u(&s21, temp, buf, result, u);
    }
    if (*c == 'o') {
      unsigned long int o = va_arg(param, unsigned long int);
      flag_o(&s21, temp, buf, result, o);
    }
    if (*c == 'x' || *c == 'X') {
      unsigned long int o = va_arg(param, unsigned long int);
      flag_x(&s21, temp, buf, result, o, *c);
    }
    if (*c == 'g' || *c == 'G') {
      if (s21.L_flag)
        f = va_arg(param, long double);
      else
        f = va_arg(param, double);
      flag_g(&s21, temp, buf, result, f, *c);
    }
    if (*c == 'e' || *c == 'E') {
      if (s21.L_flag)
        f = va_arg(param, long double);
      else
        f = va_arg(param, double);
      flag_e(&s21, temp, buf, result, f, *c);
    }
    if (*c == 'n') {
      int* num = va_arg(param, int*);
      *num = count_bytes;
      fill_result(buf, result, &s21);
    }
    if (*c == 'p') {
      uint64_t num = va_arg(param, uint64_t);
      s21_strcat(buf, "0x");
      fill_result(buf, s21_hex_to_string(num, &s21, 16, *c), &s21);
    }
    if (*c == '*') {
      int num = va_arg(param, int);
      if ((int)s21.floating == -1)
        s21.width = num;
      else if ((int)s21.floating == 0)
        s21.floating = num;
    }
  }
  va_end(param);
  return s21_strlen(buf);
}
