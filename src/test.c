#include <check.h>
#include <string.h>

#include "s21_string.h"

char buf_for_sprintf[70];
char buf_for_s21_sprintf[70];

START_TEST(s21_memchr_test1) {
#line 9
  char str[50] = "12345";
  ck_assert_ptr_eq(memchr(str, '1', 5), s21_memchr(str, '1', 5));
}
END_TEST

START_TEST(s21_memchr_test2) {
#line 13
  char str[50] = "12345";
  ck_assert_ptr_eq(memchr(str, '5', 1), s21_memchr(str, '5', 1));
}
END_TEST

START_TEST(s21_memchr_test3) {
#line 17
  char str[50] = "asAAAsdag";
  ck_assert_ptr_eq(memchr(str, 65, 9), s21_memchr(str, 65, 9));
}
END_TEST

START_TEST(s21_memchr_test4) {
#line 21
  char str[50] = "asAAAsdag";
  ck_assert_ptr_eq(memchr(str, 65, 1), s21_memchr(str, 65, 1));
}
END_TEST

START_TEST(s21_memchr_test5) {
#line 25
  char str[50] = "asAAAsdag";
  ck_assert_ptr_eq(memchr(str, 65, 0), s21_memchr(str, 65, 0));
}
END_TEST

START_TEST(s21_memchr_test6) {
#line 29
  char str[50] = "645 gfhjkh";
  ck_assert_ptr_eq(memchr(str, ' ', 3), s21_memchr(str, ' ', 3));
}
END_TEST

START_TEST(s21_memchr_test7) {
#line 33
  char str[50] = "645 gf\nhjkh";
  ck_assert_ptr_eq(memchr(str, '\n', 3), s21_memchr(str, '\n', 3));
}
END_TEST

START_TEST(s21_memchr_test8) {
#line 37
  char str[50] = "HELLO!\056789";
  ck_assert_ptr_eq(memchr(str, '!', 6), s21_memchr(str, '!', 6));
}
END_TEST

START_TEST(s21_memchr_test9) {
#line 41
  char str[50] = "HELLO!\056789";
  ck_assert_ptr_eq(memchr(str, '!', 5), s21_memchr(str, '!', 5));
}
END_TEST

START_TEST(s21_memchr_test10) {
#line 45
  char str[50] = "\0/r\v/n";
  ck_assert_ptr_eq(memchr(str, 'v', 5), s21_memchr(str, 'v', 5));
}
END_TEST

START_TEST(s21_memchr_test11) {
#line 49
  char str[50] = "";
  ck_assert_ptr_eq(memchr(str, '0', 1), s21_memchr(str, '0', 1));
}
END_TEST

START_TEST(s21_memchr_test12) {
#line 53
  char str[50] = "@#WEETggT";
  ck_assert_ptr_eq(memchr(str, 'T', 9), s21_memchr(str, 'T', 9));
}
END_TEST

START_TEST(s21_memcmp_test1) {
#line 57
  char str1[50] = "12345a s6789";
  char str2[50] = "12345a s6789";
  ck_assert_int_eq(memcmp(str1, str2, 12), s21_memcmp(str1, str2, 12));
}
END_TEST

START_TEST(s21_memcmp_test2) {
#line 62
  char str1[50] = "12345a s6789";
  char str2[50] = "12345a s6789";
  ck_assert_int_eq(memcmp(str1, str2, 1), s21_memcmp(str1, str2, 1));
}
END_TEST

START_TEST(s21_memcmp_test3) {
#line 67
  char str1[50] = "12345a s6789";
  char str2[50] = "12345a s6789";
  ck_assert_int_eq(memcmp(str1, str2, 7), s21_memcmp(str1, str2, 7));
}
END_TEST

START_TEST(s21_memcmp_test4) {
#line 72
  char str1[50] = "12345a s6789";
  char str2[50] = "12345a s6789";
  ck_assert_int_eq(memcmp(str1, str2, 0), s21_memcmp(str1, str2, 0));
}
END_TEST

START_TEST(s21_memcmp_test5) {
#line 77
  char str1[50] = "Hello/0World";
  char str2[50] = "Hello/0World";
  ck_assert_int_eq(memcmp(str1, str2, 9), s21_memcmp(str1, str2, 9));
}
END_TEST

START_TEST(s21_memcmp_test6) {
#line 82
  char str1[50] = "Hello/0\n\0\n\0World\\01234";
  char str2[50] = "Hello/0\n\0\n\0World\\01234";
  ck_assert_int_eq(memcmp(str1, str2, 19), s21_memcmp(str1, str2, 19));
}
END_TEST

START_TEST(s21_memcmp_test7) {
#line 87
  char str1[50] = "Hello/0\n\0\n\0World\\01234";
  char str2[50] = "Hello/0\n\0\n\0World\\43210";
  ck_assert_int_eq(memcmp(str1, str2, 19), s21_memcmp(str1, str2, 19));
}
END_TEST

START_TEST(s21_memcmp_test8) {
#line 92
  char str1[50] = " \0 \0 \0 4___r";
  char str2[50] = " \0 \0 \0 4__ _r";
  ck_assert_int_eq(memcmp(str1, str2, 11), s21_memcmp(str1, str2, 11));
}
END_TEST

START_TEST(s21_memcmp_test9) {
#line 97
  char str1[50] = " \0 \0 \0 4___r";
  char str2[50] = " \0 \0 \0 4__ _r";
  ck_assert_int_eq(memcmp(str1, str2, 5), s21_memcmp(str1, str2, 5));
}
END_TEST

START_TEST(s21_memcmp_test10) {
#line 102
  char str1[50] = "Hello\0World";
  char str2[50] = "Hello\0Rorld";
  ck_assert_int_eq(memcmp(str1, str2, 5), s21_memcmp(str1, str2, 5));
}
END_TEST

START_TEST(s21_memcmp_test11) {
#line 107
  char str1[50] = "Hello\0World";
  char str2[50] = "Hello\0Rorld";
  ck_assert_int_eq(memcmp(str1, str2, 9), s21_memcmp(str1, str2, 9));
}
END_TEST

START_TEST(s21_memset_test1) {
#line 112
  char str[50] = "123456789";
  ck_assert_ptr_eq(memset(str, '0', 1), s21_memset(str, '0', 1));
}
END_TEST

START_TEST(s21_memset_test2) {
#line 116
  char str[50] = "123456789";
  ck_assert_ptr_eq(memset(str, '0', 1), s21_memset(str, '0', 1));
}
END_TEST

START_TEST(s21_memset_test3) {
#line 120
  char str[50] = "123456789";
  ck_assert_ptr_eq(memset(str, '0', 4), s21_memset(str, '0', 4));
}
END_TEST

START_TEST(s21_memset_test4) {
#line 124
  char str[50] = "123456789";
  ck_assert_ptr_eq(memset(str, '0', 1), s21_memset(str, '0', 1));
}
END_TEST

START_TEST(s21_memset_test5) {
#line 128
  char str[50] = "123456789";
  ck_assert_ptr_eq(memset(str, '0', 9), s21_memset(str, '0', 9));
}
END_TEST

START_TEST(s21_memset_test6) {
#line 132
  char str[50] = "123456789";
  ck_assert_ptr_eq(memset(str, '0', 12), s21_memset(str, '0', 12));
}
END_TEST

START_TEST(s21_memset_test7) {
#line 136
  char str[50] = "123456789";
  ck_assert_ptr_eq(memset(str, 't', 3), s21_memset(str, 't', 3));
}
END_TEST

START_TEST(s21_memset_test8) {
#line 140
  char str[50] = "123456789";
  ck_assert_ptr_eq(memset(str, '\0', 8), s21_memset(str, '\0', 8));
}
END_TEST

START_TEST(s21_memset_test9) {
#line 144
  char str[50] = "40 $$V%TWCERTWr Ywrywer wert EQ";
  ck_assert_ptr_eq(memset(str, 'g', 10), s21_memset(str, 'g', 10));
}
END_TEST

START_TEST(s21_memset_test10) {
#line 148
  char str[50] = "1234\056789";
  ck_assert_ptr_eq(memset(str, '0', 4), s21_memset(str, '0', 4));
}
END_TEST

START_TEST(s21_memset_test11) {
#line 152
  char str[50] = "1234\056789";
  ck_assert_ptr_eq(memset(str, '0', 5), s21_memset(str, '0', 5));
}
END_TEST

START_TEST(s21_memset_test12) {
#line 156
  char str[50] = "1234\056789";
  ck_assert_ptr_eq(memset(str, '0', 6), s21_memset(str, '0', 6));
}
END_TEST

START_TEST(s21_memset_test13) {
#line 160
  char str[50] = "";
  ck_assert_ptr_eq(memset(str, 'y', 1), s21_memset(str, 'y', 1));
}
END_TEST

START_TEST(s21_memcpy_test1) {
#line 164
  char str1[50] = "123456789";
  char str2[50] = "40 $$V%TWCERTWr Ywrywer wert EQ";
  ck_assert_ptr_eq(memcpy(str1, str2, 0), s21_memcpy(str1, str2, 0));
}
END_TEST

START_TEST(s21_memcpy_test2) {
#line 169
  char str1[50] = "123456789";
  char str2[50] = "40 $$V%TWCERTWr Ywrywer wert EQ";
  ck_assert_ptr_eq(memcpy(str1, str2, 9), s21_memcpy(str1, str2, 9));
}
END_TEST

START_TEST(s21_memcpy_test3) {
#line 174
  char str1[50] = "123456789";
  char str2[50] = "40 $$V%TWCERTWr Ywrywer wert EQ";
  ck_assert_ptr_eq(memcpy(str1, str2, 20 - 4), s21_memcpy(str1, str2, 20 - 4));
}
END_TEST

START_TEST(s21_memcpy_test4) {
#line 179
  char str1[50] = "";
  char str2[50] = "1234\056789";
  ck_assert_ptr_eq(memcpy(str1, str2, 4), s21_memcpy(str1, str2, 4));
}
END_TEST

START_TEST(s21_memcpy_test5) {
#line 184
  char str1[50] = "";
  char str2[50] = "1234\056789";
  ck_assert_ptr_eq(memcpy(str1, str2, 2 * 4), s21_memcpy(str1, str2, 2 * 4));
}
END_TEST

START_TEST(s21_memcpy_test6) {
#line 189
  char str1[50] = "1234\056789";
  char str2[50] = "123456789";
  ck_assert_ptr_eq(memcpy(str1, str2, 9), s21_memcpy(str1, str2, 9));
}
END_TEST

START_TEST(s21_memcpy_test7) {
#line 194
  char str1[50] = "1234\056789";
  char str2[50] = "123456789";
  ck_assert_ptr_eq(memcpy(str1, str2, 1), s21_memcpy(str1, str2, 1));
}
END_TEST

START_TEST(s21_memcpy_test8) {
#line 199
  char str1[50] = "1234\056789";
  char str2[50] = "123456789";
  ck_assert_ptr_eq(memcpy(str1, str2, 0), s21_memcpy(str1, str2, 0));
}
END_TEST

START_TEST(s21_memcpy_test9) {
#line 204
  char str1[50] = "\0";
  char str2[50] = "1234\056789";
  ck_assert_ptr_eq(memcpy(str1, str2, 1), s21_memcpy(str1, str2, 1));
}
END_TEST

START_TEST(s21_memcpy_test10) {
#line 209
  char str1[50] = "1";
  char str2[50] = "\0";
  ck_assert_ptr_eq(memcpy(str1, str2, 1), s21_memcpy(str1, str2, 1));
}
END_TEST

START_TEST(s21_memcpy_test11) {
#line 214
  char str1[50] = "\0\0\0\0\0";
  char str2[50] = "123456789";
  ck_assert_ptr_eq(memcpy(str1, str2, 3), s21_memcpy(str1, str2, 3));
}
END_TEST

START_TEST(s21_memcpy_test12) {
#line 219
  char str1[50] = " 123456789qqq";
  char str2[50] = "   asdf\0Z\0-";
  ck_assert_ptr_eq(memcpy(str1, str2, 8), s21_memcpy(str1, str2, 8));
}
END_TEST

START_TEST(s21_memmove_test1) {
#line 224
  char str1[50] = "123456789";
  char str2[50] = "40 $$V%TWCERTWr Ywrywer wert EQ";
  ck_assert_ptr_eq(memmove(str1, str2, 0), s21_memmove(str1, str2, 0));
}
END_TEST

START_TEST(s21_memmove_test2) {
#line 229
  char str1[50] = "123456789";
  char str2[50] = "40 $$V%TWCERTWr Ywrywer wert EQ";
  ck_assert_ptr_eq(memmove(str1, str2, 9), s21_memmove(str1, str2, 9));
}
END_TEST

START_TEST(s21_memmove_test3) {
#line 234
  char str1[50] = "123456789";
  char str2[50] = "40 $$V%TWCERTWr Ywrywer wert EQ";
  ck_assert_ptr_eq(memmove(str1, str2, 20 - 4),
                   s21_memmove(str1, str2, 20 - 4));
}
END_TEST

START_TEST(s21_memmove_test4) {
#line 239
  char str1[50] = "";
  char str2[50] = "1234\056789";
  ck_assert_ptr_eq(memmove(str1, str2, 4), s21_memmove(str1, str2, 4));
}
END_TEST

START_TEST(s21_memmove_test5) {
#line 244
  char str1[50] = "";
  char str2[50] = "1234\056789";
  ck_assert_ptr_eq(memmove(str1, str2, 2 * 4), s21_memmove(str1, str2, 2 * 4));
}
END_TEST

