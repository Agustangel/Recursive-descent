
INCLUDES=include
SOURCE=source

calc: main.o calculator.o
	gcc -o calc $^ -llogger -lonegin

main.o: main.c
	gcc -g -O0 -I${INCLUDES}/ -c $^

calculator.o: ${SOURCE}/calculator.c
	gcc -g -O0 -I${INCLUDES}/ -c $^

valgrind: calc
	valgrind --leak-check=yes ./calc

clean:
	rm calc main.o calculator.o
