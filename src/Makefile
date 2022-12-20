FLAGS = -Wall -Wextra -Werror -std=c11 -g
FLAGS_CHECK=$(shell pkg-config --cflags --libs check)
FLAGS_GCOV=-fprofile-arcs -ftest-coverage

all:  test gcov_report

s21_string.a: s21_string.o s21_sprintf.o s21_sscanf.o s21_atoi.o
	ar src s21_string.a s21_string.o s21_sprintf.o s21_sscanf.o s21_atoi.o
	ranlib s21_string.a

test: s21_string.a
	gcc $(CFLAGS) test.c s21_string.a -o test.out $(FLAGS_CHECK)
	./test.out

gcov_report: clean s21_string.a
	gcc $(FLAGS_GCOV) *.c -o report.out $(FLAGS_CHECK)
	./report.out
	gcov -f s21_string.c s21_sprintf.c s21_sscanf.c
	lcov -t "report" -o report.info -c -d .
	genhtml -o ./report report.info
	open ./report/src/index.html
	rm -f *.gcov *.gcda *.gcno *.info report.out 
	
clean:
	rm -rf ./report *.out *.a *.o *.info *.gcov *.gcda *.gcno
	
rebuild:
	make clean
	make all

s21_string.o: s21_string.c
	gcc $(FLAGS)  -c -o s21_string.o s21_string.c
s21_sscanf.o: s21_sscanf.c
	gcc $(FLAGS)  -c -o s21_sscanf.o s21_sscanf.c
s21_sprintf.o: s21_sprintf.c
	gcc $(FLAGS)  -c -o s21_sprintf.o s21_sprintf.c
s21_atoi.o: s21_atoi.c
	gcc $(FLAGS)  -c -o s21_atoi.o s21_atoi.c

check_style:
	clang-format -style=Google -n *.c *.h

correct_style:
	clang-format -style=Google -i *.c *.h

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

cpplint:
	python3 cpplint.py --extensions=c *.c *.h

all_check:
	make check_style
	make cppcheck
	make cpplint
