all: bufcat 

bufcat: libbufio.so
	gcc bufcat.c -I../lib -lbufio -L../lib -Wl,-rpath=../lib -o bufcat

libbufio.so:
	make -C ../lib

clean:
	rm -f ./bufcat
