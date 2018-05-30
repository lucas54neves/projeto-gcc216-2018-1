all: compilar

compilar: main.o metodos.o
	@g++ -o programa main.o metodos.o

main.o: main.cpp metodos.hpp
	@g++ -o main.o main.cpp -c -W -Wall -ansi -pedantic

metodos.o: metodos.cpp metodos.hpp
	@g++ -o metodos.o metodos.cpp -c -W -Wall -ansi -pedantic

limpar:
	@rm -rf *.o *~ programa

limpaTudo:
	@rm -rf *.o *~ programa *.bin *.txt

iniciar:
	@./programa