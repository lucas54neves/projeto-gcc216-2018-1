all:	workEd.o main.o
	g++ -o main workEd.o main.o

workEd.o:	main.cpp workEd.h
	g++ -c workEd.cpp

main.o:	main.cpp workEd.h
	g++ -c main.cpp

clean:
	rm -rf *.o

iniciar:
	./main