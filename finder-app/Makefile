CC := $(if $(CROSS_COMPILE),$(CROSS_COMPILE)gcc,gcc)
CFLAGS := -Wall -Werror -g

all: writer

writer: writer.o
	$(CC) $(CFLAGS) -o writer writer.o

writer.o: writer.c
	$(CC) $(CFLAGS) -c writer.c

clean:
	rm -f writer *.o

