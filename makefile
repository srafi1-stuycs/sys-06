list: list.c
	gcc list.c -o out
run: out
	./out
clean:
	rm out
