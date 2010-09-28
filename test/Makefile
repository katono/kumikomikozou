CFLAGS = -Wall -ansi -pedantic-errors -g -DUNITTEST
PROG = unittest_lib
OBJS = main.o
OBJS += test_strtol.o
OBJS += test_sprintf.o
OBJS += ../lib.o

all: $(PROG)

.SUFFIXES: .c .o

.c .o:
	$(CC) $(CFLAGS) -c $<


$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@



.PHONY: clean
clean:
	rm -f *.o $(PROG) ../*.o


../lib.o: ../lib.h

