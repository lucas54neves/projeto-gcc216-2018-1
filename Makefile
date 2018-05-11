all:	trabalhoEd.o main.o
	g++ -o main trabalhoEd.o main.o

workEd.o:	main.cpp trabalhoEd.h
	g++ -c trabalhoEd.cpp

main.o:	main.cpp trabalhoEd.h
	g++ -c main.cpp

clean:
	rm -rf *.o

iniciar:
	./main