START_TEST(s21_memmove_test6) {
#line 249
  char str1[50] = "";
  char str2[50] = "123456789";
  ck_assert_ptr_eq(memmove(str1, str2, 9), s21_memmove(str1, str2, 9));
}
END_TEST

START_TEST(s21_memmove_test7) {
#line 254
  char str1[50] = "";
  char str2[50] = "123456789";
  ck_assert_ptr_eq(memmove(str1, str2, 1), s21_memmove(str1, str2, 1));
}
END_TEST

START_TEST(s21_memmove_test8) {
#line 259
  char str1[50] = "";
  char str2[50] = "123456789";
  ck_assert_ptr_eq(memmove(str1, str2, 0), s21_memmove(str1, str2, 0));
}
END_TEST

START_TEST(s21_memmove_test9) {
#line 264
  char str1[50] = "\0";
  char str2[50] = "123456789";
  ck_assert_ptr_eq(memmove(str1, str2, 1), s21_memmove(str1, str2, 1));
}
END_TEST

START_TEST(s21_memmove_test10) {
#line 269
  char str[50] = "123456789";
  ck_assert_ptr_eq(memmove(str + 5, str + 1, 8),
                   s21_memmove(str + 5, str + 1, 8));
}
END_TEST

START_TEST(s21_memmove_test11) {
#line 274
  char str[50] = "123456789";
  ck_assert_ptr_eq(memmove(str + 2, str + 6, 4),
                   s21_memmove(str + 2, str + 6, 4));
}
END_TEST

START_TEST(s21_memmove_test12) {
#line 279
  char str1[50] = "  abcdef  ";
  char str2[50] = "123\04567";
  ck_assert_ptr_eq(memmove(str1, str2, 4), s21_memmove(str1, str2, 4));
}
END_TEST

START_TEST(s21_memmove_test13) {
#line 284
  char str1[50] = "  abcdef  ";
  char str2[50] = "123\04567";
  ck_assert_ptr_eq(memmove(str1, str2, 7), s21_memmove(str1, str2, 7));
}
END_TEST

START_TEST(s21_memmove_test14) {
#line 289
  char str1[50] = "1234567";
  char str2[50] = "1234567";
  ck_assert_ptr_eq(memmove(str1 + 7, str2, 7), s21_memmove(str1 + 7, str2, 7));
}
END_TEST

START_TEST(s21_memmove_test15) {
#line 294
  char str1[50] = "1234567";
  char str2[50] = "1234567";
  ck_assert_ptr_eq(memmove(str1 + 3, str2 + 7, 1),
                   s21_memmove(str1 + 3, str2 + 7, 1));
}
END_TEST

