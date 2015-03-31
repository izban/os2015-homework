all: 	cat revwords filter bufcat

cat: 
	make -C cat

revwords:
	make -C revwords

filter:
	make -C filter

bufcat:
	make -C bufcat

.PHONY: cat revwords filter bufcat

clean:
	make -C cat clean
	make -C revwords clean
	make -C lib clean
	make -C filter clean
	make -C bufcat clean
