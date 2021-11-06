CC=g++
CFLAGS=-Wall

test1: test1.cpp BitHelper.h
	$(CC) $(CFLAGS) -o test1 test1.cpp

clean:
	rm test1
