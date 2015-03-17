all: 	cat revwords

cat: 
	make -C cat

revwords:
	make -C revwords

.PHONY: cat revwords

clean:
	make -C cat clean
	make -C revwords clean
	make -C lib clean
