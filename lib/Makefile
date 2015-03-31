CFLAGS = -Wall -fpic

all: libhelpers.so libbufio.so

libhelpers.so: helpers.o
	gcc -shared -o libhelpers.so helpers.o

libbufio.so: bufio.o
	gcc -shared -o libbufio.so bufio.o

clean:
	rm -f *.o
	rm -f *.so
