#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_

typedef struct s21sprintf {
  int format;
  int fill_left;
  int signed_conversion;
  int space_signed_conversion;
  int width;
  int floating;
  int h_flag;
  int l_flag;
  int L_flag;
  char* pointer;
  int octothorpe;
  int fillnull;
} s21sprintf;

int s21_sprintf(char* buf, const char* format, ...);
char* revers(char* str, int i);
char* s21_int_to_string(long int number, long int floating);
char* s21_add_sign(char* dest, char* src, int signed_conversion,
                   int space_signed_conversion, long int number);
char* s21_add_zero(char* dest, char* src, int floating);
int s21_pow(int x, int y);
int s21_round(double y);
char* s21_float_to_string(long double number, int floating);
int s21_max(int a, int b);
char* s21_uint_to_string(unsigned long long number, long int floating);
char* s21_add_spaces(char* dest, s21sprintf* s21);
void s21_reset_struct(s21sprintf* s21);
void fill_result(char* buf, char* result, s21sprintf* s21);
void flag_persent(s21sprintf* s21, char* result, char* buf);
void digital(const char* c, s21sprintf* s21);
void insert_and_free(s21sprintf* s21, char* temp, char* buf, char* result);
void flag_i_d(s21sprintf* s21, char* temp, char* buf, char* result, long int d);
void flag_f(s21sprintf* s21, char* temp, char* buf, char* result,
            long double f);
void flag_c(s21sprintf* s21, char* buf, char* result, wchar_t symbol);
void flag_s(s21sprintf* s21, char* string, char* buf, char* result);
void flag_u(s21sprintf* s21, char* temp, char* buf, char* result, uint64_t u);
char* s21_hex_to_string(unsigned long int number, s21sprintf* s21, int hex,
                        char c);
char* s21_g_to_string(long double number, s21sprintf* s21, char c);
char* s21_e_to_string(long double number, int floating, char c);
void flag_g(s21sprintf* s21, char* temp, char* buf, char* result, long double f,
            char c);
void flag_o(s21sprintf* s21, char* temp, char* buf, char* result,
            unsigned long int o);
void flag_x(s21sprintf* s21, char* temp, char* buf, char* result,
            unsigned long int o, char c);

#endif  // SRC_S21_SPRINTF_H_
