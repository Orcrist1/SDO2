CC = gcc 
CFLAGS = `sdl-config --cflags` -O3 --std=c99 --pedantic -Wall -W -Wmissing-prototypes
LIBS = `sdl-config --libs` 
EXEC = maze 

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) -o $@ -c $< $(LIBS)


zip :
	tar -zcvf ../JulienRAMAKERS.tar.gz ../projet001

clean:
	rm -rf *.o

purge : clean
	rm -rf $(EXEC)

