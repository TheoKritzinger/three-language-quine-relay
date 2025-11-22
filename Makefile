CC = gcc

all: quine2.c

quine: quine.o
	$(CC) -o quine quine.o

%.o: %.c
	$(CC) -c -o $@ $<

quine.java: quine
	./quine

quine.class: quine.java
	javac quine.java

quine.py: quine.class
	java quine

quine2.c: quine.py
	python quine.py

.PHONY: clean
clean:
	rm -f *.o quine quine.java quine.class quine.py quine2.c