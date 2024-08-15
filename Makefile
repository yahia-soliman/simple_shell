CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=gnu89

#make
all: clean sish

#make sish
sish:
	$(CC) $(CFLAGS) *.c -o sish

#make clean
clean:
	rm -rf sish
