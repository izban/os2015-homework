CFLAGS = -Wall -fpic

all: libhelpers.so

libhelpers.so: helpers.o
	gcc -shared -o libhelpers.so helpers.o

clean:
	rm -f *.o
	rm -f *.so
