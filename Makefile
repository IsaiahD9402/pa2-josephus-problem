COMPILER = g++
FLAGS = -std=c++14
COMPILE = $(COMPILER) $(FLAGS)

out: main.o Destination.o ListMyJosephus.o TestListMyJosephus.o VectorMyJosephus.o TestVectorMyJosephus.o
	$(COMPILE) main.o Destination.o ListMyJosephus.o TestListMyJosephus.o VectorMyJosephus.o TestVectorMyJosephus.o -o mainexe

main.o: main.cpp
	$(COMPILE) -c main.cpp 

Destination.o: Destination.cpp
	$(COMPILE) -c Destination.cpp

ListMyJosephus.o: ListMyJosephus.cpp
	$(COMPILE) -c ListMyJosephus.cpp 

TestListMyJosephus.o: TestListMyJosephus.cpp
	$(COMPILE) -c TestListMyJosephus.cpp 

VectorMyJosephus.o: VectorMyJosephus.cpp
	$(COMPILE) -c VectorMyJosephus.cpp 

TestVectorMyJosephus.o: TestVectorMyJosephus.cpp
	$(COMPILE) -c TestVectorMyJosephus.cpp 

clean:
	rm main.o; rm Destination.o; rm ListMyJosephus.o; rm TestListMyJosephus.o; rm VectorMyJosephus.o; rm TestVectorMyJosephus.o; rm mainexe