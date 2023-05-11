.PHONE : all clean

all: mxxd

mxxd: 
	gcc -g -c mxxd.c -o mxxd
	clear

clean:
	rm -rf mxxd
	clear