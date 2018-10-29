all: main.o work10.o
	gcc -o out main.o work10.o

work10.o: work10.c
	gcc -c work10.c

main.o: main.c work10.h
	gcc -c main.c

run:
	./out

clean:
	rm out
	rm *.o
	rm *.txt
