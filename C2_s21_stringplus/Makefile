CC = gcc
CFLAGS = -Wall -Werror -Wextra
CHECKFLAGS = -lcheck -lm -pthread -lsubunit

all: clean s21_string.a gcov_report

s21_string.a:
	$(CC) $(CFLAGS) -c s21_*.c
	ar rc s21_string.a s21_*.o
	rm s21_*.o

test: clean s21_string.a
	$(CC) $(CFLAGS) test*.c s21_string.a $(CHECKFLAGS) -o test
	./test

gcov_report: clean
	$(CC) $(CFLAGS) s21_*.c test*.c $(CHECKFLAGS) -coverage -o report
	./report
	rm report-test*.gcno report-test*.gcda
	lcov -o coverage -c -d .
	genhtml -o gcovreport coverage
	rm -rf *.gcno *.gcda report coverage

clean:
	rm -rf *.gcno *.gcda coverage report gcovreport *.a *.out test *.o
