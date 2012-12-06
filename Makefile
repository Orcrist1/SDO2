CC = gcc 
CFLAGS = --std=c99 --pedantic -Wall -W -Wmissing-prototypes
LIBS = -lSDL
EXEC = maze 

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(EXEC)
	
$(EXEC) : $(OBJ)
	$(CC) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)


zip :
	tar -zcvf ../JulienRAMAKERS.tar.gz ../projet001

clean:
	rm -rf *.o

purge : clean
	rm -rf $(EXEC)

