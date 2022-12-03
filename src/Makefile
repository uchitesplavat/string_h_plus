CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11 #-fsanitize=address -g
VALGRIND=valgrind --leak-check=full --leak-resolution=med -s
OS:= $(shell uname -s)
LINFLAGS=-lcheck -pthread -lrt -lm -lsubunit
#TC_FLAGS += $(shell pkg-config --cflags check) $(shell pkg-config --libs check)

all: clean test gcov_report memory

test: s21_string.a

ifeq ($(OS), Darwin)
	gcc s21_string_tests.c s21_string.a  -o test `pkg-config --cflags --libs check` -lcheck -lpthread #-fsanitize=address
	./test
else
	gcc s21_string_tests.c s21_string.a -o test $(LINFLAGS)
	./test
endif
s21_string.o: s21_string.c s21_string.h
	gcc $(CFLAGS) $(LINFLAGS) -c s21_string.c 
s21_string.a: s21_string.o
	ar r s21_string.a  s21_string.o
	ranlib s21_string.a
gcov_report: 
ifeq ($(OS), Darwin)
	#cd ~/goinfree
	#git clone https://github.com/Homebrew/brew homebrew
	#eval "$(~/goinfree/homebrew/bin/brew shellenv)"
	#~/goinfree/homebrew/bin/brew install lcov
	#brew install lcov
	#~/goinfree/homebrew/bin/brew install gcovr
	#brew install gcovr
    #~/goinfree/homebrew/bin/brew install check
	#brew install check
	gcc --coverage s21_string_tests.c -o s21_string_tests s21_string.c `pkg-config --cflags --libs check`
	./s21_string_tests
	#gcov s21_string.gcda
	lcov -t "s21_string_tests" -o s21_string_tests.info -c -d .   
	genhtml -o report s21_string_tests.info
	open ./report/index.html
else
	gcc --coverage s21_string_tests.c -o s21_string_tests s21_string.c $(LINFLAGS)
	./s21_string_tests
	gcov s21_string.gcda
	lcov -t "s21_string_tests" -o s21_string_tests.info -c -d .  
	genhtml -o report s21_string_tests.info
	xdg-open ./report/index.html
endif

memory: test
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./test
	rm -rf s21_string.o
else
	#sudo dnf install valgrind
	#$(VALGRIND) --leak-check=full --show-leak-kinds=all ./test
	rm -rf s21_string.o
endif


clean:
	-rm -rf *.o && rm -rf *.gcno && rm -rf *.exec
	-rm -rf *.a && rm -rf *.gcda
	-rm -rf *.info && rm -rf *.gcov
	-rm -rf ./test && rm -rf ./gcov_report
	-rm -rf ./report/


