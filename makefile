CFLAGS = -Wall 
LDLIBS = -lm

all: myht

myht: myht.o lib.o
	gcc -o myht myht.o lib.o $(CFLAGS) $(LDLIBS)

myht.o: myht.c 
	gcc -c myht.c $(CFLAGS)

lib.o: lib.h lib.c 
	gcc -c lib.c $(CFLAGS)

clean:
	rm -f *.o *.gch myht

