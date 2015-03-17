all: revwords

revwords: libhelpers.so
	gcc revwords.c -I../lib -lhelpers -L../lib -Wl,-rpath=../lib -o revwords

libhelpers.so:
	make -C ../lib

clean:
	rm -f ./revwords
