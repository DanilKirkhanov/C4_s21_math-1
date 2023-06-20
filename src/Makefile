gcc = -Werror -Wall -Wextra -std=c11
OS := $(shell uname)

ifeq ($(OS),Linux)
	FLAGS = -lcheck -lm -lpthread -lrt -lsubunit -fprofile-arcs -ftest-coverage
	OPEN_CMD = xdg-open
else
	FLAGS = -lcheck -lm -lpthread -fprofile-arcs -ftest-coverage
	OPEN = open
endif

all: clean s21_math.a test gcov_report

s21_math.a:
	gcc $(gcc) -c s21*.c
	ar -crs s21_math.a s21*.o

gcov_report: clean
	gcc tests.c s21_*.c $(FLAGS) -o tests
	./tests
	lcov -t "./tests" -o report.info --no-external -c -d .
	genhtml -o report report.info
	$(OPEN) ./report/index.html

	rm -rf *.gcno *.gcda *.gco

test: clean s21_math.a
	gcc tests.c s21_math.a $(gcc) $(FLAGS) -o tests
	./tests

rebuild:
	rm -rf *.o *.a tests
	rm -rf *.gcno *gcda *.gcov gcov
	rm -rf report report.info
	gcc $(CC) -c s21_math.c
	ar -crs s21_math.a s21_*.o


clean:
	rm -rf *.o *.a tests
	rm -rf *.gcno *gcda *.gcov gcov
	rm -rf report report.info