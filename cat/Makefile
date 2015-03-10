all: cat

cat: libhelpers.so
	gcc cat.c -I../lib -lhelpers -L../lib -Wl,-rpath=../lib -o cat

libhelpers.so:
	make -C ../lib

clean:
	rm -f ./cat
