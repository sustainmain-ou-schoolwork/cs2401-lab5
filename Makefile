CC = g++
CFLAGS = -g -Wall -std=c++11

a.out: main.cc list1.h
	$(CC) $(CFLAGS) main.cc -o a.out

clean:
	rm -rf *.o a.out
