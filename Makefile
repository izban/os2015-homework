all: 	cat revwords filter

cat: 
	make -C cat

revwords:
	make -C revwords

filter:
	make -C filter

.PHONY: cat revwords filter

clean:
	make -C cat clean
	make -C revwords clean
	make -C lib clean
	make -C filter clean