START_TEST(s21_strlen_test1) {
#line 300
  char str[50] = "12345";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test2) {
#line 304
  char str[50] = "1";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test3) {
#line 308
  char str[50] = "";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test4) {
#line 312
  char str[50] = "12345\n67890";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test5) {
#line 316
  char str[50] = "asasf )(*&^%$#@!@#$%^&\":?.{P|}{P:\\/\\})   FG   H";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test6) {
#line 320
  char str[50] = "1234\05";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test7) {
#line 324
  char str[50] = "\012345";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test8) {
#line 328
  char str[50] = "\0";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strcmp_test1) {
#line 332
  char str1[50] = "12345a s6789";
  char str2[50] = "12345a s6789";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(s21_strcmp_test2) {
#line 337
  char str1[50] = "1";
  char str2[50] = "1";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(s21_strcmp_test3) {
#line 342
  char str1[50] = "1";
  char str2[50] = "2";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(s21_strcmp_test4) {
#line 347
  char str1[50] = "12";
  char str2[50] = "2";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(s21_strcmp_test5) {
#line 352
  char str1[50] = "";
  char str2[50] = "1";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(s21_strcmp_test6) {
#line 357
  char str1[50] = "y";
  char str2[50] = "";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(s21_strcmp_test7) {
#line 362
  char str1[50] = "";
  char str2[50] = "";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(s21_strcmp_test8) {
#line 367
  char str1[50] = "aSdfgh";
  char str2[50] = "aSdfgh";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(s21_strcmp_test9) {
#line 372
  char str1[50] = "aSdfgh";
  char str2[50] = "aSdfigh";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(s21_strcmp_test10) {
#line 377
  char str1[50] = "1a2s3d4f";
  char str2[50] = "1a2s3d\n4f";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(s21_strcmp_test11) {
#line 382
  char str1[50] = "1a2s3d4f";
  char str2[50] = "1a2s3d\04f";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(s21_strcmp_test12) {
#line 387
  char str1[50] = "\01a2s3d4f";
  char str2[50] = "1a2s3d4f";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(s21_strncmp_test1) {
#line 392
  char str1[50] = "123456789a";
  char str2[50] = "123456789b";
  ck_assert_int_eq(strncmp(str1, str2, 10), s21_strncmp(str1, str2, 10));
}
END_TEST

START_TEST(s21_strncmp_test2) {
#line 397
  char str1[50] = "123456789a";
  char str2[50] = "123456789b";
  ck_assert_int_eq(strncmp(str1, str2, 11), s21_strncmp(str1, str2, 11));
}
END_TEST

START_TEST(s21_strncmp_test3) {
#line 402
  char str1[50] = "123456789a";
  char str2[50] = "123456789b";
  ck_assert_int_eq(strncmp(str1, str2, 1), s21_strncmp(str1, str2, 1));
}
END_TEST

START_TEST(s21_strncmp_test4) {
#line 407
  char str1[50] = "Hello World!";
  char str2[50] = "HelloWorld!";
  ck_assert_int_eq(strncmp(str1, str2, 5), s21_strncmp(str1, str2, 5));
}
END_TEST

START_TEST(s21_strncmp_test5) {
#line 412
  char str1[50] = "Hello World!";
  char str2[50] = "HelloWorld!";
  ck_assert_int_eq(strncmp(str1, str2, 6), s21_strncmp(str1, str2, 6));
}
END_TEST

START_TEST(s21_strncmp_test6) {
#line 417
  char str1[50] = "Hello World!";
  char str2[50] = "HelloWorld!";
  ck_assert_int_eq(strncmp(str1, str2, 0), s21_strncmp(str1, str2, 0));
}
END_TEST

START_TEST(s21_strncmp_test7) {
#line 422
  char str1[50] = " Hello World!";
  char str2[50] = "Hello World!";
  ck_assert_int_eq(strncmp(str1, str2, 3), s21_strncmp(str1, str2, 3));
}
END_TEST

START_TEST(s21_strncmp_test8) {
#line 427
  char str1[50] = "Hello World!";
  char str2[50] = "Hello World! ";
  ck_assert_int_eq(strncmp(str1, str2, 13), s21_strncmp(str1, str2, 13));
}
END_TEST

START_TEST(s21_strncmp_test9) {
#line 432
  char str1[50] = "1";
  char str2[50] = "";
  ck_assert_int_eq(strncmp(str1, str2, 0), s21_strncmp(str1, str2, 0));
}
END_TEST

START_TEST(s21_strncmp_test10) {
#line 437
  char str1[50] = "1";
  char str2[50] = "";
  ck_assert_int_eq(strncmp(str1, str2, 1), s21_strncmp(str1, str2, 1));
}
END_TEST

START_TEST(s21_strncmp_test11) {
#line 442
  char str1[50] = "Hello World!";
  char str2[50] = "Hello \0World!";
  ck_assert_int_eq(strncmp(str1, str2, 8), s21_strncmp(str1, str2, 8));
}
END_TEST

START_TEST(s21_strncmp_test12) {
#line 447
  char str1[50] = "Hello World!";
  char str2[50] = "Hello \nWorld!";
  ck_assert_int_eq(strncmp(str1, str2, 8), s21_strncmp(str1, str2, 8));
}
END_TEST

START_TEST(s21_strncmp_test13) {
#line 452
  char str1[50] = "}{:{+_)(*&^%$";
  char str2[50] = "}{:{+_)(*&^%$";
  ck_assert_int_eq(strncmp(str1, str2, 12), s21_strncmp(str1, str2, 12));
}
END_TEST

START_TEST(s21_strncmp_test14) {
#line 457
  char str1[50] = "}{:{+_)((*&^%$";
  char str2[50] = "}{:{+_)(*&^%$";
  ck_assert_int_eq(strncmp(str1, str2, 12), s21_strncmp(str1, str2, 12));
}
END_TEST

START_TEST(s21_strcpy_test1) {
#line 462
  char str1[50] = "abcde";
  char str2[50] = "12345";
  ck_assert_str_eq(strcpy(str1, str2), s21_strcpy(str1, str2));
}
END_TEST

START_TEST(s21_strcpy_test2) {
#line 467
  char str1[50] = "abcde";
  char str2[50] = "1";
  ck_assert_str_eq(strcpy(str1, str2), s21_strcpy(str1, str2));
}
END_TEST

START_TEST(s21_strcpy_test3) {
#line 472
  char str1[50] = "a";
  char str2[50] = "12345";
  ck_assert_str_eq(strcpy(str1, str2), s21_strcpy(str1, str2));
}
END_TEST

START_TEST(s21_strcpy_test4) {
#line 477
  char str1[50] = "";
  char str2[50] = "1";
  ck_assert_str_eq(strcpy(str1, str2), s21_strcpy(str1, str2));
}
END_TEST

START_TEST(s21_strcpy_test5) {
#line 482
  char str1[50] = "a";
  char str2[50] = "";
  ck_assert_str_eq(strcpy(str1, str2), s21_strcpy(str1, str2));
}
END_TEST

START_TEST(s21_strcpy_test6) {
#line 487
  char str1[50] = "";
  char str2[50] = "";
  ck_assert_str_eq(strcpy(str1, str2), s21_strcpy(str1, str2));
}
END_TEST

START_TEST(s21_strcpy_test7) {
#line 492
  char str1[50] = "ab\ncde";
  char str2[50] = "12345";
  ck_assert_str_eq(strcpy(str1, str2), s21_strcpy(str1, str2));
}
END_TEST

START_TEST(s21_strcpy_test8) {
#line 497
  char str1[50] = "abcde";
  char str2[50] = "123\n45";
  ck_assert_str_eq(strcpy(str1, str2), s21_strcpy(str1, str2));
}
END_TEST

START_TEST(s21_strcpy_test9) {
#line 502
  char str1[50] = "ab\0cde";
  char str2[50] = "12345";
  ck_assert_str_eq(strcpy(str1, str2), s21_strcpy(str1, str2));
}
END_TEST

START_TEST(s21_strcpy_test10) {
#line 507
  char str1[50] = "abcde";
  char str2[50] = "12\0345";
  ck_assert_str_eq(strcpy(str1, str2), s21_strcpy(str1, str2));
}
END_TEST

START_TEST(s21_strcpy_test11) {
#line 512
  char str1[50] = "abcde";
  char str2[50] = "\012345";
  ck_assert_str_eq(strcpy(str1, str2), s21_strcpy(str1, str2));
}
END_TEST

START_TEST(s21_strcpy_test12) {
#line 517
  char str1[50] = "\0abcde";
  char str2[50] = "\012345";
  ck_assert_str_eq(strcpy(str1, str2), s21_strcpy(str1, str2));
}
END_TEST

START_TEST(s21_strcpy_test13) {
#line 522
  char str1[50] = ")(*&  ^%$ || }{ \"";
  char str2[50] = "!23@^5   tG ()-_(+) ^&U\\\\\n/::";
  ck_assert_str_eq(strcpy(str1, str2), s21_strcpy(str1, str2));
}
END_TEST

START_TEST(strncpy_test1) {
#line 527
  char str1[50] = "abcdef";
  char str2[50] = "12345";
  ck_assert_str_eq(strncpy(str1, str2, 5), s21_strncpy(str1, str2, 5));
}
END_TEST

START_TEST(strncpy_test2) {
#line 532
  char str1[50] = "abcdef";
  char str2[50] = "12345";
  ck_assert_str_eq(strncpy(str1, str2, 1), s21_strncpy(str1, str2, 1));
}
END_TEST

START_TEST(strncpy_test3) {
#line 537
  char str1[50] = "abcdef";
  char str2[50] = "12345";
  ck_assert_str_eq(strncpy(str1, str2, 0), s21_strncpy(str1, str2, 0));
}
END_TEST

START_TEST(strncpy_test4) {
#line 542
  char str1[50] = "abcdef";
  char str2[50] = "1";
  ck_assert_str_eq(strncpy(str1, str2, 1), s21_strncpy(str1, str2, 1));
}
END_TEST

START_TEST(strncpy_test5) {
#line 547
  char str1[50] = "a";
  char str2[50] = "12345";
  ck_assert_str_eq(strncpy(str1, str2, 5), s21_strncpy(str1, str2, 5));
}
END_TEST

START_TEST(strncpy_test6) {
#line 552
  char str1[50] = "";
  char str2[50] = "12345";
  ck_assert_str_eq(strncpy(str1, str2, 5), s21_strncpy(str1, str2, 5));
}
END_TEST

START_TEST(strncpy_test7) {
#line 557
  char str1[50] = "abcdef";
  char str2[50] = "";
  ck_assert_str_eq(strncpy(str1, str2, 1), s21_strncpy(str1, str2, 1));
}
END_TEST

START_TEST(strncpy_test8) {
#line 562
  char str1[50] = " dest ";
  char str2[50] = "HELLO!\05";
  ck_assert_str_eq(strncpy(str1, str2, 6), s21_strncpy(str1, str2, 6));
}
END_TEST

START_TEST(strncpy_test9) {
#line 567
  char str1[50] = " dest ";
  char str2[50] = "HELLO!\05";
  ck_assert_str_eq(strncpy(str1, str2, 8), s21_strncpy(str1, str2, 8));
}
END_TEST

START_TEST(strncpy_test10) {
#line 572
  char str1[50] = "\0/r\v/n";
  char str2[50] = "5t/<//8\0";
  ck_assert_str_eq(strncpy(str1, str2, 3), s21_strncpy(str1, str2, 3));
}
END_TEST

START_TEST(strncpy_test11) {
#line 577
  char str1[50] = "        abcdef  ";
  char str2[50] = "   __-=      1+(*&) 234 5       ";
  ck_assert_str_eq(strncpy(str1, str2, 27), s21_strncpy(str1, str2, 27));
}
END_TEST

START_TEST(s21_strcat_test1) {
#line 582
  const char *s21_str;
  const char *orig_str;
  char str1[100] = "Hello ";
  char str2[100] = "Hello ";
  s21_str = s21_strcat(str1, "world");
  orig_str = strcat(str2, "world");
  ck_assert_str_eq(s21_str, orig_str);
}
END_TEST

START_TEST(s21_strcat_test2) {
#line 591
  const char *s21_str;
  const char *orig_str;
  char str1[100] = "Hello ";
  char str2[100] = "Hello ";
  s21_str = s21_strcat(str1, "");
  orig_str = strcat(str2, "");
  ck_assert_str_eq(s21_str, orig_str);
}
END_TEST

START_TEST(s21_strcat_test3) {
#line 600
  const char *s21_str;
  const char *orig_str;
  char str1[100] = "";
  char str2[100] = "";
  s21_str = s21_strcat(str1, "world");
  orig_str = strcat(str2, "world");
  ck_assert_str_eq(s21_str, orig_str);
}
END_TEST

START_TEST(s21_strcat_test4) {
#line 609
  const char *s21_str;
  const char *orig_str;
  char str1[100] = "";
  char str2[100] = "";
  s21_str = s21_strcat(str1, "");
  orig_str = strcat(str2, "");
  ck_assert_str_eq(s21_str, orig_str);
}
END_TEST

START_TEST(s21_strcat_test5) {
#line 618
  const char *s21_str;
  const char *orig_str;
  char str1[100] = "Hello ";
  char str2[100] = "Hello ";
  s21_str = s21_strcat(str1, "worl\0d");
  orig_str = strcat(str2, "worl\0d");
  ck_assert_str_eq(s21_str, orig_str);
}
END_TEST

START_TEST(s21_strcat_test6) {
#line 627
  const char *s21_str;
  const char *orig_str;
  char str1[100] = "He\0llo ";
  char str2[100] = "He\0llo ";
  s21_str = s21_strcat(str1, "world");
  orig_str = strcat(str2, "world");
  ck_assert_str_eq(s21_str, orig_str);
}
END_TEST

START_TEST(s21_strcat_test7) {
#line 636
  const char *s21_str;
  const char *orig_str;
  char str1[100] = "Hello ";
  char str2[100] = "Hello ";
  s21_str = s21_strcat(str1, "\n");
  orig_str = strcat(str2, "\n");
  ck_assert_str_eq(s21_str, orig_str);
}
END_TEST

START_TEST(s21_strncat_test1) {
#line 645
  const char *s21_str;
  const char *orig_str;
  char str1[100] = "Hello ";
  char str2[100] = "Hello ";
  s21_str = s21_strncat(str1, "world", 5);
  orig_str = strncat(str2, "world", sizeof str2 - strlen(str2) - 1);
  ck_assert_str_eq(s21_str, orig_str);
}
END_TEST

START_TEST(s21_strncat_test2) {
#line 654
  const char *s21_str;
  const char *orig_str;
  char str1[100] = "Hello ";
  char str2[100] = "Hello ";
  s21_str = s21_strncat(str1, "world", 10);
  orig_str = strncat(str2, "world", 10);
  ck_assert_str_eq(s21_str, orig_str);
}
END_TEST

START_TEST(s21_strncat_test3) {
#line 663
  const char *s21_str;
  const char *orig_str;
  char str1[100] = "Hello ";
  char str2[100] = "Hello ";
  s21_str = s21_strncat(str1, "", 1);
  orig_str = strncat(str2, "", 1);
  ck_assert_str_eq(s21_str, orig_str);
}
END_TEST

START_TEST(s21_strncat_test4) {
#line 672
  const char *s21_str;
  const char *orig_str;
  char str1[100] = "Hello ";
  char str2[100] = "Hello ";
  s21_str = s21_strncat(str1, "", 4);
  orig_str = strncat(str2, "", 4);
  ck_assert_str_eq(s21_str, orig_str);
}
END_TEST

START_TEST(s21_strncat_test5) {
#line 681
  const char *s21_str;
  const char *orig_str;
  char str1[100] = "";
  char str2[100] = "";
  s21_str = s21_strncat(str1, "world", 3);
  orig_str = strncat(str2, "world", 3);
  ck_assert_str_eq(s21_str, orig_str);
}
END_TEST

START_TEST(s21_strncat_test6) {
#line 690
  const char *s21_str;
  const char *orig_str;
  char str1[100] = "";
  char str2[100] = "";
  s21_str = s21_strncat(str1, "world", 0);
  orig_str = strncat(str2, "world", 0);
  ck_assert_str_eq(s21_str, orig_str);
}
END_TEST

START_TEST(s21_strncat_test7) {
#line 699
  const char *s21_str;
  const char *orig_str;
  char str1[100] = "";
  char str2[100] = "";
  s21_str = s21_strncat(str1, "", 1);
  orig_str = strncat(str2, "", 1);
  ck_assert_str_eq(s21_str, orig_str);
}
END_TEST

START_TEST(s21_strncat_test8) {
#line 708
  const char *s21_str;
  const char *orig_str;
  char str1[100] = " !@#123 ";
  char str2[100] = " !@#123 ";
  s21_str = s21_strncat(str1, "\n", 1);
  orig_str = strncat(str2, "\n", sizeof str2 - strlen(str2) - 1);
  ck_assert_str_eq(s21_str, orig_str);
}
END_TEST

START_TEST(s21_strncat_test9) {
#line 717
  const char *s21_str;
  const char *orig_str;
  char str1[100] = "H\0ello ";
  char str2[100] = "H\0ello ";
  s21_str = s21_strncat(str1, "world", 5);
  orig_str = strncat(str2, "world", sizeof str2 - strlen(str2) - 1);
  ck_assert_str_eq(s21_str, orig_str);
}
END_TEST

START_TEST(s21_strncat_test10) {
#line 726
  const char *s21_str;
  const char *orig_str;
  char str1[100] = "H\0ello ";
  char str2[100] = "H\0ello ";
  s21_str = s21_strncat(str1, "wor\0ld", 5);
  orig_str = strncat(str2, "wor\0ld", 5);
  ck_assert_str_eq(s21_str, orig_str);
}
END_TEST

START_TEST(s21_strspn_test1) {
#line 735
  const char str1[80] = "1234567890";
  const char str2[80] = "321";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(s21_strspn_test2) {
#line 740
  const char str1[80] = "12322334567890123";
  const char str2[80] = "123";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(s21_strspn_test3) {
#line 745
  const char str1[80] = " 12322334567890123";
  const char str2[80] = "123";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(s21_strspn_test4) {
#line 750
  const char str1[80] = "12 322334567890123";
  const char str2[80] = "123";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(s21_strspn_test5) {
#line 755
  const char str1[80] = "Hello";
  const char str2[80] = "Hello";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(s21_strspn_test6) {
#line 760
  const char str1[80] = "Hello";
  const char str2[80] = "ello";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(s21_strspn_test7) {
#line 765
  const char str1[80] = "Hello";
  const char str2[80] = "Hell";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(s21_strspn_test8) {
#line 770
  const char str1[80] = "";
  const char str2[80] = "Hello";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(s21_strspn_test9) {
#line 775
  const char str1[80] = "Hello";
  const char str2[80] = "";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(s21_strspn_test10) {
#line 780
  const char str1[80] = "Hello";
  const char str2[80] = "olleH";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(s21_strspn_test11) {
#line 785
  const char str1[80] = "Hello";
  const char str2[80] = "123olleH__)(5";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(s21_strspn_test12) {
#line 790
  const char str1[80] = "";
  const char str2[80] = "";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(s21_strspn_test13) {
#line 795
  const char str1[80] = "r";
  const char str2[80] = "12r";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(s21_strspn_test14) {
#line 800
  const char str1[80] = "r";
  const char str2[80] = "f12";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(s21_strspn_test15) {
#line 805
  const char str1[80] = "Hello";
  const char str2[80] = "\0Hello";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(s21_strspn_test16) {
#line 810
  const char str1[80] = "Hello";
  const char str2[80] = "Helo";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(s21_strspn_test17) {
#line 815
  const char str1[80] = "Hello";
  const char str2[80] = "He\0lo";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(s21_strspn_test18) {
#line 820
  const char str1[80] = "         H e           l      l o       ";
  const char str2[80] = "o le  H";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test1) {
#line 825
  const char str1[80] = "1234567890";
  const char str2[80] = "asdfghjk";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test2) {
#line 830
  const char str1[80] = "1234567890g";
  const char str2[80] = "asdfghjk";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test3) {
#line 835
  const char str1[80] = "12d34567890g";
  const char str2[80] = "asdfghjk";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test4) {
#line 840
  const char str1[80] = "";
  const char str2[80] = "qwe";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test5) {
#line 845
  const char str1[80] = " Hello! ";
  const char str2[80] = "";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test6) {
#line 850
  const char str1[80] = "";
  const char str2[80] = "";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test7) {
#line 855
  const char str1[80] = " ";
  const char str2[80] = "";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test8) {
#line 860
  const char str1[80] = "";
  const char str2[80] = " ";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test9) {
#line 865
  const char str1[80] = "1 2  .3... Hello!";
  const char str2[80] = "Hello!";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test10) {
#line 870
  const char str1[80] = "Hello";
  const char str2[80] = "oleH";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test11) {
#line 875
  const char str1[80] = "Hello";
  const char str2[80] = "89\0Hello";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test12) {
#line 880
  const char str1[80] = "He\0llo";
  const char str2[80] = "lo";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test13) {
#line 885
  const char str1[80] = "             321  ";
  const char str2[80] = "1";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test14) {
#line 890
  const char str1[80] = "q1q2w3we45rt66g7Zyu8j";
  const char str2[80] = "zxvbvcvbZnm,m./??";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strtok_test1) {
#line 895
  char str1[] = "123abc23ccd3vvc321";
  char str2[] = "123abc23ccd3vvc321";
  char delim[] = "abc";
  char *ptr1 = s21_strtok(str1, delim);
  char *ptr2 = strtok(str2, delim);
  while (ptr1 != s21_NULL && ptr2 != NULL) {
    ck_assert_str_eq(str1, str2);
    ptr1 = s21_strtok(s21_NULL, delim);
    ptr2 = s21_strtok(NULL, delim);
  }
}
END_TEST

START_TEST(s21_strtok_test2) {
#line 907
  char str1[] = "123abc23ccd3vvc321";
  char str2[] = "123abc23ccd3vvc321";
  char delim[] = "213";
  char *ptr1 = s21_strtok(str1, delim);
  char *ptr2 = strtok(str2, delim);
  while (ptr1 != s21_NULL && ptr2 != NULL) {
    ck_assert_str_eq(str1, str2);
    ptr1 = s21_strtok(s21_NULL, delim);
    ptr2 = s21_strtok(NULL, delim);
  }
}
END_TEST

START_TEST(s21_strtok_test3) {
#line 919
  char str1[] = "";
  char str2[] = "";
  char delim[] = "213";
  char *ptr1 = s21_strtok(str1, delim);
  char *ptr2 = strtok(str2, delim);
  while (ptr1 != s21_NULL && ptr2 != NULL) {
    ck_assert_str_eq(str1, str2);
    ptr1 = s21_strtok(s21_NULL, delim);
    ptr2 = s21_strtok(NULL, delim);
  }
}
END_TEST

START_TEST(s21_strtok_test4) {
#line 931
  char str1[] = "123abc23ccd3vvc321";
  char str2[] = "123abc23ccd3vvc321";
  char delim[] = "";
  char *ptr1 = s21_strtok(str1, delim);
  char *ptr2 = strtok(str2, delim);
  while (ptr1 != s21_NULL && ptr2 != NULL) {
    ck_assert_str_eq(str1, str2);
    ptr1 = s21_strtok(s21_NULL, delim);
    ptr2 = s21_strtok(NULL, delim);
  }
}
END_TEST

START_TEST(s21_strtok_test5) {
#line 943
  char str1[] = "123abc23ccd3vvc321";
  char str2[] = "123abc23ccd3vvc321";
  char delim[] = "789";
  char *ptr1 = s21_strtok(str1, delim);
  char *ptr2 = strtok(str2, delim);
  while (ptr1 != s21_NULL && ptr2 != NULL) {
    ck_assert_str_eq(str1, str2);
    ptr1 = s21_strtok(s21_NULL, delim);
    ptr2 = s21_strtok(NULL, delim);
  }
}
END_TEST

START_TEST(s21_strtok_test6) {
#line 955
  char str1[] = "111";
  char str2[] = "111";
  char delim[] = "1";
  char *ptr1 = s21_strtok(str1, delim);
  char *ptr2 = strtok(str2, delim);
  while (ptr1 != s21_NULL && ptr2 != NULL) {
    ck_assert_str_eq(str1, str2);
    ptr1 = s21_strtok(s21_NULL, delim);
    ptr2 = s21_strtok(NULL, delim);
  }
}
END_TEST

START_TEST(s21_strtok_test7) {
#line 967
  char str1[] = "121";
  char str2[] = "121";
  char delim[] = "1";
  char *ptr1 = s21_strtok(str1, delim);
  char *ptr2 = strtok(str2, delim);
  while (ptr1 != s21_NULL && ptr2 != NULL) {
    ck_assert_str_eq(str1, str2);
    ptr1 = s21_strtok(s21_NULL, delim);
    ptr2 = s21_strtok(NULL, delim);
  }
}
END_TEST

START_TEST(s21_strtok_test8) {
#line 979
  char str1[] = "         1   2  1   ";
  char str2[] = "         1   2  1   ";
  char delim[] = "1";
  char *ptr1 = s21_strtok(str1, delim);
  char *ptr2 = strtok(str2, delim);
  while (ptr1 != s21_NULL && ptr2 != NULL) {
    ck_assert_str_eq(str1, str2);
    ptr1 = s21_strtok(s21_NULL, delim);
    ptr2 = s21_strtok(NULL, delim);
  }
}
END_TEST

START_TEST(s21_strchr_test1) {
#line 991
  char str[80] = "1213456578090";
  ck_assert_str_eq(strchr(str, '1'), s21_strchr(str, '1'));
}
END_TEST

START_TEST(s21_strchr_test2) {
#line 995
  char str[80] = "1213456578090";
  ck_assert_str_eq(strchr(str, '5'), s21_strchr(str, '5'));
}
END_TEST

START_TEST(s21_strchr_test3) {
#line 999
  char str[80] = "1213456578090";
  ck_assert_str_eq(strchr(str, '0'), s21_strchr(str, '0'));
}
END_TEST

START_TEST(s21_strchr_test4) {
#line 1003
  char str[80] = "Hello World!";
  ck_assert_ptr_eq(strchr(str, 'y'), s21_strchr(str, 'y'));
}
END_TEST

START_TEST(s21_strchr_test5) {
#line 1007
  char str[80] = "Hello World!";
  ck_assert_str_eq(strchr(str, ' '), s21_strchr(str, ' '));
}
END_TEST

START_TEST(s21_strchr_test6) {
#line 1011
  char str[80] = "Hello W\0orld!";
  ck_assert_str_eq(strchr(str, 'l'), s21_strchr(str, 'l'));
}
END_TEST

START_TEST(s21_strchr_test7) {
#line 1015
  char str[80] = "Hello W\0orld!";
  ck_assert_ptr_eq(strchr(str, 'r'), s21_strchr(str, 'r'));
}
END_TEST

START_TEST(s21_strchr_test8) {
#line 1019
  char str[80] = "";
  ck_assert_ptr_eq(strchr(str, 'v'), s21_strchr(str, 'v'));
}
END_TEST

START_TEST(s21_strchr_test9) {
#line 1023
  char str[80] = "\tt\n\"";
  ck_assert_str_eq(strchr(str, '\n'), s21_strchr(str, '\n'));
}
END_TEST

START_TEST(s21_strchr_test10) {
#line 1027
  char str[80] = "abcdef";
  ck_assert_str_eq(strchr(str, '\0'), s21_strchr(str, '\0'));
}
END_TEST

START_TEST(s21_strchr_test11) {
#line 1031
  char str[80] = "ab\0cdef";
  ck_assert_str_eq(strchr(str, '\0'), s21_strchr(str, '\0'));
}
END_TEST

START_TEST(s21_strrchr_test1) {
#line 1035
  char str[80] = "1213456758090";
  ck_assert_str_eq(strrchr(str, '1'), s21_strrchr(str, '1'));
}
END_TEST

START_TEST(s21_strrchr_test2) {
#line 1039
  char str[80] = "1213456758090";
  ck_assert_str_eq(strrchr(str, '0'), s21_strrchr(str, '0'));
}
END_TEST

START_TEST(s21_strrchr_test3) {
#line 1043
  char str[80] = "1213456758090";
  ck_assert_str_eq(strrchr(str, '5'), s21_strrchr(str, '5'));
}
END_TEST

START_TEST(s21_strrchr_test4) {
#line 1047
  char str[80] = "";
  ck_assert_ptr_eq(strrchr(str, 't'), s21_strrchr(str, 't'));
}
END_TEST

START_TEST(s21_strrchr_test5) {
#line 1051
  char str[80] = "Hello World!";
  ck_assert_ptr_eq(strrchr(str, 'L'), s21_strrchr(str, 'L'));
}
END_TEST

START_TEST(s21_strrchr_test6) {
#line 1055
  char str[80] = "Hello World!";
  ck_assert_str_eq(strrchr(str, 'l'), s21_strrchr(str, 'l'));
}
END_TEST

START_TEST(s21_strrchr_test7) {
#line 1059
  char str[80] = "Hello Worl\0d!";
  ck_assert_str_eq(strrchr(str, 'l'), s21_strrchr(str, 'l'));
}
END_TEST

START_TEST(s21_strrchr_test8) {
#line 1063
  char str[80] = "Hello Worl\0d!";
  ck_assert_ptr_eq(strrchr(str, '6'), s21_strrchr(str, '6'));
}
END_TEST

START_TEST(s21_strrchr_test9) {
#line 1067
  char str[80] = "gggggggggggggggg\0";
  ck_assert_str_eq(strrchr(str, 'g'), s21_strrchr(str, 'g'));
}
END_TEST

START_TEST(s21_strrchr_test10) {
#line 1071
  char str[80] = "gggggggggggggggg9\0";

  ck_assert_str_eq(strrchr(str, 'g'), s21_strrchr(str, 'g'));
}
END_TEST

START_TEST(s21_strrchr_test11) {
#line 1076
  char str[80] = " 958ugjmkl3cpefc.e";
  ck_assert_str_eq(strrchr(str, ' '), s21_strrchr(str, ' '));
}
END_TEST

START_TEST(s21_strrchr_test12) {
#line 1080
  char str[80] = " 958ug\tjmkl\v3cpe\nfc.e";
  ck_assert_str_eq(strrchr(str, ' '), s21_strrchr(str, ' '));
}
END_TEST

START_TEST(s21_strchr_test13) {
#line 1084
  char str[80] = "abcdef";
  ck_assert_str_eq(strchr(str, '\0'), s21_strchr(str, '\0'));
}
END_TEST

START_TEST(s21_strchr_test14) {
#line 1088
  char str[80] = "ab\0cdef";
  ck_assert_str_eq(strchr(str, '\0'), s21_strchr(str, '\0'));
}
END_TEST

START_TEST(s21_strpbrk_test1) {
#line 1092
  char str1[80] = "1234567890";
  char str2[80] = "456";
  ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test2) {
#line 1097
  char str1[80] = "1234567890";
  char str2[80] = "654";
  ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test3) {
#line 1102
  char str1[80] = "1234567890";
  char str2[80] = "6541";
  ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test4) {
#line 1107
  char str1[80] = "1234567890";
  char str2[80] = "!w a";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test5) {
#line 1112
  char str1[80] = "1234567890";
  char str2[80] = "1234567890";
  ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test6) {
#line 1117
  char str1[80] = "1234567890";
  char str2[80] = "0987654321";
  ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test7) {
#line 1122
  char str1[80] = "qwertyu9";
  char str2[80] = "                 uyt   ";
  ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test8) {
#line 1127
  char str1[80] = "";
  char str2[80] = "123";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test9) {
#line 1132
  char str1[80] = "321";
  char str2[80] = "";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test10) {
#line 1137
  char str1[80] = "";
  char str2[80] = "";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test11) {
#line 1142
  char str1[80] = "bb123\nA\0a";
  char str2[80] = "acAd";
  ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test12) {
#line 1147
  char str1[80] = "bb123\n\0A\0a";
  char str2[80] = "acAd";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test13) {
#line 1152
  char str1[80] = "1234567890";
  char str2[80] = "1";
  ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test14) {
#line 1157
  char str1[80] = "1234567890";
  char str2[80] = "0";
  ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test1) {
#line 1162
  char str1[80] = "1234567890";
  char str2[80] = "0";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test2) {
#line 1167
  char str1[80] = "1234567890";
  char str2[80] = "1";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test3) {
#line 1172
  char str1[80] = "1234567890";
  char str2[80] = "6";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test4) {
#line 1177
  char str1[80] = "1234567890";
  char str2[80] = "456";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test5) {
#line 1182
  char str1[80] = "1234567890";
  char str2[80] = "876";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test6) {
#line 1187
  char str1[80] = "";
  char str2[80] = "123";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test7) {
#line 1192
  char str1[80] = "abc";
  char str2[80] = "";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test8) {
#line 1197
  char str1[80] = "";
  char str2[80] = "";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test9) {
#line 1202
  char str1[80] = "ad\nc";
  char str2[80] = "\n";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test10) {
#line 1207
  char str1[80] = "ad\0c123";
  char str2[80] = "c1";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test11) {
#line 1212
  char str1[80] = "adc1\023";
  char str2[80] = "c1";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test12) {
#line 1217
  char str1[80] = " a B b c ";
  char str2[80] = " ";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test13) {
#line 1222
  char str1[80] = " a B b c ";
  char str2[80] = " B ";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test14) {
#line 1227
  char str1[80] =
      "}oi>()&*^&uY#HnHG/.//.,,,fUnkb  +_ _P+)_*(&^%$$$#%@#) vCEXWDfv  ";
  char str2[80] = ")_*(";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test15) {
#line 1233
  char str1[80] =
      "}oi>()&*^&uY#HnHG/.//.,,,fUnkb  +_ _P+)_*(&^%$$$#%@#) vCEXWDfv  ";
  char str2[80] = ")*(";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strerror_test1) {
#line 1239
  ck_assert_int_eq(strcmp(s21_strerror(1), strerror(1)), 0);
}
END_TEST

START_TEST(s21_strerror_test2) {
#line 1242
  ck_assert_int_eq(strcmp(s21_strerror(-20), strerror(-20)), 0);
}
END_TEST

START_TEST(s21_strerror_test3) {
#line 1245
  ck_assert_int_eq(strcmp(s21_strerror(0), strerror(0)), 0);
}
END_TEST

START_TEST(s21_strerror_test4) {
#line 1248
  ck_assert_int_eq(strcmp(s21_strerror(100), strerror(100)), 0);
}
END_TEST

START_TEST(s21_strerror_test5) {
#line 1251
  ck_assert_int_eq(strcmp(s21_strerror(1234567), strerror(1234567)), 0);
}
END_TEST

START_TEST(s21_strerror_test6) {
#line 1254
  ck_assert_int_eq(strcmp(s21_strerror(-1234567), strerror(-1234567)), 0);
}
END_TEST

START_TEST(s21_strerror_test7) {
#line 1257
  ck_assert_int_eq(strcmp(s21_strerror(25), strerror(25)), 0);
}
END_TEST

START_TEST(s21_to_upper_test1) {
#line 1260
  char str[80] = "hello world";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, "HELLO WORLD");
  if (result) free(result);
}
END_TEST

START_TEST(s21_to_upper_test2) {
#line 1266
  char str[80] = "HeLlO WorlD";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, "HELLO WORLD");
  if (result) free(result);
}
END_TEST

START_TEST(s21_to_upper_test3) {
#line 1272
  char str[80] = "HELLO WORLD";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, "HELLO WORLD");
  if (result) free(result);
}
END_TEST

START_TEST(s21_to_upper_test4) {
#line 1278
  char str[80] = "74^&$#@%12$!#%@#^8780";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, "74^&$#@%12$!#%@#^8780");
  if (result) free(result);
}
END_TEST

START_TEST(s21_to_upper_test5) {
#line 1284
  char str[80] = "";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, "");
  if (result) free(result);
}
END_TEST

START_TEST(s21_to_upper_test6) {
#line 1290
  char str[80] = "    ";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, "    ");
  if (result) free(result);
}
END_TEST

START_TEST(s21_to_upper_test7) {
#line 1296
  char str[80] = "HELLO WORLd";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, "HELLO WORLD");
  if (result) free(result);
}
END_TEST

START_TEST(s21_to_upper_test8) {
#line 1302
  char str[80] = "hELLO WORLD";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, "HELLO WORLD");
  if (result) free(result);
}
END_TEST

START_TEST(s21_to_upper_test9) {
#line 1308
  char str[80] = "hello\nworld";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, "HELLO\nWORLD");
  if (result) free(result);
}
END_TEST

START_TEST(s21_to_upper_test10) {
#line 1314
  char str[80] = "hello\0world";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, "HELLO");
  if (result) free(result);
}
END_TEST

START_TEST(s21_to_lower_test1) {
#line 1320
  char str[80] = "HELLO WORLD";
  char *result = s21_to_lower(str);
  ck_assert_str_eq(result, "hello world");
  if (result) free(result);
}
END_TEST

START_TEST(s21_to_lower_test2) {
#line 1326
  char str[80] = "HeLlO WorlD";
  char *result = s21_to_lower(str);
  ck_assert_str_eq(result, "hello world");
  if (result) free(result);
}
END_TEST

START_TEST(s21_to_lower_test3) {
#line 1332
  char str[80] = "hello world";
  char *result = s21_to_lower(str);
  ck_assert_str_eq(result, "hello world");
  if (result) free(result);
}
END_TEST

START_TEST(s21_to_lower_test4) {
#line 1338
  char str[80] = "74^&$#@%12$!#%@#^8780";
  char *result = s21_to_lower(str);
  ck_assert_str_eq(result, "74^&$#@%12$!#%@#^8780");
  if (result) free(result);
}
END_TEST

START_TEST(s21_to_lower_test5) {
#line 1344
  char str[80] = "";
  char *result = s21_to_lower(str);
  ck_assert_str_eq(result, "");
  if (result) free(result);
}
END_TEST

START_TEST(s21_to_lower_test6) {
#line 1350
  char str[80] = "    ";
  char *result = s21_to_lower(str);
  ck_assert_str_eq(result, "    ");
  if (result) free(result);
}
END_TEST

START_TEST(s21_to_lower_test7) {
#line 1356
  char str[80] = "hello worlD";
  char *result = s21_to_lower(str);
  ck_assert_str_eq(result, "hello world");
  if (result) free(result);
}
END_TEST

START_TEST(s21_to_lower_test8) {
#line 1362
  char str[80] = "Hello world";
  char *result = s21_to_lower(str);
  ck_assert_str_eq(result, "hello world");
  if (result) free(result);
}
END_TEST

START_TEST(s21_to_lower_test9) {
#line 1368
  char str[80] = "HELLO\nWORLD";
  char *result = s21_to_lower(str);
  ck_assert_str_eq(result, "hello\nworld");
  if (result) free(result);
}
END_TEST

START_TEST(s21_to_lower_test10) {
#line 1374
  char str[80] = "HELLO\0WORLD";
  char *result = s21_to_lower(str);
  ck_assert_str_eq(result, "hello");
  if (result) free(result);
}
END_TEST

START_TEST(s21_insert_test1) {
#line 1380
  char src[80] = "Abcde";
  char str[80] = "123";
  s21_size_t index = 0;
  char *result = s21_insert(src, str, index);
  ck_assert_str_eq(result, "123Abcde");
  if (result) free(result);
}
END_TEST

START_TEST(s21_insert_test2) {
#line 1388
  char src[80] = "Abcde";
  char str[80] = "123";
  s21_size_t index = 1;
  char *result = s21_insert(src, str, index);
  ck_assert_str_eq(result, "A123bcde");
  if (result) free(result);
}
END_TEST

START_TEST(s21_insert_test3) {
#line 1396
  char src[80] = "Abcde";
  char str[80] = "123";
  s21_size_t index = 2;
  char *result = s21_insert(src, str, index);
  ck_assert_str_eq(result, "Ab123cde");
  if (result) free(result);
}
END_TEST

START_TEST(s21_insert_test4) {
#line 1404
  char src[80] = "Abcde";
  char str[80] = "123";
  s21_size_t index = 3;
  char *result = s21_insert(src, str, index);
  ck_assert_str_eq(result, "Abc123de");
  if (result) free(result);
}
END_TEST

START_TEST(s21_insert_test5) {
#line 1412
  char src[80] = "Abcde";
  char str[80] = "123";
  s21_size_t index = 4;
  char *result = s21_insert(src, str, index);
  ck_assert_str_eq(result, "Abcd123e");
  if (result) free(result);
}
END_TEST

START_TEST(s21_insert_test6) {
#line 1420
  char src[80] = "Abcde";
  char str[80] = "123";
  s21_size_t index = 5;
  char *result = s21_insert(src, str, index);
  ck_assert_str_eq(result, "Abcde123");
  if (result) free(result);
}
END_TEST

START_TEST(s21_insert_test7) {
#line 1428
  char src[80] = "Abcde";
  char str[80] = "123";
  s21_size_t index = 6;
  char *result = s21_insert(src, str, index);
  ck_assert_ptr_eq(result, s21_NULL);
  if (result) free(result);
}
END_TEST

START_TEST(s21_insert_test8) {
#line 1436
  char src[80] = "Abcde";
  char str[80] = "123";
  s21_size_t index = -1;
  char *result = s21_insert(src, str, index);
  ck_assert_ptr_eq(result, s21_NULL);
  if (result) free(result);
}
END_TEST

START_TEST(s21_insert_test9) {
#line 1444
  char src[80] = "";
  char str[80] = " 0 ";
  s21_size_t index = 0;
  char *result = s21_insert(src, str, index);
  ck_assert_str_eq(result, " 0 ");
  if (result) free(result);
}
END_TEST

START_TEST(s21_insert_test10) {
#line 1452
  char src[80] = "Empty";
  char str[80] = "";
  s21_size_t index = 2;
  char *result = s21_insert(src, str, index);
  ck_assert_str_eq(result, "Empty");
  if (result) free(result);
}
END_TEST

START_TEST(s21_insert_test11) {
#line 1460
  char src[80] = " S   p a s   e s ";
  char str[80] = "  i n ser  t ";
  s21_size_t index = 10;
  char *result = s21_insert(src, str, index);
  ck_assert_str_eq(result, " S   p a s  i n ser  t    e s ");
  if (result) free(result);
}
END_TEST

START_TEST(s21_insert_test12) {
#line 1468
  char src[80] = "asd\0fgh";
  char str[80] = "123";
  s21_size_t index = 3;
  char *result = s21_insert(src, str, index);
  ck_assert_str_eq(result, "asd123");
  if (result) free(result);
}
END_TEST

START_TEST(s21_insert_test13) {
#line 1476
  char src[80] = "asd\0fgh";
  char str[80] = "123";
  s21_size_t index = 4;
  char *result = s21_insert(src, str, index);
  ck_assert_ptr_eq(result, s21_NULL);
  if (result) free(result);
}
END_TEST

START_TEST(s21_trim_test1) {
#line 1484
  char src[80] = "abc123abc";
  char trim[80] = "abc";
  char *result = s21_trim(src, trim);
  ck_assert_str_eq(result, "123");
  if (result) free(result);
}
END_TEST

START_TEST(s21_trim_test2) {
#line 1491
  char src[80] = "8abc123abc";
  char trim[80] = "abc";
  char *result = s21_trim(src, trim);
  ck_assert_str_eq(result, "8abc123");
  if (result) free(result);
}
END_TEST

START_TEST(s21_trim_test3) {
#line 1498
  char src[80] = "abc123abc7";
  char trim[80] = "abc";
  char *result = s21_trim(src, trim);
  ck_assert_str_eq(result, "123abc7");
  if (result) free(result);
}
END_TEST

START_TEST(s21_trim_test4) {
#line 1505
  char src[80] = " abc123abc_";
  char trim[80] = "abc";
  char *result = s21_trim(src, trim);
  ck_assert_str_eq(result, " abc123abc_");
  if (result) free(result);
}
END_TEST

START_TEST(s21_trim_test5) {
#line 1512
  char src[80] = "";
  char trim[80] = "abc";
  char *result = s21_trim(src, trim);
  ck_assert_str_eq(result, "");
  if (result) free(result);
}
END_TEST

START_TEST(s21_trim_test6) {
#line 1519
  char src[80] = " spases ";
  char trim[80] = "";
  char *result = s21_trim(src, trim);
  ck_assert_str_eq(result, " spases ");
  if (result) free(result);
}
END_TEST

START_TEST(s21_trim_test7) {
#line 1526
  char src[80] = " spases ";
  char trim[80] = " ";
  char *result = s21_trim(src, trim);
  ck_assert_str_eq(result, "spases");
  if (result) free(result);
}
END_TEST

START_TEST(s21_trim_test8) {
#line 1533
  char src[80] = "                  Too many SpaSes        ";
  char trim[80] = " ";
  char *result = s21_trim(src, trim);
  ck_assert_str_eq(result, "Too many SpaSes");
  if (result) free(result);
}
END_TEST

START_TEST(s21_trim_test9) {
#line 1540
  char src[80] = "123";
  char trim[80] = "123";
  char *result = s21_trim(src, trim);
  ck_assert_str_eq(result, "");
  if (result) free(result);
}
END_TEST

START_TEST(s21_trim_test10) {
#line 1547
  char src[80] = "123123123";
  char trim[80] = "321";
  char *result = s21_trim(src, trim);
  ck_assert_str_eq(result, "");
  if (result) free(result);
}
END_TEST

START_TEST(s21_trim_test11) {
#line 1554
  char src[80] = "12312.3123";
  char trim[80] = "321";
  char *result = s21_trim(src, trim);
  ck_assert_str_eq(result, ".");
  if (result) free(result);
}
END_TEST

START_TEST(s21_trim_test12) {
#line 1561
  char src[80] = "213123abc3211112333";
  char trim[80] = "213";
  char *result = s21_trim(src, trim);
  ck_assert_str_eq(result, "abc");
  if (result) free(result);
}
END_TEST

START_TEST(s21_trim_test13) {
#line 1568
  char src[80] = "Hello World!";
  char trim[80] = "Ho";
  char *result = s21_trim(src, trim);
  ck_assert_str_eq(result, "ello World!");
  if (result) free(result);
}
END_TEST

START_TEST(s21_trim_test14) {
#line 1575
  char src[80] = "Hello\0 World!";
  char trim[80] = "oH";
  char *result = s21_trim(src, trim);
  ck_assert_str_eq(result, "ell");
  if (result) free(result);
}
END_TEST

START_TEST(s21_trim_test15) {
#line 1582
  char src[80] = "Hello World!";
  char trim[80] = "12vb";
  char *result = s21_trim(src, trim);
  ck_assert_str_eq(result, "Hello World!");
  if (result) free(result);
}
END_TEST

START_TEST(s21_trim_test16) {
#line 1589
  char src[80] = "1";
  char trim[80] = "1";
  char *result = s21_trim(src, trim);
  ck_assert_str_eq(result, "");
  if (result) free(result);
}
END_TEST

START_TEST(s21_sprintf_test1) {
#line 1596
  char str1[80] = {0};
  char str2[80] = {0};
  ck_assert_int_eq(
      s21_sprintf(str1, "%% %d %f %s %d %c", -75, 46.36, "345", 95, 'r'),
      sprintf(str2, "%% %d %f %s %d %c", -75, 46.36, "345", 95, 'r'));
}
END_TEST

START_TEST(s21_sprintf_test2) {
#line 1604
  char MESSAGE_1[500] = "Hello, World!!";
  char MESSAGE_2[500] = "Hello, World!!";
  char TEST_c = '5';
  short TEST_d = -21475;
  int TEST_i = -50000;
  double TEST_f = -50.4324;
  char TEST_s[20] = "FLAMES";
  long int li = 2323454;

  ck_assert_int_eq(s21_sprintf(MESSAGE_2, "%c %05hd %i %f %s, %2.1ld", TEST_c,
                               TEST_d, TEST_i, TEST_f, TEST_s, li),
                   sprintf(MESSAGE_1, "%c %05hd %i %f %s, %2.1ld", TEST_c,
                           TEST_d, TEST_i, TEST_f, TEST_s, li));
}
END_TEST

START_TEST(s21_sprintf_test3) {
#line 1619
  char MESSAGE_1[500] = "Hello, World!!";
  char MESSAGE_2[500] = "Hello, World!!";
  char TEST_c = '1';
  int TEST_d = 99899;
  int TEST_i = 27;
  double TEST_f = -150.4324;
  char TEST_s[20] = "-0987ytref";

  ck_assert_int_eq(s21_sprintf(MESSAGE_2, "%c %+d %i %.1f %s", TEST_c, TEST_d,
                               TEST_i, TEST_f, TEST_s),
                   sprintf(MESSAGE_1, "%c %+d %i %.1f %s", TEST_c, TEST_d,
                           TEST_i, TEST_f, TEST_s));
}
END_TEST

START_TEST(s21_sprintf_test4) {
#line 1633
  char MESSAGE_1[500] = "Hello, World!!";
  char MESSAGE_2[500] = "Hello, World!!";
  char TEST_c = '5';
  int TEST_d = 2342;
  int TEST_d2 = -345;
  int TEST_i = -50000;
  double TEST_f = -50.4324;
  char TEST_s[20] = "FLAMES";

  ck_assert_int_eq(s21_sprintf(MESSAGE_2, "%c %+1d %i %f %s, %-1d", TEST_c,
                               TEST_d, TEST_i, TEST_f, TEST_s, TEST_d2),
                   sprintf(MESSAGE_1, "%c %+1d %i %f %s, %-1d", TEST_c, TEST_d,
                           TEST_i, TEST_f, TEST_s, TEST_d2));
}
END_TEST

START_TEST(s21_sprintf_test5) {
#line 1648
  int x1 = 234;
  int x2 = -345;
  char *format_string1 = "love %+d % d love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string1, x1, x2),
                   sprintf(buf_for_sprintf, format_string1, x1, x2));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_test6) {
#line 1656
  char str1[80];
  char str2[80];
  char *format = "%.5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test7) {
#line 1664
  char str1[80];
  char str2[80];
  char *format = "%5d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test8) {
#line 1672
  char str1[80];
  char str2[80];
  char *format = "%-5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test9) {
#line 1680
  char str1[80];
  char str2[80];

  char *format = "%+5.31li";
  long int val = 698518581899;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test10) {
#line 1689
  char str1[80];
  char str2[80];
  char *format = "%.0d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test11) {
#line 1697
  char str1[80];
  char str2[80];
  char *format = "% 1.d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test12) {
#line 1705
  char str1[80];
  char str2[80];
  char *format = "%hd";
  short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test13) {
#line 1713
  char str1[80];
  char str2[80];
  char *format = "%.5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test14) {
#line 1721
  char str1[80];
  char str2[80];
  char *format = "% -5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test15) {
#line 1729
  char str1[80];
  char str2[80];
  char *format = "%-5.3c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test16) {
#line 1737
  char str1[80];
  char str2[80];
  char *format = "%s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test17) {
#line 1745
  char str1[80];
  char str2[80];
  char *format = "%.15s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test18) {
#line 1753
  char str1[80];
  char str2[80];
  char *format = "%15s";
  char *val = "77 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test19) {
#line 1761
  char str1[80];
  char str2[80];
  char *format = "%s";
  char *val =
      "77 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test20) {
#line 1770
  char str1[80];
  char str2[80];
  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test21) {
#line 1776
  char str1[80];
  char str2[80];
  ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test22) {
#line 1782
  char str1[80];
  char str2[80];
  ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                   sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test23) {
#line 1789
  char str1[80];
  char str2[80];
  ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"),
                   sprintf(str2, "%s", "Drop Sega PLS"));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test24) {
#line 1796
  char str1[80];
  char str2[80];
  ck_assert_int_eq(
      s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
      sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test25) {
#line 1804
  char str1[80];
  char str2[80];
  ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test26) {
#line 1810
  char str1[80];
  char str2[80];
  ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'), sprintf(str2, "%8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test27) {
#line 1817
  char str1[80];
  char str2[80];
  ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'),
                   sprintf(str2, "%-8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test28) {
#line 1824
  char str1[80];
  char str2[80];
  char format[] = "%1.1f";
  ck_assert_int_eq(s21_sprintf(str1, format, 1.1), sprintf(str2, format, 1.1));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test29) {
#line 1831
  char str1[80];
  char str2[80];
  char format[] = "%8.3c";
  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test30) {
#line 1838
  char str1[80];
  char str2[80];
  char format[] = "%+5.5d aboba";
  int val = 10000;
  int a = s21_sprintf(str1, format, val);
  int b = sprintf(str2, format, val);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test31) {
#line 1848
  char str1[80];
  char str2[80];
  char format[] = "%7.7f";
  ck_assert_int_eq(s21_sprintf(str1, format, 11.123456),
                   sprintf(str2, format, 11.123456));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test32) {
#line 1856
  char str1[80];
  char str2[80];
  char format[] = "%7.4s";
  ck_assert_int_eq(s21_sprintf(str1, format, "aboba floppa"),
                   sprintf(str2, format, "aboba floppa"));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test33) {
#line 1864
  char str1[80];
  char str2[80];
  char format[] = "% c";
  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test34) {
#line 1871
  char str1[80];
  char str2[80];
  char format[] = "% s";
  ck_assert_int_eq(s21_sprintf(str1, format, "aboba likes floppa"),
                   sprintf(str2, format, "aboba likes floppa"));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test35) {
#line 1879
  char str1[80];
  char str2[80];
  char format[] = "% s% c";
  ck_assert_int_eq(s21_sprintf(str1, format, "", 'f'),
                   sprintf(str2, format, "", 'f'));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test36) {
#line 1887
  char str1[80];
  char str2[80];
  char format[] = "%.f";
  ck_assert_int_eq(s21_sprintf(str1, format, 121.123),
                   sprintf(str2, format, 121.123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test37) {
#line 1895
  char str1[80];
  char str2[80];
  char *format = "%u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test38) {
#line 1903
  char str1[80];
  char str2[80];
  char *format = "%.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test39) {
#line 1911
  char str1[80];
  char str2[80];
  char *format = "% 5.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test40) {
#line 1919
  char str1[80];
  char str2[80];
  char *format = "%hu";
  unsigned short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test41) {
#line 1927
  char str1[80];
  char str2[80];
  char *format = "%lu";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test42) {
#line 1935
  char str1[80];
  char str2[80];
  char *format = "%+12d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test43) {
#line 1943
  char str1[80];
  char str2[80];
  char *format = "%15u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test44) {
#line 1951
  char str1[80];
  char str2[80];
  char *format = "%-16u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test45) {
#line 1959
  char str1[80];
  char str2[80];
  char *format = "%15c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test46) {
#line 1967
  char str1[80];
  char str2[80];
  char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                   sprintf(str2, format, val, 'c', 'a', 'b', 'b'));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test47) {
#line 1976
  char str1[80];
  char str2[80];
  char *format = "%-15.9s";
  char *val = "77 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test48) {
#line 1984
  char str1[80];
  char str2[80];
  char format[] = "%10ld";
  ck_assert_int_eq(s21_sprintf(str1, format, 1), sprintf(str2, format, 1));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test49) {
#line 1991
  char str1[80];
  char str2[80];
  char format[] = "%6.6u";
  ck_assert_int_eq(s21_sprintf(str1, format, 12341151),
                   sprintf(str2, format, 12341151));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test50) {
#line 1999
  char str1[80];
  char str2[80];
  char format[] = "%+li%+lu%+d%+lf";
  ck_assert_int_eq(s21_sprintf(str1, format, -123, 321, -5555, -1213.123),
                   sprintf(str2, format, -123, 321, -5555, -1213.123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test51) {
#line 2007
  char str1[80];
  char str2[80];
  char *format = "% d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test52) {
#line 2015
  char str1[80];
  char str2[80];
  ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                   sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test53) {
#line 2022
  char str1[80];
  char str2[80];
  ck_assert_int_eq(s21_sprintf(str1, "%i", -0), sprintf(str2, "%i", -0));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test54) {
#line 2028
  char str1[80];
  char str2[80];
  ck_assert_int_eq(s21_sprintf(str1, "%i%i%i%i", -999, 0, 666, -100),
                   sprintf(str2, "%i%i%i%i", -999, 0, 666, -100));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test55) {
#line 2035
  char str1[80];
  char str2[80];
  ck_assert_int_eq(
      s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
      sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test56) {
#line 2044
  char str1[80];
  char str2[80];
  ck_assert_int_eq(s21_sprintf(str1, "%x%X%o", 25, 25, 25),
                   sprintf(str2, "%x%X%o", 25, 25, 25));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test57) {
#line 2051
  char str1[80];
  char str2[80];
  ck_assert_int_eq(s21_sprintf(str1, "%-2x%X%o", 25, 25, 25),
                   sprintf(str2, "%-2x%X%o", 25, 25, 25));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test58) {
#line 2058
  char str1[80];
  char str2[80];
  ck_assert_int_eq(s21_sprintf(str1, "%g%G", 1.25, 0.25),
                   sprintf(str2, "%g%G", 1.25, 0.25));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test59) {
#line 2065
  char str1[80];
  char str2[80];
  ck_assert_int_eq(s21_sprintf(str1, "%g%G%e%E", 0.0000000125, 0.00000000125,
                               0.000000001285, 0.000000001215),
                   sprintf(str2, "%g%G%e%E", 0.0000000125, 0.00000000125,
                           0.000000001285, 0.000000001215));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test60) {
#line 2074
  char str1[80];
  char str2[80];
  int ptr1 = 20;
  int x;
  ck_assert_int_eq(s21_sprintf(str1, "%n%*p", &x, 7, &ptr1),
                   sprintf(str2, "%n%*p", &x, 7, &ptr1));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test61) {
#line 2083
  char str1[80];
  char str2[80];
  ck_assert_int_eq(s21_sprintf(str1, "%*.*f", 7, 6, 2.55),
                   sprintf(str2, "%*.*f", 7, 6, 2.55));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test62) {
#line 2090
  char str1[80];
  char str2[80];
  ck_assert_int_eq(s21_sprintf(str1, "%#o", 255), sprintf(str2, "%#o", 255));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test63) {
#line 2096
  char str1[80];
  char str2[80];
  ck_assert_int_eq(s21_sprintf(str1, "%e", 125.35),
                   sprintf(str2, "%e", 125.35));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test64) {
#line 2102
  char str1[80];
  char str2[80];
  ck_assert_int_eq(s21_sprintf(str1, "%%"), sprintf(str2, "%%"));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sscanf_test1) {
#line 2108
  int x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("298 7 3", "%d%*d%d", &x1, &x2),
                   s21_sscanf("298 7 3", "%d%*d%d", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test2) {
#line 2115
  unsigned int x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("0x12fA bB09", "%x%x", &x1, &x2),
                   s21_sscanf("0x12fA bB09", "%x%x", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test3) {
#line 2122
  int x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("0xff01 -96 05678", "%i%i", &x1, &x2),
                   s21_sscanf("0xff01 -96 05678", "%i%i", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test4) {
#line 2129
  int x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("0567 +101 ", "%i%i", &x1, &x2),
                   s21_sscanf("0567 +101 ", "%i%i", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test5) {
#line 2136
  unsigned int x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("0567 +101 ", "%o%3o", &x1, &x2),
                   s21_sscanf("0567 +101 ", "%o%3o", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test6) {
#line 2143
  unsigned int x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("3452 -99", "%u%u", &x1, &x2),
                   s21_sscanf("3452 -99", "%u%u", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test7) {
#line 2150
  unsigned int x1, x2, y1, y2;
  ck_assert_uint_eq(sscanf("3452 -99", "%u%u", &x1, &x2),
                    s21_sscanf("3452 -99", "%u%u", &y1, &y2));
  ck_assert_uint_eq(x1, y1);
  ck_assert_uint_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test8) {
#line 2157
  int x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("3452-99", "%i%n", &x1, &x2),
                   s21_sscanf("3452-99", "%i%n", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test9) {
#line 2164
  char x1[10] = "\0", x2[10] = "\0", y1[10] = "\0", y2[10] = "\0";
  ck_assert_int_eq(sscanf("hi fry slow", "%9sfry%9s", x1, x2),
                   s21_sscanf("hi fry slow", "%9sfry%9s", y1, y2));
  ck_assert_str_eq(x1, y1);
  ck_assert_str_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test10) {
#line 2171
  int x1, y1;
  ck_assert_int_eq(sscanf("12%", "%d%%", &x1), s21_sscanf("12%", "%d%%", &y1));
  ck_assert_int_eq(x1, y1);
}
END_TEST

START_TEST(s21_sscanf_test11) {
#line 2176
  int x1 = 0, y1 = 0;
  ck_assert_int_eq(sscanf("-11-  %", "%d%%", &x1),
                   s21_sscanf("-11-  %", "%d%%", &y1));
  ck_assert_int_eq(x1, y1);
}
END_TEST

START_TEST(s21_sscanf_test12) {
#line 2182
  int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
  ck_assert_int_eq(sscanf("-11  % 4", "%d%%%d", &x1, &x2),
                   s21_sscanf("-11  % 4", "%d%%%d", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test13) {
#line 2189
  unsigned int x1, x2, y1, y2;
  ck_assert_int_eq(
      sscanf("0x12fAaaaaaaaaaaaaaaaaaa bB09", "%x%x", &x1, &x2),
      s21_sscanf("0x12fAaaaaaaaaaaaaaaaaaa bB09", "%x%x", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test14) {
#line 2196
  unsigned short int x1, y1;
  ck_assert_int_eq(sscanf("12", "%hu", &x1), s21_sscanf("12", "%hu", &y1));
  ck_assert_int_eq(x1, y1);
}
END_TEST

START_TEST(s21_sscanf_test16) {
#line 2201
  char x1[20] = {0}, x2[20] = {0}, y1[20] = {0}, y2[20] = {0};
  ck_assert_int_eq(sscanf("  ya", "%9s   %9s", x1, x2),
                   s21_sscanf("  ya", "%9s   %9s", y1, y2));
  ck_assert_str_eq(x1, y1);
  ck_assert_str_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test17) {
#line 2208
  long x1, y1;
  short x2, y2;
  ck_assert_int_eq(sscanf("12 45", "%ld%hd", &x1, &x2),
                   s21_sscanf("12 45", "%ld%hd", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test18) {
#line 2216
  char x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("0 a", "%c%c", &x1, &x2),
                   s21_sscanf("0 a", "%c%c", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test19) {
#line 2223
  long unsigned int x1, y1;
  unsigned int x2, y2;
  ck_assert_uint_eq(sscanf("3452 -99", "%lu%u", &x1, &x2),
                    s21_sscanf("3452 -99", "%lu%u", &y1, &y2));
  ck_assert_uint_eq(x1, y1);
  ck_assert_uint_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test20) {
#line 2231
  int x1 = 0, y1 = 0;
  ck_assert_int_eq(sscanf("  g  ", "%i", &x1), s21_sscanf("  g  ", "%i", &y1));
  ck_assert_int_eq(x1, y1);
}
END_TEST

START_TEST(s21_sscanf_test21) {
#line 2236
  unsigned int x1 = 0, y1 = 0;
  ck_assert_int_eq(sscanf("  g  ", "%u", &x1), s21_sscanf("  g  ", "%u", &y1));
  ck_assert_int_eq(x1, y1);
}
END_TEST

START_TEST(s21_sscanf_test22) {
#line 2241
  int x1 = 0, y1 = 0;
  ck_assert_int_eq(sscanf("V123", "%d", &x1), s21_sscanf("V123", "%d", &y1));
  ck_assert_int_eq(x1, y1);
}
END_TEST

START_TEST(s21_sscanf_test23) {
#line 2246
  wchar_t x1[10], y1[10];
  ck_assert_int_eq(sscanf("qwerty 12345", "%1ls", x1),
                   s21_sscanf("qwerty 12345", "%1ls", y1));
  ck_assert_int_eq(*x1, *y1);
}
END_TEST

START_TEST(s21_sscanf_test24) {
#line 2252
  wchar_t x1, y1;
  char x2, y2;
  ck_assert_int_eq(sscanf("ass", "%lc%c", &x1, &x2),
                   s21_sscanf("ass", "%lc%c", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test25) {
#line 2260
  int x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("123456 654321", "  %00004d  %6d", &x1, &x2),
                   s21_sscanf("123456 654321", "  %00004d  %6d", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}
END_TEST

START_TEST(s21_sscanf_test26) {
#line 2267
  long double x1, y1;
  float x2, y2;
  ck_assert_int_eq(sscanf("0.9045010    0.023", "%Le%4f", &x1, &x2),
                   s21_sscanf("0.9045010    0.023", "%Le%4f", &y1, &y2));
  ck_assert_int_eq((x1 - y1) * 1e15, 0);
  ck_assert_int_eq((x2 - y2) * 1e15, 0);
}
END_TEST

START_TEST(s21_sscanf_test27) {
#line 2275
  float x1, y1, x2, y2;
  ck_assert_int_eq(sscanf("2.17e2 0.4e-3", "%G %g", &x1, &x2),
                   s21_sscanf("2.17e2 0.4e-3", "%G %g", &y1, &y2));
  ck_assert_int_eq((x1 - y1) * 1e15, 0);
  ck_assert_int_eq((x2 - y2) * 1e15, 0);
}
END_TEST

START_TEST(s21_sscanf_test28) {
#line 2282
  float x1, y1, x2, y2;
  ck_assert_int_eq(sscanf("2.17e2 0.4e+3", "%E%f", &x1, &x2),
                   s21_sscanf("2.17e2 0.4e+3", "%E%f", &y1, &y2));
  ck_assert_int_eq((x1 - y1) * 1e15, 0);
  ck_assert_int_eq((x2 - y2) * 1e15, 0);
}
END_TEST

START_TEST(s21_sscanf_test29) {
#line 2289
  char x1[30] = {0}, y1[30] = {0};
  float x2, y2;
  unsigned int x3 = 0, y3 = 0;
  ck_assert_int_eq(
      sscanf("qwerty -12.0345007", "%6s%f    %o", x1, &x2, &x3),
      s21_sscanf("qwerty -12.0345007", "%6s%f    %o", y1, &y2, &y3));
  ck_assert_str_eq(x1, y1);
  ck_assert_int_eq((x2 - y2) * 1e15, 0);
  ck_assert_int_eq(x3, y3);
}
END_TEST

START_TEST(s21_sscanf_test30) {
#line 2299
  char x1[30] = {0}, y1[30] = {0};
  float x2, y2;
  unsigned int x3 = 0, y3 = 0;
  ck_assert_int_eq(sscanf("qwerty -12.0345007", "%9s%f%2o", x1, &x2, &x3),
                   s21_sscanf("qwerty -12.0345007", "%9s%f%2o", y1, &y2, &y3));
  ck_assert_str_eq(x1, y1);
  ck_assert_int_eq((x2 - y2) * 1e15, 0);
  ck_assert_int_eq(x3, y3);
}
END_TEST

START_TEST(s21_sscanf_test31) {
#line 2309
  unsigned int x1, y1;
  char s1[30], s2[30];
  ck_assert_int_eq(sscanf("0xE00A4DOG", "%6x%*d%3s", &x1, s1),
                   s21_sscanf("0xE00A4DOG", "%6x%*d%3s", &y1, s2));
  ck_assert_int_eq(x1, y1);
  ck_assert_str_eq(s1, s2);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_memchr_test1);
  tcase_add_test(tc1_1, s21_memchr_test2);
  tcase_add_test(tc1_1, s21_memchr_test3);
  tcase_add_test(tc1_1, s21_memchr_test4);
  tcase_add_test(tc1_1, s21_memchr_test5);
  tcase_add_test(tc1_1, s21_memchr_test6);
  tcase_add_test(tc1_1, s21_memchr_test7);
  tcase_add_test(tc1_1, s21_memchr_test8);
  tcase_add_test(tc1_1, s21_memchr_test9);
  tcase_add_test(tc1_1, s21_memchr_test10);
  tcase_add_test(tc1_1, s21_memchr_test11);
  tcase_add_test(tc1_1, s21_memchr_test12);
  tcase_add_test(tc1_1, s21_memcmp_test1);
  tcase_add_test(tc1_1, s21_memcmp_test2);
  tcase_add_test(tc1_1, s21_memcmp_test3);
  tcase_add_test(tc1_1, s21_memcmp_test4);
  tcase_add_test(tc1_1, s21_memcmp_test5);
  tcase_add_test(tc1_1, s21_memcmp_test6);
  tcase_add_test(tc1_1, s21_memcmp_test7);
  tcase_add_test(tc1_1, s21_memcmp_test8);
  tcase_add_test(tc1_1, s21_memcmp_test9);
  tcase_add_test(tc1_1, s21_memcmp_test10);
  tcase_add_test(tc1_1, s21_memcmp_test11);
  tcase_add_test(tc1_1, s21_memset_test1);
  tcase_add_test(tc1_1, s21_memset_test2);
  tcase_add_test(tc1_1, s21_memset_test3);
  tcase_add_test(tc1_1, s21_memset_test4);
  tcase_add_test(tc1_1, s21_memset_test5);
  tcase_add_test(tc1_1, s21_memset_test6);
  tcase_add_test(tc1_1, s21_memset_test7);
  tcase_add_test(tc1_1, s21_memset_test8);
  tcase_add_test(tc1_1, s21_memset_test9);
  tcase_add_test(tc1_1, s21_memset_test10);
  tcase_add_test(tc1_1, s21_memset_test11);
  tcase_add_test(tc1_1, s21_memset_test12);
  tcase_add_test(tc1_1, s21_memset_test13);
  tcase_add_test(tc1_1, s21_memcpy_test1);
  tcase_add_test(tc1_1, s21_memcpy_test2);
  tcase_add_test(tc1_1, s21_memcpy_test3);
  tcase_add_test(tc1_1, s21_memcpy_test4);
  tcase_add_test(tc1_1, s21_memcpy_test5);
  tcase_add_test(tc1_1, s21_memcpy_test6);
  tcase_add_test(tc1_1, s21_memcpy_test7);
  tcase_add_test(tc1_1, s21_memcpy_test8);
  tcase_add_test(tc1_1, s21_memcpy_test9);
  tcase_add_test(tc1_1, s21_memcpy_test10);
  tcase_add_test(tc1_1, s21_memcpy_test11);
  tcase_add_test(tc1_1, s21_memcpy_test12);
  tcase_add_test(tc1_1, s21_memmove_test1);
  tcase_add_test(tc1_1, s21_memmove_test2);
  tcase_add_test(tc1_1, s21_memmove_test3);
  tcase_add_test(tc1_1, s21_memmove_test4);
  tcase_add_test(tc1_1, s21_memmove_test5);
  tcase_add_test(tc1_1, s21_memmove_test6);
  tcase_add_test(tc1_1, s21_memmove_test7);
  tcase_add_test(tc1_1, s21_memmove_test8);
  tcase_add_test(tc1_1, s21_memmove_test9);
  tcase_add_test(tc1_1, s21_memmove_test10);
  tcase_add_test(tc1_1, s21_memmove_test11);
  tcase_add_test(tc1_1, s21_memmove_test12);
  tcase_add_test(tc1_1, s21_memmove_test13);
  tcase_add_test(tc1_1, s21_memmove_test14);
  tcase_add_test(tc1_1, s21_memmove_test15);
  tcase_add_test(tc1_1, s21_strlen_test1);
  tcase_add_test(tc1_1, s21_strlen_test2);
  tcase_add_test(tc1_1, s21_strlen_test3);
  tcase_add_test(tc1_1, s21_strlen_test4);
  tcase_add_test(tc1_1, s21_strlen_test5);
  tcase_add_test(tc1_1, s21_strlen_test6);
  tcase_add_test(tc1_1, s21_strlen_test7);
  tcase_add_test(tc1_1, s21_strlen_test8);
  tcase_add_test(tc1_1, s21_strcmp_test1);
  tcase_add_test(tc1_1, s21_strcmp_test2);
  tcase_add_test(tc1_1, s21_strcmp_test3);
  tcase_add_test(tc1_1, s21_strcmp_test4);
  tcase_add_test(tc1_1, s21_strcmp_test5);
  tcase_add_test(tc1_1, s21_strcmp_test6);
  tcase_add_test(tc1_1, s21_strcmp_test7);
  tcase_add_test(tc1_1, s21_strcmp_test8);
  tcase_add_test(tc1_1, s21_strcmp_test9);
  tcase_add_test(tc1_1, s21_strcmp_test10);
  tcase_add_test(tc1_1, s21_strcmp_test11);
  tcase_add_test(tc1_1, s21_strcmp_test12);
  tcase_add_test(tc1_1, s21_strncmp_test1);
  tcase_add_test(tc1_1, s21_strncmp_test2);
  tcase_add_test(tc1_1, s21_strncmp_test3);
  tcase_add_test(tc1_1, s21_strncmp_test4);
  tcase_add_test(tc1_1, s21_strncmp_test5);
  tcase_add_test(tc1_1, s21_strncmp_test6);
  tcase_add_test(tc1_1, s21_strncmp_test7);
  tcase_add_test(tc1_1, s21_strncmp_test8);
  tcase_add_test(tc1_1, s21_strncmp_test9);
  tcase_add_test(tc1_1, s21_strncmp_test10);
  tcase_add_test(tc1_1, s21_strncmp_test11);
  tcase_add_test(tc1_1, s21_strncmp_test12);
  tcase_add_test(tc1_1, s21_strncmp_test13);
  tcase_add_test(tc1_1, s21_strncmp_test14);
  tcase_add_test(tc1_1, s21_strcpy_test1);
  tcase_add_test(tc1_1, s21_strcpy_test2);
  tcase_add_test(tc1_1, s21_strcpy_test3);
  tcase_add_test(tc1_1, s21_strcpy_test4);
  tcase_add_test(tc1_1, s21_strcpy_test5);
  tcase_add_test(tc1_1, s21_strcpy_test6);
  tcase_add_test(tc1_1, s21_strcpy_test7);
  tcase_add_test(tc1_1, s21_strcpy_test8);
  tcase_add_test(tc1_1, s21_strcpy_test9);
  tcase_add_test(tc1_1, s21_strcpy_test10);
  tcase_add_test(tc1_1, s21_strcpy_test11);
  tcase_add_test(tc1_1, s21_strcpy_test12);
  tcase_add_test(tc1_1, s21_strcpy_test13);
  tcase_add_test(tc1_1, strncpy_test1);
  tcase_add_test(tc1_1, strncpy_test2);
  tcase_add_test(tc1_1, strncpy_test3);
  tcase_add_test(tc1_1, strncpy_test4);
  tcase_add_test(tc1_1, strncpy_test5);
  tcase_add_test(tc1_1, strncpy_test6);
  tcase_add_test(tc1_1, strncpy_test7);
  tcase_add_test(tc1_1, strncpy_test8);
  tcase_add_test(tc1_1, strncpy_test9);
  tcase_add_test(tc1_1, strncpy_test10);
  tcase_add_test(tc1_1, strncpy_test11);
  tcase_add_test(tc1_1, s21_strcat_test1);
  tcase_add_test(tc1_1, s21_strcat_test2);
  tcase_add_test(tc1_1, s21_strcat_test3);
  tcase_add_test(tc1_1, s21_strcat_test4);
  tcase_add_test(tc1_1, s21_strcat_test5);
  tcase_add_test(tc1_1, s21_strcat_test6);
  tcase_add_test(tc1_1, s21_strcat_test7);
  tcase_add_test(tc1_1, s21_strncat_test1);
  tcase_add_test(tc1_1, s21_strncat_test2);
  tcase_add_test(tc1_1, s21_strncat_test3);
  tcase_add_test(tc1_1, s21_strncat_test4);
  tcase_add_test(tc1_1, s21_strncat_test5);
  tcase_add_test(tc1_1, s21_strncat_test6);
  tcase_add_test(tc1_1, s21_strncat_test7);
  tcase_add_test(tc1_1, s21_strncat_test8);
  tcase_add_test(tc1_1, s21_strncat_test9);
  tcase_add_test(tc1_1, s21_strncat_test10);
  tcase_add_test(tc1_1, s21_strspn_test1);
  tcase_add_test(tc1_1, s21_strspn_test2);
  tcase_add_test(tc1_1, s21_strspn_test3);
  tcase_add_test(tc1_1, s21_strspn_test4);
  tcase_add_test(tc1_1, s21_strspn_test5);
  tcase_add_test(tc1_1, s21_strspn_test6);
  tcase_add_test(tc1_1, s21_strspn_test7);
  tcase_add_test(tc1_1, s21_strspn_test8);
  tcase_add_test(tc1_1, s21_strspn_test9);
  tcase_add_test(tc1_1, s21_strspn_test10);
  tcase_add_test(tc1_1, s21_strspn_test11);
  tcase_add_test(tc1_1, s21_strspn_test12);
  tcase_add_test(tc1_1, s21_strspn_test13);
  tcase_add_test(tc1_1, s21_strspn_test14);
  tcase_add_test(tc1_1, s21_strspn_test15);
  tcase_add_test(tc1_1, s21_strspn_test16);
  tcase_add_test(tc1_1, s21_strspn_test17);
  tcase_add_test(tc1_1, s21_strspn_test18);
  tcase_add_test(tc1_1, s21_strcspn_test1);
  tcase_add_test(tc1_1, s21_strcspn_test2);
  tcase_add_test(tc1_1, s21_strcspn_test3);
  tcase_add_test(tc1_1, s21_strcspn_test4);
  tcase_add_test(tc1_1, s21_strcspn_test5);
  tcase_add_test(tc1_1, s21_strcspn_test6);
  tcase_add_test(tc1_1, s21_strcspn_test7);
  tcase_add_test(tc1_1, s21_strcspn_test8);
  tcase_add_test(tc1_1, s21_strcspn_test9);
  tcase_add_test(tc1_1, s21_strcspn_test10);
  tcase_add_test(tc1_1, s21_strcspn_test11);
  tcase_add_test(tc1_1, s21_strcspn_test12);
  tcase_add_test(tc1_1, s21_strcspn_test13);
  tcase_add_test(tc1_1, s21_strcspn_test14);
  tcase_add_test(tc1_1, s21_strtok_test1);
  tcase_add_test(tc1_1, s21_strtok_test2);
  tcase_add_test(tc1_1, s21_strtok_test3);
  tcase_add_test(tc1_1, s21_strtok_test4);
  tcase_add_test(tc1_1, s21_strtok_test5);
  tcase_add_test(tc1_1, s21_strtok_test6);
  tcase_add_test(tc1_1, s21_strtok_test7);
  tcase_add_test(tc1_1, s21_strtok_test8);
  tcase_add_test(tc1_1, s21_strchr_test1);
  tcase_add_test(tc1_1, s21_strchr_test2);
  tcase_add_test(tc1_1, s21_strchr_test3);
  tcase_add_test(tc1_1, s21_strchr_test4);
  tcase_add_test(tc1_1, s21_strchr_test5);
  tcase_add_test(tc1_1, s21_strchr_test6);
  tcase_add_test(tc1_1, s21_strchr_test7);
  tcase_add_test(tc1_1, s21_strchr_test8);
  tcase_add_test(tc1_1, s21_strchr_test9);
  tcase_add_test(tc1_1, s21_strchr_test10);
  tcase_add_test(tc1_1, s21_strchr_test11);
  tcase_add_test(tc1_1, s21_strrchr_test1);
  tcase_add_test(tc1_1, s21_strrchr_test2);
  tcase_add_test(tc1_1, s21_strrchr_test3);
  tcase_add_test(tc1_1, s21_strrchr_test4);
  tcase_add_test(tc1_1, s21_strrchr_test5);
  tcase_add_test(tc1_1, s21_strrchr_test6);
  tcase_add_test(tc1_1, s21_strrchr_test7);
  tcase_add_test(tc1_1, s21_strrchr_test8);
  tcase_add_test(tc1_1, s21_strrchr_test9);
  tcase_add_test(tc1_1, s21_strrchr_test10);
  tcase_add_test(tc1_1, s21_strrchr_test11);
  tcase_add_test(tc1_1, s21_strrchr_test12);
  tcase_add_test(tc1_1, s21_strchr_test13);
  tcase_add_test(tc1_1, s21_strchr_test14);
  tcase_add_test(tc1_1, s21_strpbrk_test1);
  tcase_add_test(tc1_1, s21_strpbrk_test2);
  tcase_add_test(tc1_1, s21_strpbrk_test3);
  tcase_add_test(tc1_1, s21_strpbrk_test4);
  tcase_add_test(tc1_1, s21_strpbrk_test5);
  tcase_add_test(tc1_1, s21_strpbrk_test6);
  tcase_add_test(tc1_1, s21_strpbrk_test7);
  tcase_add_test(tc1_1, s21_strpbrk_test8);
  tcase_add_test(tc1_1, s21_strpbrk_test9);
  tcase_add_test(tc1_1, s21_strpbrk_test10);
  tcase_add_test(tc1_1, s21_strpbrk_test11);
  tcase_add_test(tc1_1, s21_strpbrk_test12);
  tcase_add_test(tc1_1, s21_strpbrk_test13);
  tcase_add_test(tc1_1, s21_strpbrk_test14);
  tcase_add_test(tc1_1, s21_strstr_test1);
  tcase_add_test(tc1_1, s21_strstr_test2);
  tcase_add_test(tc1_1, s21_strstr_test3);
  tcase_add_test(tc1_1, s21_strstr_test4);
  tcase_add_test(tc1_1, s21_strstr_test5);
  tcase_add_test(tc1_1, s21_strstr_test6);
  tcase_add_test(tc1_1, s21_strstr_test7);
  tcase_add_test(tc1_1, s21_strstr_test8);
  tcase_add_test(tc1_1, s21_strstr_test9);
  tcase_add_test(tc1_1, s21_strstr_test10);
  tcase_add_test(tc1_1, s21_strstr_test11);
  tcase_add_test(tc1_1, s21_strstr_test12);
  tcase_add_test(tc1_1, s21_strstr_test13);
  tcase_add_test(tc1_1, s21_strstr_test14);
  tcase_add_test(tc1_1, s21_strstr_test15);
  tcase_add_test(tc1_1, s21_strerror_test1);
  tcase_add_test(tc1_1, s21_strerror_test2);
  tcase_add_test(tc1_1, s21_strerror_test3);
  tcase_add_test(tc1_1, s21_strerror_test4);
  tcase_add_test(tc1_1, s21_strerror_test5);
  tcase_add_test(tc1_1, s21_strerror_test6);
  tcase_add_test(tc1_1, s21_strerror_test7);
  tcase_add_test(tc1_1, s21_to_upper_test1);
  tcase_add_test(tc1_1, s21_to_upper_test2);
  tcase_add_test(tc1_1, s21_to_upper_test3);
  tcase_add_test(tc1_1, s21_to_upper_test4);
  tcase_add_test(tc1_1, s21_to_upper_test5);
  tcase_add_test(tc1_1, s21_to_upper_test6);
  tcase_add_test(tc1_1, s21_to_upper_test7);
  tcase_add_test(tc1_1, s21_to_upper_test8);
  tcase_add_test(tc1_1, s21_to_upper_test9);
  tcase_add_test(tc1_1, s21_to_upper_test10);
  tcase_add_test(tc1_1, s21_to_lower_test1);
  tcase_add_test(tc1_1, s21_to_lower_test2);
  tcase_add_test(tc1_1, s21_to_lower_test3);
  tcase_add_test(tc1_1, s21_to_lower_test4);
  tcase_add_test(tc1_1, s21_to_lower_test5);
  tcase_add_test(tc1_1, s21_to_lower_test6);
  tcase_add_test(tc1_1, s21_to_lower_test7);
  tcase_add_test(tc1_1, s21_to_lower_test8);
  tcase_add_test(tc1_1, s21_to_lower_test9);
  tcase_add_test(tc1_1, s21_to_lower_test10);
  tcase_add_test(tc1_1, s21_insert_test1);
  tcase_add_test(tc1_1, s21_insert_test2);
  tcase_add_test(tc1_1, s21_insert_test3);
  tcase_add_test(tc1_1, s21_insert_test4);
  tcase_add_test(tc1_1, s21_insert_test5);
  tcase_add_test(tc1_1, s21_insert_test6);
  tcase_add_test(tc1_1, s21_insert_test7);
  tcase_add_test(tc1_1, s21_insert_test8);
  tcase_add_test(tc1_1, s21_insert_test9);
  tcase_add_test(tc1_1, s21_insert_test10);
  tcase_add_test(tc1_1, s21_insert_test11);
  tcase_add_test(tc1_1, s21_insert_test12);
  tcase_add_test(tc1_1, s21_insert_test13);
  tcase_add_test(tc1_1, s21_trim_test1);
  tcase_add_test(tc1_1, s21_trim_test2);
  tcase_add_test(tc1_1, s21_trim_test3);
  tcase_add_test(tc1_1, s21_trim_test4);
  tcase_add_test(tc1_1, s21_trim_test5);
  tcase_add_test(tc1_1, s21_trim_test6);
  tcase_add_test(tc1_1, s21_trim_test7);
  tcase_add_test(tc1_1, s21_trim_test8);
  tcase_add_test(tc1_1, s21_trim_test9);
  tcase_add_test(tc1_1, s21_trim_test10);
  tcase_add_test(tc1_1, s21_trim_test11);
  tcase_add_test(tc1_1, s21_trim_test12);
  tcase_add_test(tc1_1, s21_trim_test13);
  tcase_add_test(tc1_1, s21_trim_test14);
  tcase_add_test(tc1_1, s21_trim_test15);
  tcase_add_test(tc1_1, s21_trim_test16);
  tcase_add_test(tc1_1, s21_sprintf_test1);
  tcase_add_test(tc1_1, s21_sprintf_test2);
  tcase_add_test(tc1_1, s21_sprintf_test3);
  tcase_add_test(tc1_1, s21_sprintf_test4);
  tcase_add_test(tc1_1, s21_sprintf_test5);
  tcase_add_test(tc1_1, s21_sprintf_test6);
  tcase_add_test(tc1_1, s21_sprintf_test7);
  tcase_add_test(tc1_1, s21_sprintf_test8);
  tcase_add_test(tc1_1, s21_sprintf_test9);
  tcase_add_test(tc1_1, s21_sprintf_test10);
  tcase_add_test(tc1_1, s21_sprintf_test11);
  tcase_add_test(tc1_1, s21_sprintf_test12);
  tcase_add_test(tc1_1, s21_sprintf_test13);
  tcase_add_test(tc1_1, s21_sprintf_test14);
  tcase_add_test(tc1_1, s21_sprintf_test15);
  tcase_add_test(tc1_1, s21_sprintf_test16);
  tcase_add_test(tc1_1, s21_sprintf_test17);
  tcase_add_test(tc1_1, s21_sprintf_test18);
  tcase_add_test(tc1_1, s21_sprintf_test19);
  tcase_add_test(tc1_1, s21_sprintf_test20);
  tcase_add_test(tc1_1, s21_sprintf_test21);
  tcase_add_test(tc1_1, s21_sprintf_test22);
  tcase_add_test(tc1_1, s21_sprintf_test23);
  tcase_add_test(tc1_1, s21_sprintf_test24);
  tcase_add_test(tc1_1, s21_sprintf_test25);
  tcase_add_test(tc1_1, s21_sprintf_test26);
  tcase_add_test(tc1_1, s21_sprintf_test27);
  tcase_add_test(tc1_1, s21_sprintf_test28);
  tcase_add_test(tc1_1, s21_sprintf_test29);
  tcase_add_test(tc1_1, s21_sprintf_test30);
  tcase_add_test(tc1_1, s21_sprintf_test31);
  tcase_add_test(tc1_1, s21_sprintf_test32);
  tcase_add_test(tc1_1, s21_sprintf_test33);
  tcase_add_test(tc1_1, s21_sprintf_test34);
  tcase_add_test(tc1_1, s21_sprintf_test35);
  tcase_add_test(tc1_1, s21_sprintf_test36);
  tcase_add_test(tc1_1, s21_sprintf_test37);
  tcase_add_test(tc1_1, s21_sprintf_test38);
  tcase_add_test(tc1_1, s21_sprintf_test39);
  tcase_add_test(tc1_1, s21_sprintf_test40);
  tcase_add_test(tc1_1, s21_sprintf_test41);
  tcase_add_test(tc1_1, s21_sprintf_test42);
  tcase_add_test(tc1_1, s21_sprintf_test43);
  tcase_add_test(tc1_1, s21_sprintf_test44);
  tcase_add_test(tc1_1, s21_sprintf_test45);
  tcase_add_test(tc1_1, s21_sprintf_test46);
  tcase_add_test(tc1_1, s21_sprintf_test47);
  tcase_add_test(tc1_1, s21_sprintf_test48);
  tcase_add_test(tc1_1, s21_sprintf_test49);
  tcase_add_test(tc1_1, s21_sprintf_test50);
  tcase_add_test(tc1_1, s21_sprintf_test51);
  tcase_add_test(tc1_1, s21_sprintf_test52);
  tcase_add_test(tc1_1, s21_sprintf_test53);
  tcase_add_test(tc1_1, s21_sprintf_test54);
  tcase_add_test(tc1_1, s21_sprintf_test55);
  tcase_add_test(tc1_1, s21_sprintf_test56);
  tcase_add_test(tc1_1, s21_sprintf_test57);
  tcase_add_test(tc1_1, s21_sprintf_test58);
  tcase_add_test(tc1_1, s21_sprintf_test59);
  tcase_add_test(tc1_1, s21_sprintf_test60);
  tcase_add_test(tc1_1, s21_sprintf_test61);
  tcase_add_test(tc1_1, s21_sprintf_test62);
  tcase_add_test(tc1_1, s21_sprintf_test63);
  tcase_add_test(tc1_1, s21_sprintf_test64);
  tcase_add_test(tc1_1, s21_sscanf_test1);
  tcase_add_test(tc1_1, s21_sscanf_test2);
  tcase_add_test(tc1_1, s21_sscanf_test3);
  tcase_add_test(tc1_1, s21_sscanf_test4);
  tcase_add_test(tc1_1, s21_sscanf_test5);
  tcase_add_test(tc1_1, s21_sscanf_test6);
  tcase_add_test(tc1_1, s21_sscanf_test7);
  tcase_add_test(tc1_1, s21_sscanf_test8);
  tcase_add_test(tc1_1, s21_sscanf_test9);
  tcase_add_test(tc1_1, s21_sscanf_test10);
  tcase_add_test(tc1_1, s21_sscanf_test11);
  tcase_add_test(tc1_1, s21_sscanf_test12);
  tcase_add_test(tc1_1, s21_sscanf_test13);
  tcase_add_test(tc1_1, s21_sscanf_test14);
  tcase_add_test(tc1_1, s21_sscanf_test16);
  tcase_add_test(tc1_1, s21_sscanf_test17);
  tcase_add_test(tc1_1, s21_sscanf_test18);
  tcase_add_test(tc1_1, s21_sscanf_test19);
  tcase_add_test(tc1_1, s21_sscanf_test20);
  tcase_add_test(tc1_1, s21_sscanf_test21);
  tcase_add_test(tc1_1, s21_sscanf_test22);
  tcase_add_test(tc1_1, s21_sscanf_test23);
  tcase_add_test(tc1_1, s21_sscanf_test24);
  tcase_add_test(tc1_1, s21_sscanf_test25);
  tcase_add_test(tc1_1, s21_sscanf_test26);
  tcase_add_test(tc1_1, s21_sscanf_test27);
  tcase_add_test(tc1_1, s21_sscanf_test28);
  tcase_add_test(tc1_1, s21_sscanf_test29);
  tcase_add_test(tc1_1, s21_sscanf_test30);
  tcase_add_test(tc1_1, s21_sscanf_test31);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
