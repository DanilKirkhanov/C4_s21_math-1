gcc = -Werror -Wall -Wextra -std=c11

all: clean s21_math.a test gcov_report

s21_math.a:
	$(gcc) -c s21_*.c
	ar -crs s21_math.a s21__*.o

gcov_report: clean
	gcc test_unit.c s21_*.c $(gcc) -D MAC -o test_unit
	./test_unit
	lcov -t "./test_unit" -o report.info --no-external -c -d .
	genhtml -o report report.info
	open ./report/index.html

	rm -rf *.gcno *.gcda *.gco

test:
	gcc test_unit.c s21_math.a $(gcc) -lgcov -coverage -o test_unit
	./test_unit

rebuild:
	rm -rf *.o *.a test_unit
	rm -rf *.gcno *gcda *.gcov gcov
	rm -rf report report.info
	gcc $(CC) -c s21_math.c
	ar -crs s21_math.a s21_*.o


clean:
	rm -rf *.o *.a test_unit
	rm -rf *.gcno *gcda *.gcov gcov
	rm -rf report report.info