CC = gcc 
CFLAGS = -Wall -Wextra -std=c11
ifeq ($(MAKECMDGOALS), gcov_report)
	CFLAGS += --coverage
endif
TEST_DIR = tests

CFILES = $(wildcard s21*.c)
TEST_CFILES = $(wildcard $(TEST_DIR)/*.c)
COBJ = $(CFILES:.c=.o)
LIBNAME = s21_matrix.a

.PHONY: all clean test gcov_report

all: rebuild

test: rebuild
	$(CC) $(CFLAGS) $(TEST_CFILES) -L . $(LIBNAME) -o ./$(TEST_DIR)/run_tests -lcheck -lsubunit -g -lm
	./$(TEST_DIR)/run_tests

valgrind: rebuild
	$(CC) $(CFLAGS) $(TEST_CFILES) -L . $(LIBNAME) -o ./$(TEST_DIR)/run_tests -lcheck -lsubunit -g -lm
	valgrind --tool=memcheck --leak-check=yes -s ./$(TEST_DIR)/run_tests

$(LIBNAME): $(COBJ)
	ar rcs $@ $^
	ranlib $@

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -g -lm

gcov_report: rebuild $(LIBNAME)
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage $(TEST_CFILES) -L . $(LIBNAME) -o $(TEST_DIR)/run_tests -lgcov -lcheck -lsubunit -lm
	./$(TEST_DIR)/run_tests
	rm -rf $(TEST_DIR)/*gcda $(TEST_DIR)/*gcno
	lcov -t "s21_test" -o $(TEST_DIR)/s21_test.info -c -d .
	genhtml -o report $(TEST_DIR)/s21_test.info

clean: 
	rm -rf $(COBJ) $(LIBNAME) /$(TEST_DIR)/run_tests $(TEST_DIR)/s21_test.info ./report/
	rm -rf $(TEST_DIR)/run_tests *gcda *gcno */*gcda */*gcno

rebuild: clean $(LIBNAME)