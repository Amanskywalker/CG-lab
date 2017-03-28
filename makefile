CC=g++
CFLAGS=
LIBS= -lglut -lGL -lGLU
RM=rm -rf
OUT=app

all: build

build: lp1.o
	$(RM) *.o

debug: CFLAGS+=-DDEBUG_ON
debug: build

lp1.o: lp1.cpp
	$(CC) $(CFLAGS) lp1.cpp $(LIBS) -o lp1

clean:
	$(RM) *.o $(OUT)
