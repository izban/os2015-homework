all: filter 

filter: libhelpers.so
	gcc filter.c -I../lib -lhelpers -L../lib -Wl,-rpath=../lib -o filter

libhelpers.so:
	make -C ../lib

clean:
	rm -f ./filter
