TARGETS=dotprod_mutex dotprod_serial hello hellothread hole1 lscat myCat myLs noHole1 myShell simple-cat simple-ls simple-sh simple-sh1 workbench zachHole1 client conServerThread

CROSS_TOOL =
CC_CPP = $(CROSS_TOOL)g++
CC_C = $(CROSS_TOOL)gcc

CFLAGS = -Wall -g -std=c99 -lpthread -lnsl

all: clean $(TARGETS)

$(TARGETS):
	$(CC_C) $(CFLAGS) $@.c -o $@

clean:
	rm -f $(TARGETS)
