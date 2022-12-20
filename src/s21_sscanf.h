#ifndef SRC_S21_SSCANF_H_
#define SRC_S21_SSCANF_H_

int s21_sscanf(const char *str, const char *format, ...);
int s21_checkFormatLine(char *format);
void s21_getSpecifier(char *format, char *tmpSpecifier);
void s21_setOptions(char *specifier, char *str);
char *s21_agregator(char *str, char *format, va_list ap);
char *s21_process_percent(char *str);
char *s21_process_c(char *str, va_list ap);
char *s21_process_s(char *str, va_list ap);
char *s21_process_u(char *str, char *format, va_list ap);
char *s21_process_d(char *str, char *format, va_list ap);
char *s21_process_o(char *str, char *format, va_list ap);
char *s21_process_x_p(char *str, char *format, va_list ap);
char *s21_process_i(char *str, char *format, va_list ap);
void s21_process_n(va_list ap);
char *s21_process_float(char *str, va_list ap);
void s21_write_s(const char *str, va_list ap);
void s21_write_u(char *format, va_list ap, unsigned long res);
void s21_write_sig_int(char *format, va_list ap, long res);
void s21_write_float(va_list ap, double result);
void s21_checkCountIteration();
int s21_checkSpecs(char c);
int s21_ifSpecNotFound(char c);
wchar_t *s21_strcpy_width(wchar_t *dest, const char *src);
int s21_skipSpaces(const char *str, const char *format);
int s21_skipSpacesFormat(char *str);
int s21_checkMinusPlus(const char *str);
char *s21_copyStrToBuff(char *dest, char *src);
long s21_convertDigitToOct(char *str);
long s21_convertDigitToHex(char *str);
unsigned long s21_convertDigitToUD(char *str);
char *s21_copyStrToDigit(char *digit, char *str, char *template);
void s21_copyStrToDigitHex(char *digit, char *str);
void s21_copyStrToDigitOct(char *digit, char *str);
void s21_copyStrToDigitDec(char *digit, char *str);
int s21_isPrefix_0(char *str);
int s21_isPrefix_0x(char *str);
int s21_isSpecFloat(char ch);
int s21_getLength(char *str);
int s21_isDigit(char c);

#endif  // SRC_S21_SSCANF_H_
