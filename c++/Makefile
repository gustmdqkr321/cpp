CC = g++
CCFLAGS = -g


Bitset: Bitset.o Bvector.o Kvector.o
	$(CC) $(CCFLAGS) -o Bitset Bitset.o Bvector.o Kvector.o

Bvector: Bvector.o Kvector.o
	$(CC) $(CCFLAGS) -o Bvector Bvector.o Kvector.o




clean:
	rm -f *.o

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -c $<
