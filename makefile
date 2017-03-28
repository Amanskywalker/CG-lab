CC=g++
CFLAGS= -lglut -lGLU -lGL
RM=rm -rf
OUT=app

all: build

build: lp1.o
	$(RM) *.o

debug: CFLAGS+=-DDEBUG_ON
debug: build

lp1.o: lp1.cpp
	$(CC) lp1.cpp $(CFLAGS) -o lp1

clean:
	$(RM) *.o $(OUT)
