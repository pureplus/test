
TARGET=test
OBJS=test.o

CC = gcc
CFLAGS += -g -Wall
CFLAGS += -std=gnu99
CFLAGS += -I./includelib
# CFLAGS += -WI, -Bstatic


LD_LIBRARIES = -L/usr/lib -lplcapi
.PHONY: test clean
%.o:%.c 
	@echo  "  GCC	$@"
	$(CC) -c -o $@ $< $(CFLAGS) -I./

${TARGET} : $(OBJS)
	@echo  "  LD	$@"
	$(CC) -o $@  $^   $(CFLAGS) ${LD_LIBRARIES} -ldl

	sudo ./test 0

clean:
	rm -f *.o
