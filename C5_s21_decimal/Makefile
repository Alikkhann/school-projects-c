CC = gcc
CFLAGS = -Wall -Wextra -Werror
CHECKFLAGS = -lcheck -lm -pthread -lsubunit

all: clean s21_decimal.a gcov_report

s21_decimal.a:
	$(CC) $(CFLAGS) -c */*.c $(CHECKFLAGS)
	ar rc s21_decimal.a *.o
	rm *.o

test: clean s21_decimal.a
	$(CC) $(CFLAGS) */test*.c s21_decimal.a $(CHECKFLAGS) -o test
	./test

gcov_report: clean 
	$(CC) $(CFLAGS) */*.c $(CHECKFLAGS) -coverage -o report
	./report
	lcov -o coverage -c -d .
	genhtml -o gcovreport coverage
	rm report-test*.gcno report-test*.gcda
	rm -rf *.gcno *.gcda report coverage

style:
	clang-format -i -style=Google */*.c */*.h *.h

clean:
	rm -rf *.gcno *.gcda coverage report gcovreport *.a *.out test *.o
