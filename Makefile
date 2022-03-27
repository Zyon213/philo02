all:
	gcc -pthread -lpthread dining03.c -o din
debug:
	gcc -pthread -lpthread -g -fsanitize=address dining03.c -o din
clean:
	rm -f din
