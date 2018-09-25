SimpleCalculator : Add.o Subtract.o main.o
	gcc -o SimpleCalculator Add.o Subtract.o main.o

Add.o : Add.c
	gcc -c -o Add.o Add.c

Subtract.o : Subtract.c
	gcc -c -o Subtract.o Subtract.c

main.o : main.c
	gcc -c -o main.o main.c

clean : 
	rm *.o SimpleCalculator

